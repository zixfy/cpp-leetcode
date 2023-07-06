// 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n
// 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
//
//
//
//
//
//  示例 1：
//
//
// 输入：n = 3
// 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//
//
//
//
//  示例 2：
//
//
// 输入：n = 1
// 输出：[[1]]
//
//
//
//
//  提示：
//
//
//  1 <= n <= 8
//
//
//  Related Topics 树 二叉搜索树 动态规划 回溯 二叉树 👍 1419 👎 0
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
struct MyPairHash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &p) const {
    return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
  }
};

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    unordered_map<pair<int, int>, vector<TreeNode *>, MyPairHash> dp;
    for (int i = 1; i <= n; ++i)
      dp[{i, i}].emplace_back(new TreeNode(i));
    auto nil = vector<TreeNode *>{nullptr};
    function<const vector<TreeNode *> &(int, int)> dfs =
        [&](int l, int r) -> const vector<TreeNode *> & {
      if (l > r)
        return nil;
      auto &ret = dp[{l, r}];
      if (!ret.empty())
        return ret;
      for (int m = l; m <= r; ++m)
        for (auto p1 : dfs(l, m - 1))
          for (auto p2 : dfs(m + 1, r))
            ret.push_back(new TreeNode(m, p1, p2));
      return ret;
    };
    return dfs(1, n);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
