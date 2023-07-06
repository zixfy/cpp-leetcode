// 这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1
// 表示单元格上有服务器，0 表示没有。
//
//  如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。
//
//  请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。
//
//
//
//  示例 1：
//
//
//
//  输入：grid = [[1,0],[0,1]]
// 输出：0
// 解释：没有一台服务器能与其他服务器进行通信。
//
//  示例 2：
//
//
//
//  输入：grid = [[1,0],[1,1]]
// 输出：3
// 解释：所有这些服务器都至少可以与一台别的服务器进行通信。
//
//
//  示例 3：
//
//
//
//  输入：grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
// 输出：4
// 解释：第一行的两台服务器互相通信，第三列的两台服务器互相通信，但右下角的服务器无法与其他服务器通信。
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  1 <= m <= 250
//  1 <= n <= 250
//  grid[i][j] == 0 or 1
//
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 数组 计数 矩阵 👍 57 👎 0

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
  int countServers(vector<vector<int>> &grid) {
    const auto [m, n] = make_pair(grid.size(), grid[0].size());
    auto ufs = UnionFind(n);
    vector row_cnt(m, 0), col_cnt(n, 0);
    int cnt = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; ++j) {
        auto g = grid[i][j];
        cnt += g;
        row_cnt[i] += g, col_cnt[j] += g;
      }
    int ans = 0;
    for (int i = 0; i < m; i++)
      if (row_cnt[i] == 1)
        for (int j = 0; j < n; ++j)
          if (col_cnt[j] == 1 && grid[i][j] == 1)
            ++ans;
    return cnt - ans;
    //    return n - ufs.get_scc_n()
  }
};
// leetcode submit region end(Prohibit modification and deletion)
