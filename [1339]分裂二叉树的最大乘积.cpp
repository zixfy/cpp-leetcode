// 给你一棵二叉树，它的根为 root 。请你删除 1
// 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。
//
//  由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。
//
//
//
//  示例 1：
//
//
//
//  输入：root = [1,2,3,4,5,6]
// 输出：110
// 解释：删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110
// （11*10）
//
//
//  示例 2：
//
//
//
//  输入：root = [1,null,2,3,4,null,null,5,6]
// 输出：90
// 解释：移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90
// （15*6）
//
//
//  示例 3：
//
//  输入：root = [2,3,9,10,7,8,6,5,4,11,1]
// 输出：1025
//
//
//  示例 4：
//
//  输入：root = [1,1]
// 输出：1
//
//
//
//
//  提示：
//
//
//  每棵树最多有 50000 个节点，且至少有 2 个节点。
//  每个节点的值在 [1, 10000] 之间。
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 87 👎 0
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
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
  int maxProduct(TreeNode *root) {
    unordered_map<TreeNode *, int> children_cnt;
    children_cnt[nullptr] = 0;
    function<int(TreeNode *)> count_children = [&](TreeNode *cur) {
      if (cur == nullptr)
        return 0;
      auto ret =
          cur->val + count_children(cur->left) + count_children(cur->right);
      children_cnt[cur] = ret;
      return ret;
    };
    count_children(root);

    constexpr int MOD = 1e9 + 7;
    long long ans = 0;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int par_sum) {
      if (cur == nullptr)
        return;
      ans = max(ans, static_cast<long long>(par_sum) * children_cnt[cur]);
      auto lef_sum = children_cnt[cur->left],
           rig_sum = children_cnt[cur->right];
      dfs(cur->left, par_sum + cur->val + rig_sum);
      dfs(cur->right, par_sum + cur->val + lef_sum);
    };
    dfs(root, 0);
    return ans % MOD;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
