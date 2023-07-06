// 给定两个 非空链表 l1和 l2
// 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
//  可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//
//
//  示例1：
//
//
//
//
// 输入：l1 = [7,2,4,3], l2 = [5,6,4]
// 输出：[7,8,0,7]
//
//
//  示例2：
//
//
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[8,0,7]
//
//
//  示例3：
//
//
// 输入：l1 = [0], l2 = [0]
// 输出：[0]
//
//
//
//
//  提示：
//
//
//  链表的长度范围为 [1, 100]
//  0 <= node.val <= 9
//  输入数据保证链表代表的数字无前导 0
//
//
//
//
//  进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。
//
//
//
//
//  注意：本题与主站 445
//  题相同：https://leetcode-cn.com/problems/add-two-numbers-ii/
//
//  Related Topics 栈 链表 数学 👍 93 👎 0

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

int carry(ListNode *cur) {
  if (cur == nullptr)
    return 0;
  if ((cur->val += carry(cur->next)) > 9) {
    cur->val -= 10;
    return 1;
  }
  return 0;
}
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    auto h1 = l1, t1 = l1, h2 = l2, t2 = l2;
    while (t1 && t2)
      t1 = t1->next, t2 = t2->next;
    if (t1 == nullptr)
      swap(t1, t2), swap(h1, h2);
    auto old_h1 = h1;
    while (t1 != nullptr)
      h1 = h1->next, t1 = t1->next;
    while (h1 != nullptr)
      h1->val += h2->val, h1 = h1->next, h2 = h2->next;
    l1 = old_h1;
    auto c = carry(l1);
    return c ? new ListNode(1, l1) : l1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
