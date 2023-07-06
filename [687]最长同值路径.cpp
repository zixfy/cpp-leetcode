// 给定一个二叉树的
//  root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。
//  这条路径可以经过也可以不经过根节点。
//
//  两个节点之间的路径长度 由它们之间的边数表示。
//
//
//
//  示例 1:
//
//
//
//
// 输入：root = [5,4,5,1,1,5]
// 输出：2
//
//
//  示例 2:
//
//
//
//
// 输入：root = [1,4,5,4,4,5]
// 输出：2
//
//
//
//
//  提示:
//
//
//  树的节点数的范围是
//  [0, 10⁴]
//  -1000 <= Node.val <= 1000
//  树的深度将不超过 1000
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 763 👎 0
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
  int longestUnivaluePath(TreeNode *root) {
    using xy = pair<int, int>;
    int ans{};
    function<xy(decltype(root))> dfs = [&](decltype(root) cur) -> xy {
      if (nullptr == cur)
        return {0, 0};
      xy r{1, 1};
      //no branches, branches
      xy&& lef = dfs(cur->left), &&rig = dfs(cur -> right);
      if (cur->left&&cur->val != cur->left->val)
        lef = {0, 0};
      if (cur->right&&cur->val != cur->right->val)
        rig = {0, 0};
      r.first = 1 + max(lef.first, rig.first);
      r.second = 1 + lef.first + rig.first;
      ans = max(ans, r.second);
//      cout << "val: " << cur->val << " r:" << r << endl;
      return r;
    };
    if (nullptr == root)
        return 0;
    dfs(root);
    return ans - 1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
