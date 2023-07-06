// 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于
// FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”
// 。
//
//  循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环
// 队列，我们能使用这些空间去存储新的值。
//
//  你的实现应该支持如下操作：
//
//
//  MyCircularQueue(k): 构造器，设置队列长度为 k 。
//  Front: 从队首获取元素。如果队列为空，返回 -1 。
//  Rear: 获取队尾元素。如果队列为空，返回 -1 。
//  enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
//  deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
//  isEmpty(): 检查循环队列是否为空。
//  isFull(): 检查循环队列是否已满。
//
//
//
//
//  示例：
//
//  MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
// circularQueue.enQueue(1);  // 返回 true
// circularQueue.enQueue(2);  // 返回 true
// circularQueue.enQueue(3);  // 返回 true
// circularQueue.enQueue(4);  // 返回 false，队列已满
// circularQueue.Rear();  // 返回 3
// circularQueue.isFull();  // 返回 true
// circularQueue.deQueue();  // 返回 true
// circularQueue.enQueue(4);  // 返回 true
// circularQueue.Rear();  // 返回 4
//
//
//
//  提示：
//
//
//  所有的值都在 0 至 1000 的范围内；
//  操作数将在 1 至 1000 的范围内；
//  请不要使用内置的队列库。
//
//
//  Related Topics 设计 队列 数组 链表 👍 462 👎 0

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
class MyCircularQueue {
private:
  size_t _sz = 0;
  size_t _max_sz;
  vector<int> q;
  size_t _front, _tail;

public:
  MyCircularQueue(int k) : _max_sz(k) {
    q.resize(k);
    _tail = _max_sz - 1;
    _front = 0;
  }

  bool enQueue(int value) {
    if (isFull())
      return false;
    _tail++, _sz++;
    if (_tail == _max_sz)
      _tail = 0;
    q[_tail] = value;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    _front ++, _sz--;
    if (_front == _max_sz)
      _front = 0;
    return true;
  }

  int Front() { return isEmpty() ? -1 : q[_front]; }

  int Rear() { return isEmpty() ? -1 : q[_tail]; }

  bool isEmpty() { return _sz == 0; }

  bool isFull() { return _sz == _max_sz; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// leetcode submit region end(Prohibit modification and deletion)
