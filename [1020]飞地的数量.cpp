// 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1
// 表示一个陆地单元格。
//
//  一次 移动
//  是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid
//  的边界。
//
//  返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
//
//
//
//  示例 1：
//
//
// 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// 输出：3
// 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
//
//
//  示例 2：
//
//
// 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// 输出：0
// 解释：所有 1 都在边界上或可以到达边界。
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 500
//  grid[i][j] 的值为 0 或 1
//
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 206 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {
    const auto m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      if (grid[0][i] == 1)
        q.emplace(0, i);
      if (grid[m - 1][i] == 1)
        q.emplace(m - 1, i);
    }
    for (int i = 0; i < m; ++i) {
      if (grid[i][0] == 1)
        q.emplace(i, 0);
      if (grid[i][n - 1])
        q.emplace(i, n - 1);
    }
    while (!q.empty()) {
      const auto [x, y] = q.front();
      if (grid[x][y] == 1) {
        grid[x][y] = 2;
        for (const auto [nx, ny] : vector<pair<int, int>>{
                 {x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}}) {
          if (nx > -1 && nx < m && ny > -1 && ny < n && grid[nx][ny] == 1)
            q.emplace(nx, ny);
        }
      }
      q.pop();
    }
    int ans = 0;
    for (int k = 0; k < n * m; ++k)
      ans += grid[k / n][k % n] == 1;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
