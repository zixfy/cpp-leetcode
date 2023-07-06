// 给你一个由 n 个节点（下标从 0
// 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 edges[i] = [a, b]
// 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 succProb[i] 。
//
//  指定两个节点分别作为起点 start 和终点 end
//  ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。
//
//  如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过
//  1e-5 ，就会被视作正确答案。
//
//
//
//  示例 1：
//
//
//
//  输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
//  0,
// end = 2
// 输出：0.25000
// 解释：从起点到终点有两条路径，其中一条的成功概率为 0.2 ，而另一条为 0.5 * 0.5
// = 0.25
//
//
//  示例 2：
//
//
//
//  输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
//  0,
// end = 2
// 输出：0.30000
//
//
//  示例 3：
//
//
//
//  输入：n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// 输出：0.00000
// 解释：节点 0 和 节点 2 之间不存在路径
//
//
//
//
//  提示：
//
//
//  2 <= n <= 10^4
//  0 <= start, end < n
//  start != end
//  0 <= a, b < n
//  a != b
//  0 <= succProb.length == edges.length <= 2*10^4
//  0 <= succProb[i] <= 1
//  每两个节点之间最多有一条边
//
//
//  Related Topics 图 数组 最短路 堆（优先队列） 👍 124 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}
class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {

    using node = pair<int, double>;
    using edge = pair<int, double>;
    auto f = [](const node &a, const node &b) { return a.second < b.second; };
    std::priority_queue<node, std::vector<node>, decltype(f)> pq(f);

    pq.emplace(start, 1.);
    vector<vector<edge>> adjs(n);
    for (auto i = 0; i < succProb.size(); ++i)
      adjs[edges[i][0]].emplace_back(edges[i][1], succProb[i]),
          adjs[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    unordered_map<int, double> dist{{start, .0}};
    while (!pq.empty()) {
      auto [cur, prob] = pq.top();
      pq.pop();
      if (cur == end)
        return prob;
      if (dist[cur] > prob)
        continue;
      else
        dist[cur] = prob;
      for (auto [to, p] : adjs[cur])
        if (prob * p > dist[to])
          pq.emplace(to, prob * p);
    }
    //    cout << dist << endl;
    return .0;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
