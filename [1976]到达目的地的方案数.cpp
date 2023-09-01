// 你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有
// 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两
// 个路口之间最多有一条路。
//
//  给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei]
//  表示在路口 ui 和 vi 之间有一条需要花费 timei
//  时间才能通过的道路。你想知道花费 最少时间 从路口 0 出发到达路口 n - 1
//  的方案数。
//
//  请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 10⁹ +
//  7 取余 后返回。
//
//
//
//  示例 1：
//  输入：n = 7, roads =
//  [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2
//,5,1],[0,4,5],[4,6,2]]
// 输出：4
// 解释：从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
// 四条花费 7 分钟的路径分别为：
//- 0 ➝ 6
//- 0 ➝ 4 ➝ 6
//- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
//- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
//
//
//  示例 2：
//
//  输入：n = 2, roads = [[1,0,10]]
// 输出：1
// 解释：只有一条从路口 0 到路口 1 的路，花费 10 分钟。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 200
//  n - 1 <= roads.length <= n * (n - 1) / 2
//  roads[i].length == 3
//  0 <= ui, vi <= n - 1
//  1 <= timei <= 10⁹
//  ui != vi
//  任意两个路口之间至多有一条路。
//  从任意路口出发，你能够到达其他任意路口。
//
//
//  Related Topics 图 拓扑排序 动态规划 最短路 👍 64 👎 0

#include <bits/stdc++.h>
using let = std::any;
using i64 = std::int64_t;

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
using u64 = std::uint64_t;
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector adjs(n, vector<pair<int, int>>{});
    for (auto const &road : roads)
      adjs[road[0]].emplace_back(road[1], road[2]),
          adjs[road[1]].emplace_back(road[0], road[2]);

    vector dist(n, numeric_limits<u64>::max());
    vector dp(n, 0);
    dp[0] = 1;
    dist[0] = 0;
    priority_queue<pair<u64, int>, vector<pair<u64, int>>, greater<>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
      auto [cur_d, cur_p] = q.top();
//      cout << cur_p << ", " << cur_d << endl;
      q.pop();
      if (dist[cur_p] < cur_d)
        continue;
      for (auto [to, cost] : adjs[cur_p]) {
        auto nxt_d = cur_d + cost;
        if (nxt_d > dist[to])
          continue;
        if (nxt_d < dist[to])
          dp[to] = 0, q.emplace(nxt_d, to);
        dist[to] = nxt_d;
        dp[to] = (dp[to] + dp[cur_p]) % MOD;
      }
    }
//    std::copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, ", "));
    return dp.back();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
