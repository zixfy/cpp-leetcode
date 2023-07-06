// Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3 种类型的边：
//
//
//  类型 1：只能由 Alice 遍历。
//  类型 2：只能由 Bob 遍历。
//  类型 3：Alice 和 Bob 都可以遍历。
//
//
//  给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi
//  之间存在类型为 typei 的双向边。请
// 你在保证图仍能够被 Alice和 Bob
// 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob
// 都可以到达所有其他节点，则认为图 是可以完全遍历的。
//
//  返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。
//
//
//
//  示例 1：
//
//
//
//  输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// 输出：2
// 解释：如果删除 [1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob
// 仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所
// 以可以删除的最大边数是 2 。
//
//
//  示例 2：
//
//
//
//  输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// 输出：0
// 解释：注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
//
//
//  示例 3：
//
//
//
//  输入：n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// 输出：-1
// 解释：在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob 也不能达到节点
// 1 。因此，图无法完全遍历。
//
//
//
//  提示：
//
//
//  1 <= n <= 10^5
//  1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
//  edges[i].length == 3
//  1 <= edges[i][0] <= 3
//  1 <= edges[i][1] < edges[i][2] <= n
//  所有元组 (typei, ui, vi) 互不相同
//
//
//  Related Topics 并查集 图 👍 150 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)

class UnionFind {
public:
  UnionFind() = delete;
  UnionFind(size_t n) : _n(n) , _scc(n){
    _par.reserve(_n);
    for (auto i = 0; i < _n; ++i)
      _par.push_back(i);
  };
  bool add_link(int a, int b);
  inline int get_scc_n() { return _scc; }

private:
  int find_par(int);
  size_t _n, _scc;
  vector<int> _par;
};

int UnionFind::find_par(int x) {
  if (_par[x] != x)
    _par[x] = find_par(_par[x]);
  return _par[x];
}
bool UnionFind::add_link(int a, int b) {
  auto p1 = find_par(a), p2 = find_par(b);
  if (p1 == p2)
    return false;
  _par[p1] = p2;
  --_scc;
  return true;
}
class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
    int ans = 0;
    auto uf_a = UnionFind(n), uf_b = UnionFind(n);
    for (const auto &e : edges) {
      int t = e[0], u = e[1] - 1, v = e[2]-1;
      if (t == 3 && ((!uf_a.add_link(u, v)) & (!uf_b.add_link(u, v))))
        ++ans;
    }
    for (const auto &e : edges) {
      int t = e[0], u = e[1] - 1, v = e[2]-1;
      if (t == 1 && !uf_a.add_link(u, v))
        ++ans;
      if (t == 2 && !uf_b.add_link(u, v))
        ++ans;
    }

//    cout << ans;
    return (uf_a.get_scc_n() == 1 && uf_b.get_scc_n() == 1) ? ans: -1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
