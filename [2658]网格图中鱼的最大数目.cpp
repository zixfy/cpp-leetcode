// 给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，其中下标在 (r, c)
// 处的整数表示：
//
//
//  如果 grid[r][c] = 0 ，那么它是一块 陆地 。
//  如果 grid[r][c] > 0 ，那么它是一块 水域 ，且包含 grid[r][c] 条鱼。
//
//
//  一位渔夫可以从任意 水域 格子 (r, c) 出发，然后执行以下操作任意次：
//
//
//  捕捞格子 (r, c) 处所有的鱼，或者
//  移动到相邻的 水域 格子。
//
//
//  请你返回渔夫最优策略下， 最多 可以捕捞多少条鱼。如果没有水域格子，请你返回 0
//  。
//
//  格子 (r, c) 相邻 的格子为 (r, c + 1) ，(r, c - 1) ，(r + 1, c) 和 (r - 1, c)
//  ，前提是相邻格子在网格
// 图内。
//
//
//
//  示例 1：
//
//
//
//  输入：grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// 输出：7
// 解释：渔夫可以从格子 (1,3) 出发，捕捞 3 条鱼，然后移动到格子 (2,3) ，捕捞 4
// 条鱼。
//
//
//  示例 2：
//
//
//
//  输入：grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
// 输出：1
// 解释：渔夫可以从格子 (0,0) 或者 (3,3) ，捕捞 1 条鱼。
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 10
//  0 <= grid[i][j] <= 10
//
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 7 👎 0

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



template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)

class UnionFind {
public:
  UnionFind() = delete;
  UnionFind(size_t n) : _n(n), _scc(n) {
    _par.reserve(_n);
    for (auto i = 0; i < _n; ++i)
      _par.push_back(i);
  };
  bool add_link(int a, int b);
  inline int get_scc_n() { return _scc; }
friend class Solution;
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
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  int findMaxFish(vector<vector<int>> &grid) {
    auto [m, n] = make_pair(grid.size(), grid[0].size());
    auto mn = m * n;
    auto ufs = UnionFind(mn);
    vector ans(mn, 0);
    for (auto idx = 0, i = 0, j = 0; idx < mn; ++idx, ++j) {
      if (j == n)
        ++i, j = 0;
      ans[idx] = grid[i][j];
    }
//    cout << "hrere";
//    cout << ans << endl;
    for (auto idx = 0, i = 0, j = 0; idx < mn; ++idx, ++j) {
      if (j == n)
        ++i, j = 0;
      if (ans[idx])
      for (auto [x, y] : initializer_list<pair<int, int>>{
               {i + 1, j}, {i, j + 1}, {i - 1, j}, {i, j - 1}})
        if (x > -1 && y > -1 && x < m && y < n && grid[x][y])
          if (int jpar = ufs.find_par(x * n + y); ufs.add_link(jpar, idx))
            ans[ufs.find_par(idx)] += ans[jpar];
    }
//    cout << ans << endl;
    return *max_element(ans.begin(), ans.end());
  }
};
// leetcode submit region end(Prohibit modification and deletion)
