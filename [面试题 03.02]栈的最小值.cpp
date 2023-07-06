// 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(
// 1)。
//  示例： MinStack minStack = new MinStack(); minStack.push(-2);
//  minStack.push(0);
// minStack.push(-3); minStack.getMin();   --> 返回 -3. minStack.pop();
// minStack.top(
//); --> 返回 0. minStack.getMin(); --> 返回 -2.
//
//  Related Topics 栈 设计 👍 89 👎 0
#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
public:
  stack<int> _stk{};
  stack<int> _descend_stk{};
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    _stk.push(x);
    if (_descend_stk.empty() || x <= _descend_stk.top())
      _descend_stk.push(x);
  }

  void pop() {
    int t = _stk.top();
    _stk.pop();
    if (_descend_stk.top() == t)
      _descend_stk.pop();
  }

  int top() { return _stk.top(); }

  int getMin() { return _descend_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// leetcode submit region end(Prohibit modification and deletion)
