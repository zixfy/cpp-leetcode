// 路径
// 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
// 至多出现一次 。该路径 至少包含一个 节点，且不 一定经过根节点。
//
//  路径和 是路径中各节点值的总和。
//
//  给定一个二叉树的根节点 root ，返回其
//  最大路径和，即所有路径上节点值之和的最大值。
//
//
//
//  示例 1：
//
//
//
//
// 输入：root = [1,2,3]
// 输出：6
// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
//
//  示例 2：
//
//
//
//
// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
//
//
//
//
//  提示：
//
//
//  树中节点数目范围是 [1, 3 * 10⁴]
//  -1000 <= Node.val <= 1000
//
//
//
//
//
//  注意：本题与主站 124 题相同：
//  https://leetcode-cn.com/problems/binary-tree-maximum-path-
// sum/
//
//  Related Topics 树 深度优先搜索 动态规划 二叉树 👍 74 👎 0
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include "bits/stdc++.h"
using namespace std;
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
  int maxPathSum(TreeNode *root) {
    int ans = numeric_limits<int>::min();
    function<pair<int, int>(TreeNode *)> dfs = [&](TreeNode *cur) -> pair<int, int>{
      if (cur == nullptr)
        return {0, 0};
      auto [l1, l2] = dfs(cur->left);
      auto [r1, r2] = dfs(cur->right);
      auto l = max(l1, l2);
      auto r = max(r1, r2);
      ans = max(ans, cur->val + max(l, 0) + max(r, 0));
      return {cur->val + max(l, 0), cur->val + max(r, 0)};
    };
    dfs(root);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
