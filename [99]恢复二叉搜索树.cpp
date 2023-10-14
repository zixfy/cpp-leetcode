// 给你二叉搜索树的根节点 root ，该树中的 恰好
// 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
//
//
//
//  示例 1：
//
//
// 输入：root = [1,3,null,null,2]
// 输出：[3,1,null,null,2]
// 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
//
//
//  示例 2：
//
//
// 输入：root = [3,1,4,null,null,2]
// 输出：[2,1,4,null,null,3]
// 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
//
//
//
//  提示：
//
//
//  树上节点的数目在范围 [2, 1000] 内
//  -2³¹ <= Node.val <= 2³¹ - 1
//
//
//
//
//  进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1)
//  空间的解决方案吗？
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 856 👎 0
#include "vector"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
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
using namespace std;
auto recursive_lambda = [](auto lam) {
  return [lam = lam](auto &&...args) {
    return lam(lam, std::forward<decltype(args)>(args)...);
  };
};
class Solution {
public:
  void recoverTree(TreeNode *root) {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *prev = nullptr, *succ = nullptr;
    auto dfs1 = recursive_lambda([&](auto &&self, TreeNode *cur) -> void {
      if (cur == nullptr)
        return;
      self(std::forward<decltype(self)>(self), cur->left);
      if (first != nullptr)
        return;
      if (prev != nullptr && prev->val > cur->val) {
        first = prev;
      }
      prev = cur;

      self(std::forward<decltype(self)>(self), cur->right);
    });
    auto dfs2 = recursive_lambda([&](auto &&self, TreeNode *cur) -> void {
      if (cur == nullptr)
        return;
      self(std::forward<decltype(self)>(self), cur->right);
      if (second != nullptr)
        return;
      if (succ != nullptr && succ->val < cur->val) {
        second = succ;
      }
      succ = cur;

      self(std::forward<decltype(self)>(self), cur->left);
    });
    dfs1(root);
    dfs2(root);
    std::swap(first->val, second->val);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
