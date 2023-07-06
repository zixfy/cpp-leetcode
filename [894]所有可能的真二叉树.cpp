// 给你一个整数 n ，请你找出所有可能含 n 个节点的 真二叉树
// ，并以列表形式返回。答案中每棵树的每个节点都必须符合 Node.val == 0 。
//
//  答案的每个元素都是一棵真二叉树的根节点。你可以按 任意顺序
//  返回最终的真二叉树列表。
//
//  真二叉树 是一类二叉树，树中每个节点恰好有 0 或 2 个子节点。
//
//
//
//  示例 1：
//
//
// 输入：n = 7
// 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0
//,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//
//
//  示例 2：
//
//
// 输入：n = 3
// 输出：[[0,0,0]]
//
//
//
//
//  提示：
//
//
//  1 <= n <= 20
//
//
//  Related Topics 树 递归 记忆化搜索 动态规划 二叉树 👍 292 👎 0

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int n) {
    if (!(n & 1))
      return {};
    vector ans(n + 1, vector<TreeNode *>());
    ans[1].push_back(new TreeNode());
    function<vector<TreeNode *> &(int)> dfs =
        [&](int cur) -> vector<TreeNode *> & {
      auto &r = ans[cur];
      if (!r.empty())
        return r;
      for (int i = 1; i < cur - 1; i += 2)
        for (const auto n1 : dfs(i))
          for (const auto n2 : dfs(cur - 1 - i))
            r.push_back(new TreeNode(0, n1, n2));
      return r;
    };
    return dfs(n);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
