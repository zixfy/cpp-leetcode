// 给定一个无向、连通的树。树中有 n 个标记为 0...n-1 的节点以及 n-1 条边 。
//
//  给定整数 n 和数组 edges ， edges[i] = [ai, bi]表示树中的节点 ai 和 bi
//  之间有一条边。
//
//  返回长度为 n 的数组 answer ，其中 answer[i] 是树中第 i
//  个节点与所有其他节点之间的距离之和。
//
//
//
//  示例 1:
//
//
//
//
// 输入: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// 输出: [8,12,6,10,10,10]
// 解释: 树如图所示。
// 我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// 也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
//
//
//  示例 2:
//
//
// 输入: n = 1, edges = []
// 输出: [0]
//
//
//  示例 3:
//
//
// 输入: n = 2, edges = [[1,0]]
// 输出: [1,1]
//
//
//
//
//  提示:
//
//
//  1 <= n <= 3 * 10⁴
//  edges.length == n - 1
//  edges[i].length == 2
//  0 <= ai, bi < n
//  ai != bi
//  给定的输入保证为有效的树
//
//
//  Related Topics 树 深度优先搜索 图 动态规划 👍 425 👎 0

#include <bits/stdc++.h>
// leetcode submit region begin(Prohibit modification and deletion)
auto recursive_lambda = [](auto &&lam) {
  return [lam_impl = lam](auto &&...args) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};
class Solution {
public:
  std::vector<int> sumOfDistancesInTree(int n,
                                        std::vector<std::vector<int>> &edges) {
    std::vector adjs(n, std::vector<int>{});
    std::vector sizes(n, 0), dp(n, 0);
    for (const auto &e : edges) {
      auto u = e[0], v = e[1];
      adjs[u].emplace_back(v), adjs[v].emplace_back(u);
    }
    auto dfs1 = recursive_lambda(
        [&sizes, &adjs](auto &&self, int cur, int par) -> std::pair<int, int> {
          int sz = 1, dt = 0;
          for (auto child : adjs[cur])
            if (par != child) {
              auto [c_sz, c_dt] = self(self, child, cur);
              sz += c_sz;
              dt += c_sz + c_dt;
            }
          sizes[cur] = sz;
          return {sz, dt};
        });
    dp[0] = dfs1(0, 0).second;
    auto dfs2 = recursive_lambda(
        [&dp, &sizes, &adjs, n](auto &&self, int cur, int par) -> void {
          for (auto child : adjs[cur])
            if (par != child) {
              dp[child] = dp[cur] - sizes[child] + n - sizes[child];
              self(self, child, cur);
            }
        });
    dfs2(0, 0);
    return dp;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
