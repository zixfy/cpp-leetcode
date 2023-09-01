// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//
//  差值是一个正数，其数值等于两值之差的绝对值。
//
//
//
//  示例 1：
//
//
// 输入：root = [4,2,6,1,3]
// 输出：1
//
//
//  示例 2：
//
//
// 输入：root = [1,0,48,null,null,12,49]
// 输出：1
//
//
//
//
//  提示：
//
//
//  树中节点的数目范围是 [2, 10⁴]
//  0 <= Node.val <= 10⁵
//
//
//
//
//  注意：本题与 783
//  https://leetcode-cn.com/problems/minimum-distance-between-bst-
// nodes/ 相同
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 二叉树 👍 483 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
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

auto recursive_lambda = [](auto &&lam) {
  return [lam_impl = lam](auto &&...args) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};

class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    using xy = std::pair<int, int>;
    auto ans = std::numeric_limits<int>::max();
    auto dfs = recursive_lambda([&](auto &&self, TreeNode *cur) -> xy {
      if (cur->left == nullptr && cur->right == nullptr)
        return {cur->val, cur->val};
      auto mini = cur->val;
      auto maxi = cur->val;
      if (cur->left != nullptr) {
        auto [l_mini, l_maxi] = self(self, cur->left);
        mini = l_mini;
        ans = std::min(ans, cur->val - l_maxi);
      }
      if (cur->right != nullptr) {
        auto [r_mini, r_maxi] = self(self, cur->right);
        maxi = r_maxi;
        ans = std::min(ans, r_mini - cur->val );
      }
      return {mini, maxi};
    });
    dfs(root);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
