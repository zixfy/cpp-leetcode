// 给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1
// 组成的 正方形 子矩阵的个数。
//
//
//
//  示例 1：
//
//  输入：matrix =
//[
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
//]
// 输出：15
// 解释：
// 边长为 1 的正方形有 10 个。
// 边长为 2 的正方形有 4 个。
// 边长为 3 的正方形有 1 个。
// 正方形的总数 = 10 + 4 + 1 = 15.
//
//
//  示例 2：
//
//  输入：matrix =
//[
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
//]
// 输出：7
// 解释：
// 边长为 1 的正方形有 6 个。
// 边长为 2 的正方形有 1 个。
// 正方形的总数 = 6 + 1 = 7.
//
//
//
//
//  提示：
//
//
//  1 <= arr.length <= 300
//  1 <= arr[0].length <= 300
//  0 <= arr[i][j] <= 1
//
//
//  Related Topics 数组 动态规划 矩阵 👍 280 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    // dp[i][j] = dp[i - 1][j-1], dp[i][j-1]
    const auto [m, n] = make_pair(matrix.size(), matrix[0].size());
    auto upper_cnt = matrix, left_cnt = matrix;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (matrix[i][j]) {
          if (i)
            upper_cnt[i][j] += upper_cnt[i - 1][j];
          if (j)
            left_cnt[i][j] += left_cnt[i][j - 1];
        }
    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i && j && matrix[i][j]) {
          matrix[i][j] += min(matrix[i - 1][j - 1],
                              min(upper_cnt[i][j], left_cnt[i][j]) - 1);
        }
        ans += matrix[i][j];
      }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
