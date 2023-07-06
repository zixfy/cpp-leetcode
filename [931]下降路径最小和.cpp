// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径
// 的 最小和 。
//
//  下降路径
//  可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第
// 一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col -
// 1)、(row + 1, col) 或者 (row + 1 , col + 1) 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
// 输出：13
// 解释：如图所示，为和最小的两条下降路径
//
//
//  示例 2：
//
//
//
//
// 输入：matrix = [[-19,57],[-40,-5]]
// 输出：-59
// 解释：如图所示，为和最小的下降路径
//
//
//
//
//  提示：
//
//
//  n == matrix.length == matrix[i].length
//  1 <= n <= 100
//  -100 <= matrix[i][j] <= 100
//
//
//  Related Topics 数组 动态规划 矩阵 👍 226 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    // dp[i][j] = min(dp[i-1][j, j-1, j+1]) + d[i][j]
    const auto [m, n] = make_pair(matrix.size(), matrix[0].size());
    array dp{vector(n, 0), vector(n, 0)};
    for (int i = 0; i < m; ++i) {
      const auto& pre = dp[(i + 1) & 1];
      auto &cur = dp[i & 1];
      for (int j = 0; j < n; ++j) {
        cur[j] = pre[j];
        if (j)
          cur[j] = min(cur[j], pre[j - 1]);
        if (j < n - 1)
          cur[j] = min(cur[j], pre[j + 1]);
        cur[j] += matrix[i][j];
      }
    }
    auto &ans = dp[(m - 1) & 1];
    return *min_element(ans.begin(), ans.end());
  }
};
// leetcode submit region end(Prohibit modification and deletion)
