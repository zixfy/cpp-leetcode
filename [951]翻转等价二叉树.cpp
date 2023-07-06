// 我们可以为二叉树 T 定义一个 翻转操作
// ，如下所示：选择任意节点，然后交换它的左子树和右子树。
//
//  只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转 等价
//  于二叉树 Y。
//
//  这些树由根节点 root1 和 root2 给出。如果两个二叉树是否是翻转 等价
//  的函数，则返回 true ，否则返回 false 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
// [1,3,2,null,6,4,5,null, null,null,null,8,7] 输出：true 解释：我们翻转值为
// 1，3 以及 5 的三个节点。
//
//
//  示例 2:
//
//
// 输入: root1 = [], root2 = []
// 输出: true
//
//
//  示例 3:
//
//
// 输入: root1 = [], root2 = [1]
// 输出: false
//
//
//
//
//  提示：
//
//
//  每棵树节点数在 [0, 100] 范围内
//  每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 151 👎 0

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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if ((root1 == nullptr) ^ (root2 == nullptr))
      return false;
    if (root1 == nullptr)
      return true;
    if (root1->val != root2->val)
      return false;
    return flipEquiv(root1->left, root2->left) &&
               flipEquiv(root1->right, root2->right) ||
           flipEquiv(root1->left, root2->right) &&
               flipEquiv(root1->right, root2->left);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
