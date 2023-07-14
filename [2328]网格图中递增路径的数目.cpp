// 给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4
// 个方向相邻的任意一个格子。
//
//  请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是
//  严格递增 的路径数目。由于答案可能会很大，请将结果对 10⁹ + 7 取余 后返
// 回。
//
//  如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。
//
//
//
//  示例 1：
//
//
//
//  输入：grid = [[1,1],[3,4]]
// 输出：8
// 解释：严格递增路径包括：
//- 长度为 1 的路径：[1]，[1]，[3]，[4] 。
//- 长度为 2 的路径：[1 -> 3]，[1 -> 4]，[3 -> 4] 。
//- 长度为 3 的路径：[1 -> 3 -> 4] 。
// 路径数目为 4 + 3 + 1 = 8 。
//
//
//  示例 2：
//
//  输入：grid = [[1],[2]]
// 输出：3
// 解释：严格递增路径包括：
//- 长度为 1 的路径：[1]，[2] 。
//- 长度为 2 的路径：[1 -> 2] 。
// 路径数目为 2 + 1 = 3 。
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 1000
//  1 <= m * n <= 10⁵
//  1 <= grid[i][j] <= 10⁵
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 记忆化搜索 数组
//  动态规划 矩阵 👍 34 👎 0

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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
namespace std {
template <typename U, typename V> struct hash<pair<U, V>> {
  size_t operator()(const pair<U, V> &p) const {
    return std::hash<U>()(p.first) ^ (std::hash<V>()(p.second) << 1);
  }
};
} // namespace std
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int countPaths(vector<vector<int>> &grid) {
    const auto m = grid.size(), n = grid[0].size();
    unordered_map<pair<int, int>, int> dp;
    function<int(int, int)> mem_dp = [&dp, &grid, m, n, &mem_dp](int i, int j) {
      auto coords = make_pair(i, j);
      if (dp.count(coords) == 0) {
        int cnt = 1;
        for (auto [x, y] : initializer_list<pair<int, int>>{
                 {i, j + 1}, {i, j - 1}, {i + 1, j}, {i - 1, j}})
          if (x > -1 && x < m && y > -1 && y < n && grid[i][j] < grid[x][y])
            cnt = (cnt + mem_dp(x, y)) % MOD;
        dp[coords] = cnt;
        return cnt;
      }
      return dp[coords];
    };
    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = (ans + mem_dp(i, j)) % MOD;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
