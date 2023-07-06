// 存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1
// 之间的唯一编号。
//
//  给定一个二维数组 graph ，表示图，其中 graph[u] 是一个节点数组，由节点 u
//  的邻接节点组成。形式上，对于 graph[u] 中的每个 v
// ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：
//
//
//  不存在自环（graph[u] 不包含 u）。
//  不存在平行边（graph[u] 不包含重复值）。
//  如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
//  这个图可能不是连通图，也就是说两个节点 u 和 v
//  之间可能不存在一条连通彼此的路径。
//
//
//  二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B
//  ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称
// 为 二分图 。
//
//  如果图是二分图，返回 true ；否则，返回 false 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// 输出：false
// 解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。
//
//  示例 2：
//
//
//
//
// 输入：graph = [[1,3],[0,2],[1,3],[0,2]]
// 输出：true
// 解释：可以将节点分成两组: {0, 2} 和 {1, 3} 。
//
//
//
//  提示：
//
//
//  graph.length == n
//  1 <= n <= 100
//  0 <= graph[u].length < n
//  0 <= graph[u][i] <= n - 1
//  graph[u] 不会包含 u
//  graph[u] 的所有值 互不相同
//  如果 graph[u] 包含 v，那么 graph[v] 也会包含 u
//
//
//
//
//
//  注意：本题与主站 785 题相同：
//  https://leetcode-cn.com/problems/is-graph-bipartite/
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 49 👎 0

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
  o << "vector [";
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
class UnionFind {
  friend class Solution;

public:
  UnionFind() = delete;
  UnionFind(size_t n) : _n(n), _scc(n) {
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
//  cout << p1 << "@ " << p2;
  _par[p1] = p2;
  --_scc;
  return true;
}
class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    const auto n = graph.size();
    vector opp(n, -1);
    auto ufs = UnionFind(n);
    for (int from = 0; from < n; ++from)
      for (const auto to : graph[from])
        if (from < to) {
          auto p1 = ufs.find_par(from), p2 = ufs.find_par(to);
          if (p1 == p2)
            return false;
//          cout << make_tuple(p1, opp[p1], p2, opp[p2]);
          if (opp[p1] == -1)
            opp[p1] = p2;
          else
            ufs.add_link(p2, opp[p1]);
          p2 = ufs.find_par(to);
          //          p1 = ufs.find_par(from);
          if (opp[p2] == -1)
            opp[p2] = p1;
          else
            ufs.add_link(p1, opp[p2]);

//          cout << make_tuple(p1, opp[p1], p2, opp[p2]) << endl;
        }
//    cout << ufs.get_scc_n() << endl;
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
