// 给你一个下标从 0 开始的 m x n 二进制矩阵 grid 。
//
//  我们按照如下过程，定义一个下标从 0 开始的 m x n 差值矩阵 diff ：
//
//
//  令第 i 行一的数目为 onesRowi 。
//  令第 j 列一的数目为 onesColj 。
//  令第 i 行零的数目为 zerosRowi 。
//  令第 j 列零的数目为 zerosColj 。
//  diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
//
//
//  请你返回差值矩阵 diff 。
//
//
//
//  示例 1：
//
//
//
//  输入：grid = [[0,1,1],[1,0,1],[0,0,1]]
// 输出：[[0,0,4],[0,0,4],[-2,-2,2]]
// 解释：
//- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0
//
//- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0
//
//- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4
//
//- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0
//
//- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0
//
//- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4
//
//- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -
// 2
//- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -
// 2
//- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2
//
//
//
//  示例 2：
//
//
//
//  输入：grid = [[1,1,1],[1,1,1]]
// 输出：[[5,5,5],[5,5,5]]
// 解释：
//- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
//
//- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
//
//- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
//
//- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
//
//- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
//
//- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5
//
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 10⁵
//  1 <= m * n <= 10⁵
//  grid[i][j] 要么是 0 ，要么是 1 。
//
//
//  Related Topics 数组 矩阵 模拟 👍 6 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
    auto m = grid.size(), n = grid[0].size();
    vector<int> row_cnt, col_cnt;
    row_cnt.reserve(m), col_cnt.reserve(n);
    std::transform(grid.begin(), grid.end(), back_inserter(row_cnt),
                   [](auto const &row) {
                     return std::accumulate(row.begin(), row.end(), 0);
                   });
    std::generate_n(back_inserter(col_cnt), n, [i = 0, &grid]() mutable {
      auto ret = std::accumulate(
          grid.begin(), grid.end(), 0,
          [i](int acc, const vector<int> &v) { return acc + v[i]; });
      ++i;
      return ret;
    });
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        grid[i][j] = ((row_cnt[i] + col_cnt[j]) << 1) -m - n;
      }
    return grid;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
