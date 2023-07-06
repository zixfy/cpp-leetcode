// 给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的
// 叶子节点 。
//
//  注意，一旦删除值为 target
//  的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target
//  ，那么这个节点也应该被删除。
//
//  也就是说，你需要重复此过程直到不能继续删除。
//
//
//
//  示例 1：
//
//
//
//  输入：root = [1,2,3,2,null,2,4], target = 2
// 输出：[1,null,3,null,4]
// 解释：
// 上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2
// ），它们会被删除，得到中间的图。 有一个新的节点变成了叶子节点且它的值与
// target 相同，所以将再次进行删除，从而得到最右边的图。
//
//
//  示例 2：
//
//
//
//  输入：root = [1,3,3,3,2], target = 3
// 输出：[1,3,null,null,2]
//
//
//  示例 3：
//
//
//
//  输入：root = [1,2,null,2,null,2], target = 2
// 输出：[1]
// 解释：每一步都删除一个绿色的叶子节点（值为 2）。
//
//  示例 4：
//
//  输入：root = [1,1,1], target = 1
// 输出：[]
//
//
//  示例 5：
//
//  输入：root = [1,2,3], target = 1
// 输出：[1,2,3]
//
//
//
//
//  提示：
//
//
//  1 <= target <= 1000
//  每一棵树最多有 3000 个节点。
//  每一个节点值的范围是 [1, 1000] 。
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 104 👎 0

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
private:
  TreeNode *_del(TreeNode *cur, int target) {
    if (cur == nullptr)
      return nullptr;
    cur->left= _del(cur->left, target);
    cur->right= _del(cur->right, target);
    if (cur->val == target && (cur->left == cur->right))
      return nullptr;
    return cur;
  }

public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    return _del(root, target);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
