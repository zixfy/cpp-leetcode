// 随机产生数字并传递给一个方法。你能否完成这个方法，在每次产生新值时，寻找当前所有值的中间值（中位数）并保存。
//
//  中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
//
//  例如，
//
//  [2,3,4] 的中位数是 3
//
//  [2,3] 的中位数是 (2 + 3) / 2 = 2.5
//
//  设计一个支持以下两种操作的数据结构：
//
//
//  void addNum(int num) - 从数据流中添加一个整数到数据结构中。
//  double findMedian() - 返回目前所有元素的中位数。
//
//
//  示例：
//
//  addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3)
// findMedian() -> 2
//
//
//  Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 33 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>);
template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);

template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
private:
  priority_queue<int, vector<int>, less<>> q1;
  priority_queue<int, vector<int>, greater<>> q2;

public:
  /** initialize your data structure here. */
  MedianFinder() = default;
  void addNum(int num) {
    if (q1.empty()) {
      q1.push(num);
      return;
    }
    auto tmp = q1.top();
    if (tmp > num)
      q1.push(num);
    else
      q2.push(num);
    if (q1.size() > q2.size() + 1)
      q2.push(q1.top()), q1.pop();
    else if (q1.size() < q2.size())
      q1.push(q2.top()), q2.pop();
  }
  double findMedian() {
    if (q1.size() == q2.size())
      return (q1.top() + q2.top()) / 2.;
    return q1.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// leetcode submit region end(Prohibit modification and deletion)
