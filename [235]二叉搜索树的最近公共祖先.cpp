// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//
//  百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点
//  p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
//  的深度尽可能大（
// 一个节点也可以是它自己的祖先）。”
//
//  例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5]
//
//
//
//
//
//  示例 1:
//
//  输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// 输出: 6
// 解释: 节点 2 和节点 8 的最近公共祖先是 6。
//
//
//  示例 2:
//
//  输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// 输出: 2
// 解释: 节点 2 和节点 4 的最近公共祖先是 2,
// 因为根据定义最近公共祖先节点可以为节点本身。
//
//
//
//  说明:
//
//
//  所有节点的值都是唯一的。
//  p、q 为不同节点且均存在于给定的二叉搜索树中。
//
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 1071 👎 0

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val > q->val)
      swap(p, q);
    TreeNode *ans{};
    function<pair<bool, bool>(TreeNode *)> dfs =
        [&](TreeNode *cur) -> pair<bool, bool> {
      if (cur == nullptr || ans != nullptr )
        return {false, false};
      auto [p1, q1] = dfs(cur->left);
      auto [p2, q2] = dfs(cur->right);
      auto r = make_pair(p1 || p2 || cur == p, q1 || q2 || cur == q);
      if (!ans && r.first && r.second)
        ans = cur;
      return r;
    };
    dfs(root);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
