// 给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0
// 的连续节点组成的序列，直到不存在这样的序列为止。
//
//  删除完毕后，请你返回最终结果链表的头节点。
//
//
//
//  你可以返回任何满足题目要求的答案。
//
//  （注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
//
//  示例 1：
//
//  输入：head = [1,2,-3,3,1]
// 输出：[3,1]
// 提示：答案 [1,2,1] 也是正确的。
//
//
//  示例 2：
//
//  输入：head = [1,2,3,-3,4]
// 输出：[1,2,4]
//
//
//  示例 3：
//
//  输入：head = [1,2,3,-3,-2]
// 输出：[1]
//
//
//
//
//  提示：
//
//
//  给你的链表中可能有 1 到 1000 个节点。
//  对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.
//
//
//  Related Topics 哈希表 链表 👍 195 👎 0

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

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "[";
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

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V *> p) {
  o << "{";
  for (const auto &a : p)
    o << a.first << " : " << a.second->val << ", ";
  return o << "}\n";
}
class Solution {
public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    auto ans = new ListNode(0, head);
    unordered_map<int, ListNode *> mapy;
    mapy[0] = ans;
    int prefix = 0;
    auto p = head;
    while (p != nullptr) {
      prefix += p->val;
      if (mapy.count(prefix)) {
        auto ori_p = mapy[prefix];
        auto tmp_p = ori_p ->next;
        auto tmp_pre = prefix;
        while (tmp_p != p) {
          tmp_pre += tmp_p->val;
          mapy.erase(tmp_pre);
          tmp_p = tmp_p ->next;
        }
        ori_p->next = p->next;
      } else mapy[prefix] = p;
//            cout << p->val << " " << prefix << endl << mapy << endl;
      p = p->next;
    }
    auto ret = ans->next;
    delete ans;
    if (ret == nullptr || ret->val == 0)
      return nullptr;
    return ret;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
