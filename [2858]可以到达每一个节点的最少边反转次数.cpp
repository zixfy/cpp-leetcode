// 给你一个 n 个点的 简单有向图 （没有重复边的有向图），节点编号为 0 到 n - 1
// 。如果这些边是双向边，那么这个图形成一棵 树 。
//
//  给你一个整数 n 和一个 二维 整数数组 edges ，其中 edges[i] = [ui, vi]
//  表示从节点 ui 到节点 vi 有一条 有向边 。
//
//
//  边反转 指的是将一条边的方向反转，也就是说一条从节点 ui 到节点 vi
//  的边会变为一条从节点 vi 到节点 ui 的边。
//
//  对于范围 [0, n - 1] 中的每一个节点 i ，你的任务是分别 独立 计算 最少
//  需要多少次 边反转 ，从节点 i 出发经过 一系列有向边 ，可以到
// 达所有的节点。
//
//  请你返回一个长度为 n 的整数数组 answer ，其中 answer[i]表示从节点 i
//  出发，可以到达所有节点的 最少边反转 次数。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 4, edges = [[2,0],[2,1],[1,3]]
// 输出：[1,1,0,2]
// 解释：上图表示了与输入对应的简单有向图。
// 对于节点 0 ：反转 [2,0] ，从节点 0 出发可以到达所有节点。
// 所以 answer[0] = 1 。
// 对于节点 1 ：反转 [2,1] ，从节点 1 出发可以到达所有节点。
// 所以 answer[1] = 1 。
// 对于节点 2 ：不需要反转就可以从节点 2 出发到达所有节点。
// 所以 answer[2] = 0 。
// 对于节点 3 ：反转 [1,3] 和 [2,1] ，从节点 3 出发可以到达所有节点。
// 所以 answer[3] = 2 。
//
//
//  示例 2：
//
//
//
//
// 输入：n = 3, edges = [[1,2],[2,0]]
// 输出：[2,0,1]
// 解释：上图表示了与输入对应的简单有向图。
// 对于节点 0 ：反转 [2,0] 和 [1,2] ，从节点 0 出发可以到达所有节点。
// 所以 answer[0] = 2 。
// 对于节点 1 ：不需要反转就可以从节点 2 出发到达所有节点。
// 所以 answer[1] = 0 。
// 对于节点 2 ：反转 [1,2] ，从节点 2 出发可以到达所有节点。
// 所以 answer[2] = 1 。
//
//
//
//
//  提示：
//
//
//  2 <= n <= 10⁵
//  edges.length == n - 1
//  edges[i].length == 2
//  0 <= ui == edges[i][0] < n
//  0 <= vi == edges[i][1] < n
//  ui != vi
//  输入保证如果边是双向边，可以得到一棵树。
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 动态规划 👍 13 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include "queue"
#include "vector"
using namespace std;

class Solution {
public:
  vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
    vector adjs(n, vector<int>{});
    vector ans(n, 0);
    for (auto iter = edges.begin(); iter != edges.end(); ++iter)
      adjs[(*iter)[0]].emplace_back(std::distance(edges.begin(), iter)),
          adjs[(*iter)[1]].emplace_back(std::distance(edges.begin(), iter));

    int cost = 0;
    using u8 = std::uint8_t;
    std::queue<int> bfs;
    std::vector<u8> vis(n, 0);
    bfs.push(0);
    vis[0] = true;
    while (not bfs.empty()) {
      auto cur = bfs.front();
      for (auto edge_index : adjs[cur]) {
        auto &edge = edges[edge_index];
        auto is_rev = (edge[1] == cur);
        auto oth = (is_rev) ? edge[0] : edge[1];
        if (vis[oth])
          continue;
        if (is_rev) {
          cost++;
          ans[oth] = ans[cur] - 1;
        } else {
          ans[oth] = ans[cur] + 1;
        }
        bfs.emplace(oth);
        vis[oth] = true;
      }
      bfs.pop();
    }
    for (auto &num : ans)
      num += cost;

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
