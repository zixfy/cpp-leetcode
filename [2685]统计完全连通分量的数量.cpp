// 给你一个整数 n 。现有一个包含 n 个顶点的 无向 图，顶点按从 0 到 n - 1
// 编号。给你一个二维整数数组 edges 其中 edges[i] = [ai, bi] 表示顶点 ai 和 bi
// 之间存在一条 无向 边。
//
//  返回图中 完全连通分量 的数量。
//
//  如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为
//  连通分量 。
//
//  如果连通分量中每对节点之间都存在一条边，则称其为 完全连通分量 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// 输出：3
// 解释：如上图所示，可以看到此图所有分量都是完全连通分量。
//
//
//  示例 2：
//
//
//
//
// 输入：n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// 输出：1
// 解释：包含节点 0、1 和 2 的分量是完全连通分量，因为每对节点之间都存在一条边。
// 包含节点 3 、4 和 5 的分量不是完全连通分量，因为节点 4 和 5 之间不存在边。
// 因此，在图中完全连接分量的数量是 1 。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 50
//  0 <= edges.length <= n * (n - 1) / 2
//  edges[i].length == 2
//  0 <= ai, bi <= n - 1
//  ai != bi
//  不存在重复的边
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 👍 13 👎 0

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
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>);
template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);

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

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "[";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
  static int get_par(vector<int> &pars, int i) {
    if (pars[i] != i)
      pars[i] = get_par(pars, pars[i]);
    return pars[i];
  }
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector degrees(n, 0), sizes(n, 1), pars(n, 0);
    for (int i = 0; i < n; ++i)
      pars[i] = i;
    for (const auto &edge : edges) {
      auto u = get_par(pars, edge[0]), v = get_par(pars, edge[1]);
      ++degrees[u], ++degrees[v];
      if (u != v) {
        degrees[v] += degrees[u];
        sizes[v] += sizes[u];
        pars[u] = v;
      }
    }
    unordered_set<int> ans;
    for (int i = 0; i < n; ++i) {
      auto p = get_par(pars, i);
      auto sz = sizes[p], degs = degrees[p];
      if (sz * (sz - 1) == degs)
        ans.insert(p);
    }
      return ans.size();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
