// 给你一个大小为 m x n 的整数矩阵 grid 和一个大小为 k 的数组 queries 。
//
//  找出一个大小为 k 的数组 answer ，且满足对于每个整数 queries[i] ，你从矩阵
//  左上角 单元格开始，重复以下过程：
//
//
//  如果 queries[i] 严格
//  大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1
//  分，并且你可以移动到所有 4 个方向（上、下、左、右）上
// 任一 相邻 单元格。
//  否则，你不能获得任何分，并且结束这一过程。
//
//
//  在过程结束后，answer[i]
//  是你可以获得的最大分数。注意，对于每个查询，你可以访问同一个单元格 多次 。
//
//  返回结果数组 answer 。
//
//
//
//  示例 1：
//
//
// 输入：grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
// 输出：[5,8,1]
// 解释：上图展示了每个查询中访问并获得分数的单元格。
//
//  示例 2：
//
//
// 输入：grid = [[5,2,1],[1,1,2]], queries = [3]
// 输出：[0]
// 解释：无法获得分数，因为左上角单元格的值大于等于 3 。
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  2 <= m, n <= 1000
//  4 <= m * n <= 10⁵
//  k == queries.length
//  1 <= k <= 10⁴
//  1 <= grid[i][j], queries[i] <= 10⁶
//
//
//  Related Topics 广度优先搜索 并查集 数组 排序 堆（优先队列） 👍 36 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
using xy = pair<int, int>;
using wxy = pair<int, xy>;
constexpr std::array<xy, 4> dirs{{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}};
class Solution {
public:
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
    using u8 = uint8_t;
    auto m = grid.size(), n = grid[0].size(), l = queries.size();

    vector vis(m, vector(n, u8{}));
    std::priority_queue<wxy, vector<wxy>, greater<>> q;
    q.emplace(grid[0][0], xy{0, 0});
    vis[0][0] = true;

    std::unordered_map<int, int> threshold2value;
    int cur_sum = 0, cur_max = 0;
    while (!q.empty()) {
      auto [cur, pos] = q.top();
      q.pop();

      cur_max = max(cur_max, cur);
      ++cur_sum;

      threshold2value[cur_max] = cur_sum;

      for (auto [dx, dy] : dirs) {
        auto nx = pos.first + dx, ny = pos.second + dy;
        if (nx < m && nx > -1 && ny > -1 && ny < n && !vis[nx][ny])
          vis[nx][ny] = true, q.emplace(grid[nx][ny], xy{nx, ny});
      }
    }

    vector<xy> kv(threshold2value.begin(), threshold2value.end());
    std::sort(kv.begin(), kv.end());
    std::transform(
        queries.begin(), queries.end(), queries.begin(), [&kv](int q) {
          auto iter = std::upper_bound(kv.begin(), kv.end(), pair{q, 0});
          if (iter == kv.begin())
            return 0;
          return std::prev(iter)->second;
        });
    return queries;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
