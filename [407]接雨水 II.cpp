// 给你一个 m x n
// 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
//
//
//
//  示例 1:
//
//
//
//
// 输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// 输出: 4
// 解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
//
//
//  示例 2:
//
//
//
//
// 输入: heightMap =
// [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]] 输出: 10
//
//
//
//
//  提示:
//
//
//  m == heightMap.length
//  n == heightMap[i].length
//  1 <= m, n <= 200
//  0 <= heightMap[i][j] <= 2 * 10⁴
//
//
//
//
//  Related Topics 广度优先搜索 数组 矩阵 堆（优先队列） 👍 679 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using u8 = std::uint8_t;
using u32 = std::uint32_t;
using xy = std::pair<int, int>;
constexpr std::array<xy, 4> dirs{{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
class Solution {
public:
  int trapRainWater(std::vector<std::vector<int>> &heightMap) {
    auto m = heightMap.size(), n = heightMap.front().size();

    int ans = 0, tim = 0;
    std::vector vis(m, std::vector(n, u32{false}));
    auto valid_adj_cnt = [&](int x, int y) {
      auto ret = 0;
      for (auto [dx, dy] : dirs) {
        auto nx = x + dx, ny = y + dy;
        if (nx < m && nx >= 0 && ny < n && ny >= 0 && !vis[nx][ny] &&
            heightMap[x][y] <= heightMap[nx][ny])
          ++ret;
      }
      return ret;
    };
    auto bfs = [&](int i, int j) {
      if (vis[i][j])
        return 0;
      auto basin_cnt = 1, basin_vol = heightMap[i][j],
           min_border = heightMap[i][j];
      std::vector<xy> border, nxt_border;
      border.emplace_back(i, j);
      while (!border.empty()) {
        auto valid_border_cnt = 0;
        auto border_cnt = border.size();
        for (auto [bx, by] : border) {
          bool okay = 0;
          valid_border_cnt += okay;
        }
        return basin_cnt * min_border - basin_vol;
      };
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ++tim, ans += bfs(i, j);

    return ans;
  }
};

// leetcode submit region end(Prohibit modification and deletion)
