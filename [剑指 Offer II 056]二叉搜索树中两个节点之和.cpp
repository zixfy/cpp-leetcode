// 给定一个二叉搜索树的 根节点 root 和一个整数 k ,
// 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k
// 。假设二叉搜索树中节点的值均唯一。
//
//
//
//  示例 1：
//
//
// 输入: root = [8,6,10,5,7,9,11], k = 12
// 输出: true
// 解释: 节点 5 和节点 7 之和等于 12
//
//
//  示例 2：
//
//
// 输入: root = [8,6,10,5,7,9,11], k = 22
// 输出: false
// 解释: 不存在两个节点值之和为 22 的节点
//
//
//
//
//  提示：
//
//
//  二叉树的节点个数的范围是 [1, 10⁴].
//  -10⁴ <= Node.val <= 10⁴
//  root 为二叉搜索树
//  -10⁵ <= k <= 10⁵
//
//
//
//
//  注意：本题与主站 653 题相同：
//  https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 哈希表 双指针 二叉树
//  👍 62 👎 0

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
  TreeNode *_find(TreeNode *cur, int k) {
    if (cur == nullptr)
      return nullptr;
    if (cur->val == k)
      return cur;
    else if (cur->val > k)
      return _find(cur->left, k);
    return _find(cur->right, k);
  }

public:
  bool findTarget(TreeNode *root, int k) {
    vector<TreeNode*>q;
    q.push_back(root);
    while (!q.empty()) {
      auto cur = q.back();
      auto _r = _find(root, k - (cur->val));
      if (_r != nullptr && _r != cur) {

        return true;
      }
      q.pop_back();
      if (cur->left)
        q.push_back(cur->left);
      if (cur->right)
        q.push_back(cur->right);
    }
    return false;
    // 2n -> n - 1, 2n + 1 -> n
  }
};
// leetcode submit region end(Prohibit modification and deletion)
