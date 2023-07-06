// 现有一个含 n 个顶点的 双向 图，每个顶点按从 0 到 n - 1
// 标记。图中的边由二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui
// 和 vi
// 之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。
//
//  返回图中 最短 环的长度。如果不存在环，则返回 -1 。
//
//  环 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。
//
//
//
//  示例 1：
//  输入：n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
// 输出：3
// 解释：长度最小的循环是：0 -> 1 -> 2 -> 0
//
//
//  示例 2：
//  输入：n = 4, edges = [[0,1],[0,2]]
// 输出：-1
// 解释：图中不存在循环
//
//
//
//
//  提示：
//
//
//  2 <= n <= 1000
//  1 <= edges.length <= 1000
//  edges[i].length == 2
//  0 <= ui, vi < n
//  ui != vi
//  不存在重复的边
//
//
//  Related Topics 广度优先搜索 图 👍 11 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int findShortestCycle(int n, vector<vector<int>> &edges) {
    using xy = pair<int, int>;
    auto ans = INT_MAX;
    vector adjs(n, vector<int>{});
    for (const auto &edge : edges) {
      auto u = edge[0], v = edge[1];
      adjs[u].push_back(v), adjs[v].push_back(u);
    }
    for (const auto &edge : edges) {
      auto u = edge[0], v = edge[1];
      queue<xy> q;

      vector<char> vis(n, false);
      vis[u] = true;
      for (auto to : adjs[u])
        if (to != v)
          q.emplace(to, 1), vis[to] = true;
      while (!q.empty()) {
        auto [cur, dist] = q.front();
        if (cur == v) {
          ans = min(ans, dist + 1);
          break;
        }
        for (auto to : adjs[cur]) {
          if (!vis[to])
            q.emplace(to, dist + 1), vis[to] = true;
        }
        q.pop();
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
