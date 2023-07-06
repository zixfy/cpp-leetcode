// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
// 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的
// 根节点的引用。
//
//  一般来说，删除节点可分为两个步骤：
//
//
//  首先找到需要删除的节点；
//  如果找到了，删除它。
//
//
//
//
//  示例 1:
//
//
//
//
// 输入：root = [5,3,6,2,4,null,7], key = 3
// 输出：[5,4,6,2,null,null,7]
// 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
// 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
// 另一个正确答案是 [5,2,6,null,4,null,7]。
//
//
//
//
//  示例 2:
//
//
// 输入: root = [5,3,6,2,4,null,7], key = 0
// 输出: [5,3,6,2,4,null,7]
// 解释: 二叉树不包含值为 0 的节点
//
//
//  示例 3:
//
//
// 输入: root = [], key = 0
// 输出: []
//
//
//
//  提示:
//
//
//  节点数的范围 [0, 10⁴].
//  -10⁵ <= Node.val <= 10⁵
//  节点值唯一
//  root 是合法的二叉搜索树
//  -10⁵ <= key <= 10⁵
//
//
//
//
//  进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
//
//  Related Topics 树 二叉搜索树 二叉树 👍 1146 👎 0

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
  TreeNode *_del(TreeNode *cur, int key) {
    if (cur == nullptr)
      return nullptr;
    if (cur->val < key)
      cur->right = _del(cur->right, key);
    else if (cur->val > key)
      cur->left = _del(cur->left, key);
    else {
      if (cur->left == nullptr)
        return cur->right;
      if (cur->right == nullptr)
        return cur->left;
      auto lef = cur->left, rig = cur->right;
      cur = rig;
      while (rig->left != nullptr)
        rig = rig->left;
      rig->left = lef;
    }
    return cur;
  }
  TreeNode *deleteNode(TreeNode *root, int key) {
    auto v_root = new TreeNode(numeric_limits<int>::min(), nullptr, root);
    _del(v_root, key);
    return v_root->right;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
