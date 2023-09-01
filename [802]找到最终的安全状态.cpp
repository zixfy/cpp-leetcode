// 有一个有 n 个节点的有向图，节点按 0 到 n - 1 编号。图由一个 索引从 0 开始 的
// 2D 整数数组 graph表示， graph[i]是与节点 i
// 相邻的节点的整数数组，这意味着从节点 i 到 graph[i]中的每个节点都有一条边。
//
//  如果一个节点没有连出的有向边，则该节点是 终端节点
//  。如果从该节点开始的所有可能路径都通向 终端节点 ，则该节点为 安全节点 。
//
//  返回一个由图中所有 安全节点 组成的数组作为答案。答案数组中的元素应当按 升序
//  排列。
//
//
//
//  示例 1：
//
//
//
//
// 输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// 输出：[2,4,5,6]
// 解释：示意图如上。
// 节点 5 和节点 6 是终端节点，因为它们都没有出边。
// 从节点 2、4、5 和 6 开始的所有路径都指向节点 5 或 6 。
//
//
//  示例 2：
//
//
// 输入：graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// 输出：[4]
// 解释:
// 只有节点 4 是终端节点，从节点 4 开始的所有路径都通向节点 4 。
//
//
//
//
//  提示：
//
//
//  n == graph.length
//  1 <= n <= 10⁴
//  0 <= graph[i].length <= n
//  0 <= graph[i][j] <= n - 1
//  graph[i] 按严格递增顺序排列。
//  图中可能包含自环。
//  图中边的数目在范围 [1, 4 * 10⁴] 内。
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 404 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using std::vector;
/*
 * a
 */
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    auto n = graph.size();
    vector rgraph(n, vector<int>{});
    vector in_degs(n, 0);
    std::transform(graph.begin(), graph.end(), in_degs.begin(),
                   [](auto const &edges) { return edges.size(); });

    for (int i = 0; i < n; ++i)
      for (auto to : graph[i])
        rgraph[to].emplace_back(i);

    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (in_degs[i] == 0)
        ans.emplace_back(i);
    for (int i = 0; i < ans.size(); ++i) {
      for (auto to : rgraph[ans[i]])
        if (--in_degs[to] == 0)
          ans.emplace_back(to);
    }
    std::sort(ans.begin(), ans.end());
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
