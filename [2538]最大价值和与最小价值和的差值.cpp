// 给你一个 n 个节点的无向无根图，节点编号为 0 到 n - 1 。给你一个整数 n
// 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi]
// 表示树中节点 ai 和 bi 之间有一条边。
//
//  每个节点都有一个价值。给你一个整数数组 price ，其中 price[i] 是第 i
//  个节点的价值。
//
//  一条路径的 价值和 是这条路径上所有节点的价值之和。
//
//  你可以选择树中任意一个节点作为根节点 root 。选择 root 为根的 开销 是以 root
//  为起点的所有路径中，价值和 最大的一条路径与最小的一条路径
// 的差值。
//
//  请你返回所有节点作为根节点的选择中，最大 的 开销 为多少。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
// 输出：24
// 解释：上图展示了以节点 2
// 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
//- 第一条路径节点为 [2,1,3,4]：价值为 [7,8,6,10] ，价值和为 31 。
//- 第二条路径节点为 [2] ，价值为 [7] 。
// 最大路径和与最小路径和的差值为 24 。24 是所有方案中的最大开销。
//
//
//  示例 2：
//
//
//
//
// 输入：n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
// 输出：2
// 解释：上图展示了以节点 0
// 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
//- 第一条路径包含节点 [0,1,2]：价值为 [1,1,1] ，价值和为 3 。
//- 第二条路径节点为 [0] ，价值为 [1] 。
// 最大路径和与最小路径和的差值为 2 。2 是所有方案中的最大开销。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 10⁵
//  edges.length == n - 1
//  0 <= ai, bi <= n - 1
//  edges 表示一棵符合题面要求的树。
//  price.length == n
//  1 <= price[i] <= 10⁵
//
//
//  Related Topics 树 深度优先搜索 数组 动态规划 👍 38 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {

    vector adjs(n, vector<int>{});
    vector lower_max(n, 0ll), lower_max2(n, 0ll);

    for (const auto &e : edges) {
      auto u = e[0], v = e[1];
      adjs[u].emplace_back(v), adjs[v].emplace_back(u);
    }
    long long ans = 0;
    auto recursive_lambda = [](auto &&lam) {
      return [lam_impl = lam](auto &&...args) {
        return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
      };
    };
    auto dfs1 =
        recursive_lambda([&price, &adjs, &lower_max, &lower_max2](
                             auto &&self, int par, int cur) -> long long {
          long long max1 = 0, max2 = 0;
          for (auto child : adjs[cur])
            if (child != par) {
              auto nmax = self(self, cur, child) + price[child];
              if (nmax >= max1) {
                max2 = max1;
                max1 = nmax;
              }
              else if (nmax > max2)
                max2 = nmax;
            }
          lower_max[cur] = max1, lower_max2[cur] = max2;
          return max1;
        });
    dfs1(0, 0);
    auto dfs2 = recursive_lambda(
        [&price, &adjs, &ans, &lower_max,
         &lower_max2](auto &&self, int par, long long upper_max, int cur) -> void {
          long long max1 = lower_max[cur], max2 = lower_max2[cur];
          for (auto child : adjs[cur])
            if (child != par) {
              if (lower_max[child] + price[child] <= max2)
                self(self, cur, price[cur] + max(upper_max, max1), child);
              else
                self(self, cur, price[cur] + max(upper_max, max2), child);
            }
//          cout << cur << " " << upper_max << " " << lower_max[cur] << endl;
          ans = max(ans, max(upper_max, lower_max[cur]));
        });
    dfs2(0, 0, 0);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
