// 给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素
// insertVal ，使这个列表仍然是循环升序的。
//
//  给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。
//
//  如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。
//
//  如果列表为空（给定的节点是
//  null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。
//
//
//
//  示例 1：
//
//
//
//
// 输入：head = [3,4,1], insertVal = 2
// 输出：[3,4,1,2]
// 解释：在上图中，有一个包含三个元素的循环有序列表，你获得值为 3
// 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3
// 之间，插入之后 ，整个列表如上图所示，最后返回节点 3 。
//
//
//
//
//  示例 2：
//
//
// 输入：head = [], insertVal = 1
// 输出：[1]
// 解释：列表为空（给定的节点是 null），创建一个循环有序列表并返回这个节点。
//
//
//  示例 3：
//
//
// 输入：head = [1], insertVal = 0
// 输出：[1,0]
//
//
//
//
//  提示：
//
//
//  0 <= Number of Nodes <= 5 * 10^4
//  -10^6 <= Node.val <= 10^6
//  -10^6 <= insertVal <= 10^6
//
//
//
//
//
//  注意：本题与主站 708 题相同：
//  https://leetcode-cn.com/problems/insert-into-a-sorted-
// circular-linked-list/
//
//  Related Topics 链表 👍 151 👎 0

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
class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};
// leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
  Node *insert(Node *head, int insertVal) {
    if (head == nullptr) {
      auto r = new Node(insertVal);
      r->next = r;
      return r;
    }
    auto old_head = head;
    auto max_node = head, min_node = head;
    bool v = false;
    auto las = head;
    do {
      if (head->val >= max_node->val && head->val > head->next->val)
        max_node = head;
      if (head->val < min_node->val || head->val == min_node->val && head->val < las->val)
        min_node = head;
      if (insertVal >= head->val && insertVal <= head->next->val) {
        auto node = new Node(insertVal, head->next);
        head->next = node;
        v = true;
        break;
      }
      las = head;
      head = head->next;
    } while (head != old_head);
    if (!v) {
      if (insertVal > max_node->val) {
        auto node = new Node(insertVal, max_node->next);
        max_node->next = node;
      } else {
        auto node = new Node(min_node->val, min_node->next);
        min_node->next = node;
        if (min_node == old_head)
          old_head = node;
        min_node->val = insertVal;
      }
    }
    return old_head;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
