// 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是
// mat 中对应位置元素到最近的 0 的距离。
//
//  两个相邻元素间的距离为 1 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：[[0,0,0],[0,1,0],[0,0,0]]
//
//
//  示例 2：
//
//
//
//
// 输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
// 输出：[[0,0,0],[0,1,0],[1,2,1]]
//
//
//
//
//  提示：
//
//
//  m == mat.length
//  n == mat[i].length
//  1 <= m, n <= 10⁴
//  1 <= m * n <= 10⁴
//  mat[i][j] is either 0 or 1.
//  mat 中至少有一个 0
//
//
//  Related Topics 广度优先搜索 数组 动态规划 矩阵 👍 854 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
constexpr array<pair<int, int>, 4> dirs = {{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    const int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j])
          mat[i][j] = numeric_limits<int>::max();
        else
          q.emplace(i, j);
    while (!q.empty()) {
      const auto [x, y] = q.front();
      for (const auto [dx, dy] : dirs) {
        int nx = dx + x, ny = dy + y;
        if (nx > -1 && nx < m && ny > -1 && ny < n &&
            mat[nx][ny] == numeric_limits<int>::max()) {
          mat[nx][ny] = mat[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
      q.pop();
    }
    return mat;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
