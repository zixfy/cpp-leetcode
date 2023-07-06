// 在一个 n x n 的矩阵 grid 中，除了在数组 mines 中给出的元素为
// 0，其他每个元素都为 1。mines[i] = [xi, yi]表示 grid[xi][yi] == 0
//
//  返回 grid 中包含 1 的最大的 轴对齐 加号标志的阶数
//  。如果未找到加号标志，则返回 0 。
//
//  一个 k 阶由 1 组成的 “轴对称”加号标志 具有中心网格 grid[r][c] == 1
//  ，以及4个从中心向上、向下、向左、向右延伸，长度为 k-1，
// 由 1 组成的臂。注意，只有加号标志的所有网格要求为 1 ，别的网格可能为 0
// 也可能为 1 。
//
//
//
//  示例 1：
//
//
//
//
// 输入: n = 5, mines = [[4, 2]]
// 输出: 2
// 解释: 在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
//
//
//  示例 2：
//
//
//
//
// 输入: n = 1, mines = [[0, 0]]
// 输出: 0
// 解释: 没有加号标志，返回 0 。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 500
//  1 <= mines.length <= 5000
//  0 <= xi, yi < n
//  每一对 (xi, yi) 都 不重复
//
//
//  Related Topics 数组 动态规划 👍 207 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
struct PairHash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &pair) const {
    std::size_t hash1 = std::hash<T>{}(pair.first);
    std::size_t hash2 = std::hash<U>{}(pair.second);
    return hash1 ^ hash2;
  }
};
struct PairEqual {
  template <typename T, typename U>
  bool operator()(const std::pair<T, U> &lhs,
                  const std::pair<T, U> &rhs) const {
    return lhs.first == rhs.first && lhs.second == rhs.second;
  }
};
class Solution {
public:
  int orderOfLargestPlusSign(int sz, vector<vector<int>> &mines) {
    auto dp = new int[sz * sz][4]();

    unordered_set<pair<int, int>, PairHash, PairEqual> pool;
    for (const auto &p : mines)
      pool.emplace(p[0], p[1]);

    for (int i{}; i < sz * sz; ++i) {
      const auto [x, y] = make_pair(i / sz, i % sz);
      if (pool.count({x, y}))
        continue;
      dp[i][0] = x ? (1 + dp[i - sz][0]) : 1;
      dp[i][1] = y ? (1 + dp[i - 1][1]) : 1;
    }
    for (int i{sz * sz - 1}; i > -1; --i) {
      const auto [x, y] = make_pair(i / sz, i % sz);
      if (pool.count({x, y}))
        continue;
      dp[i][2] = x < sz  -1? (1 + dp[i + sz][2]) : 1;
      dp[i][3] = y < sz -1 ? (1 + dp[i + 1][3]) : 1;
    } cout << "here";
//    for (int i = 0; i < sz * sz * 4; ++i)
//     cout << ((int *)(dp))[i] << endl;
    int ans{};
    for (int i = 0; i < sz * sz; ++i)
      ans = max(ans, min(min(dp[i][0], dp[i][1]), min(dp[i][2], dp[i][3])));
//    cout << "here";
    delete[] dp;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
