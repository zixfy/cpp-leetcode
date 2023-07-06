// 我们把无限数量 ∞ 的栈排成一行，按从左到右的次序从 0
// 开始编号。每个栈的的最大容量 capacity 都相同。
//
//  实现一个叫「餐盘」的类 DinnerPlates：
//
//
//  DinnerPlates(int capacity) - 给出栈的最大容量 capacity。
//  void push(int val) - 将给出的正整数 val 推入 从左往右第一个 没有满的栈。
//  int pop() - 返回 从右往左第一个
//  非空栈顶部的值，并将其从栈中删除；如果所有的栈都是空的，请返回 -1。 int
//  popAtStack(int index) - 返回编号 index
//  的栈顶部的值，并将其从栈中删除；如果编号 index 的栈是空的，请返回 -
// 1。
//
//
//
//
//  示例：
//
//  输入：
//["DinnerPlates","push","push","push","push","push","popAtStack","push","push",
//"popAtStack","popAtStack","pop","pop","pop","pop","pop"]
//[[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
// 输出：
//[null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]
//
// 解释：
// DinnerPlates D = DinnerPlates(2);  // 初始化，栈最大容量 capacity = 2
// D.push(1);
// D.push(2);
// D.push(3);
// D.push(4);
// D.push(5);         // 栈的现状为：    2  4
//                                     1  3  5
//                                     ﹈ ﹈ ﹈
// D.popAtStack(0);   // 返回 2。栈的现状为：      4
//                                           1  3  5
//                                           ﹈ ﹈ ﹈
// D.push(20);        // 栈的现状为：  20  4
//                                    1  3  5
//                                    ﹈ ﹈ ﹈
// D.push(21);        // 栈的现状为：  20  4 21
//                                    1  3  5
//                                    ﹈ ﹈ ﹈
// D.popAtStack(0);   // 返回 20。栈的现状为：       4 21
//                                             1  3  5
//                                             ﹈ ﹈ ﹈
// D.popAtStack(2);   // 返回 21。栈的现状为：       4
//                                             1  3  5
//                                             ﹈ ﹈ ﹈
// D.pop()            // 返回 5。栈的现状为：        4
//                                             1  3
//                                             ﹈ ﹈
// D.pop()            // 返回 4。栈的现状为：    1  3
//                                            ﹈ ﹈
// D.pop()            // 返回 3。栈的现状为：    1
//                                            ﹈
// D.pop()            // 返回 1。现在没有栈。
// D.pop()            // 返回 -1。仍然没有栈。
//
//
//
//
//  提示：
//
//
//  1 <= capacity <= 20000
//  1 <= val <= 20000
//  0 <= index <= 100000
//  最多会对 push，pop，和 popAtStack 进行 200000 次调用。
//
//
//  Related Topics 栈 设计 哈希表 堆（优先队列） 👍 73 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)

constexpr bool debug = false;
class DinnerPlates {
  friend ostream &operator<<(ostream &, const DinnerPlates &);

private:
  int _cap;
  int _tot = 0;
  vector<stack<int>> _stks{};
  priority_queue<int> _non_empty_idxs{};
  priority_queue<int, vector<int>, greater<>> _non_full_idxs{};

private:
public:
  DinnerPlates(int capacity) : _cap(capacity) {}
  DinnerPlates() = delete;

  void push(int val) {
    if constexpr (debug)
      cout << *this;
    if (++_tot > _cap * _stks.size()) {
      _stks.emplace_back();
      _stks.back().push(val);
      if (_cap > 1)
        _non_full_idxs.push(_stks.size() - 1);
      _non_empty_idxs.push(_stks.size() - 1);
      return;
    }
    while (!_non_full_idxs.empty()) {
      int cur = _non_full_idxs.top();
      if (cur >= _stks.size() || _stks[cur].size() == _cap) {
        _non_full_idxs.pop();
        continue;
      }
      _stks[cur].push(val);
      if (_stks[cur].size() == 1)
        _non_empty_idxs.push(cur);
      if (_stks[cur].size() == _cap)
        _non_full_idxs.pop();
      break;
    }
  }

  int pop() {
    if constexpr (debug)
      cout << *this;
    if (_tot == 0)
      return -1;
    --_tot;
    while (!_non_empty_idxs.empty()) {
      int cur = _non_empty_idxs.top();
      if (cur >= _stks.size() || _stks[cur].size() == 0) {
        _non_empty_idxs.pop();
        continue;
      }
      int r = _stks[cur].top();
      _stks[cur].pop();
      if (_stks[cur].size() == _cap - 1)
        _non_full_idxs.push(cur);
      if (_stks[cur].size() == 0) {
        _non_empty_idxs.pop();
        if (cur == _stks.size() - 1)
          _stks.pop_back();
      }
      return r;
    }
    throw std::runtime_error("really bad bug here");
  }

  int popAtStack(int index) {
    if constexpr (debug)
      cout << *this;
    if (index >= _stks.size() || _stks[index].empty())
      return -1;
    int r = _stks[index].top();
    --_tot;
    _stks[index].pop();
    _non_full_idxs.push(index);

    return r;
  }
};
ostream &operator<<(ostream &o, const DinnerPlates &d) {
  o << "tot: " << d._tot << " sz: [";
  for (const auto &s : d._stks)
    o << s.size() << ", ";
  return o << ']' << '\n';
}
/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// leetcode submit region end(Prohibit modification and deletion)
