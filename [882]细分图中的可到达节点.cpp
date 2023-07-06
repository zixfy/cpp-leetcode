// 给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1
// 。你决定将图中的每条边 细分 为一条节点链，每条边之间的新节点数各不相同。
//
//  图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti]
//  表示原始图中节点 ui 和 vi 之间存在一条边，
// cnti 是将边 细分 后的新节点总数。注意，cnti == 0 表示边不可细分。
//
//  要 细分 边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti
//  个新节点。新节点为 x1, x2, ..., xcnti ，
// 新边为 [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi] 。
//
//  现在得到一个 新的细分图 ，请你计算从节点 0
//  出发，可以到达多少个节点？如果节点间距离是 maxMoves 或更少，则视为 可以到达
//  。
//
//  给你原始图和 maxMoves ，返回 新的细分图中从节点 0 出发 可到达的节点数 。
//
//
//
//  示例 1：
//
//
// 输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
// 输出：13
// 解释：边的细分情况如上图所示。
// 可以到达的节点已经用黄色标注出来。
//
//
//  示例 2：
//
//
// 输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
// 输出：23
//
//
//  示例 3：
//
//
// 输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
// 输出：1
// 解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
//
//
//
//
//  提示：
//
//
//  0 <= edges.length <= min(n * (n - 1) / 2, 10⁴)
//  edges[i].length == 3
//  0 <= ui < vi < n
//  图中 不存在平行边
//  0 <= cnti <= 10⁴
//  0 <= maxMoves <= 10⁹
//  1 <= n <= 3000
//
//
//  Related Topics 图 最短路 堆（优先队列） 👍 153 👎 0

#include "bits/stdc++.h"
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
struct Edge {
  int u, v, d;
  int u2v;
  int v2u;
  pair<int, int> try_reach(int from, int move) {
    int gain = 0;
    if (from == u && u2v < move) {
      gain += max(0, min(d - v2u, move) - u2v);
      u2v = move;
    }
    if (from == v && v2u < move) {
      gain += max(0, min(d - u2v, move) - v2u);
      v2u = move;
    }
    return {move - 1 - d, gain};
  }
  inline int get_oth(int from) { return from == u ? v : u; }
};
struct f {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
  }
};
class Solution {
public:
  int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
    int ans = 0;
    unordered_map<int, int> vis_nodes{{0, maxMoves}};
    priority_queue<pair<int, int>, vector<pair<int, int>>, f> q;
    vector<vector<Edge *>> grained_edges(n);
    for (const auto &e : edges) {
      auto p_edge = new Edge{e[0], e[1], e[2], 0, 0};
      grained_edges[p_edge->u].push_back(p_edge);
      grained_edges[p_edge->v].push_back(p_edge);
    }
    q.emplace(0, maxMoves);
    while (!q.empty()) {
      auto [cur, move] = q.top();
      for (auto e : grained_edges[cur]) {
        auto oth = e->get_oth(cur);
        auto [new_move, gain] = e->try_reach(cur, move);
        ans += gain;
        if (new_move >= 0 && (!vis_nodes.count(oth) || new_move > vis_nodes[oth]))
          vis_nodes[oth] = new_move, q.emplace(oth, new_move);
      }
      q.pop();
    }
    return ans + vis_nodes.size();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
