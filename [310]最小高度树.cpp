// 树是一个无向图，其中任何两个顶点只通过一条路径连接。
// 换句话说，一个任何没有简单环路的连通图都是一棵树。
//
//  给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1
//  条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi]
//  表示树中节点 ai 和 bi 之间存在一条无向边。
//
//  可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h
//  。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度
// 树 。
//
//  请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。 树的
// 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
//
//
//
//  示例 1：
//
//
// 输入：n = 4, edges = [[1,0],[1,2],[1,3]]
// 输出：[1]
// 解释：如图所示，当根是标签为 1 的节点时，树的高度是 1
// ，这是唯一的最小高度树。
//
//  示例 2：
//
//
// 输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// 输出：[3,4]
//
//
//
//
//
//
//
//  提示：
//
//
//  1 <= n <= 2 * 10⁴
//  edges.length == n - 1
//  0 <= ai, bi < n
//  ai != bi
//  所有 (ai, bi) 互不相同
//  给定的输入 保证 是一棵树，并且 不会有重复的边
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 781 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
auto recursive_lambda = [](auto &&lam) {
  return [lam_impl = lam](auto &&...args) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector adjs(n, vector<int>{});
    for (const auto &e : edges) {
      auto u = e[0], v = e[1];
      adjs[u].emplace_back(v), adjs[v].emplace_back(u);
    }
    vector<int> ans;
    vector<int> max_hei(n, 0), max_hei2(n, 0);
    auto update_ans = [maxx = 100000, &ans](int idx, int dep) mutable {
//      cout << idx << ", " << dep << endl;
      if (dep < maxx)
        ans.clear(), maxx = dep;
      if (dep == maxx)
        ans.emplace_back(idx);
    };
    auto dfs0 = recursive_lambda(
        [&adjs, &max_hei, &max_hei2](auto &&self, int par, int cur) -> int {
          int max1 = 1, max2 = 0;
          for (auto child : adjs[cur])
            if (child != par) {
              auto nmax = self(self, cur, child) + 1;
              if (nmax >= max1)
                max2 = max1, max1 = nmax;
              else if (nmax > max2)
                max2 = nmax;
            }
          max_hei[cur] = max1, max_hei2[cur] = max2;
          return max_hei[cur];
        });
    dfs0(0, 0);
    auto dfs = recursive_lambda(
        [&update_ans, &max_hei, &max_hei2, &adjs](auto &&self, int par, int cur,
                                                  int max_par_dep) -> void {
          update_ans(cur, max(max_hei[cur], 1 + max_par_dep));
          for (auto child : adjs[cur])
            if (child != par) {
              if (max_hei[cur] == max_hei[child] + 1)
                self(self, cur, child, max(max_hei2[cur], 1 + max_par_dep));
              else
                self(self, cur, child, max(max_hei[cur], 1 + max_par_dep));
            }
        });
    dfs(0, 0, 0);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
