// 给你一个 m x n 的矩阵 matrix ，请你返回一个新的矩阵 answer ，其中
// answer[row][col] 是 matrix[row][ col] 的秩。
//
//  每个元素的 秩
//  是一个整数，表示这个元素相对于其他元素的大小关系，它按照如下规则计算：
//
//
//  秩是从 1 开始的一个整数。
//  如果两个元素 p 和 q 在 同一行 或者 同一列 ，那么：
//
//  如果 p < q ，那么 rank(p) < rank(q)
//  如果 p == q ，那么 rank(p) == rank(q)
//  如果 p > q ，那么 rank(p) > rank(q)
//
//  秩 需要越 小 越好。
//
//
//  题目保证按照上面规则 answer 数组是唯一的。
//
//
//
//  示例 1：
//
//
// 输入：matrix = [[1,2],[3,4]]
// 输出：[[1,2],[2,3]]
// 解释：
// matrix[0][0] 的秩为 1 ，因为它是所在行和列的最小整数。
// matrix[0][1] 的秩为 2 ，因为 matrix[0][1] > matrix[0][0] 且 matrix[0][0]
// 的秩为 1 。 matrix[1][0] 的秩为 2 ，因为 matrix[1][0] > matrix[0][0] 且
// matrix[0][0] 的秩为 1 。 matrix[1][1] 的秩为 3 ，因为 matrix[1][1] >
// matrix[0][1]， matrix[1][1] > matrix[1][0 ] 且 matrix[0][1] 和 matrix[1][0]
// 的秩都为 2 。
//
//
//  示例 2：
//
//
// 输入：matrix = [[7,7],[7,7]]
// 输出：[[1,1],[1,1]]
//
//
//  示例 3：
//
//
// 输入：matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
// 输出：[[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
//
//
//  示例 4：
//
//
// 输入：matrix = [[7,3,6],[1,4,5],[9,8,2]]
// 输出：[[5,1,4],[1,2,3],[6,3,1]]
//
//
//
//
//  提示：
//
//
//  m == matrix.length
//  n == matrix[i].length
//  1 <= m, n <= 500
//  -10⁹ <= matrix[row][col] <= 10⁹
//
//
//  Related Topics 贪心 并查集 图 拓扑排序 数组 矩阵 👍 140 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "[";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
vector<int> topical_sort(const vector<vector<int>> &adjs) {
  const auto n = adjs.size();
  vector<int> in_deg(n, 0);
  for (const auto &tos : adjs)
    for (auto to : tos)
      in_deg[to]++;
  queue<int> q;
  for (int i = 0; i < n; ++i)
    if (in_deg[i] == 0)
      q.push(i);
  vector<int> ans;
  ans.reserve(n);
  while (!q.empty()) {
    auto cur = q.front();
    ans.push_back(cur);
    for (auto to : adjs[cur])
      if (--in_deg[to] == 0)
        q.push(to);
    q.pop();
  }
  return ans;
}

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

class Solution {
public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    const auto [m, n] = make_pair(matrix.size(), matrix[0].size());
    vector ans(m, vector<int>(n, 0));
    auto mn = m * n;
    auto ufs = UnionFind(mn);
    vector<int> tmp, tmp2;
    tmp.reserve(n), tmp2.reserve(m);
    generate_n(back_inserter(tmp), n, [i = 0]() mutable { return i++; });
    generate_n(back_inserter(tmp2), m, [i = 0]() mutable { return i++; });
    vector<vector<int>> adjs(mn);
    for (int i = 0, flat = 0; i < m; i++, flat += n) {
      const auto &row = matrix[i];
      auto col_idx = tmp;
      std::sort(col_idx.begin(), col_idx.end(),
                [&row](const int &a, const int &b) { return row[a] < row[b]; });
      for (int j = 0; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          auto u = flat + col_idx[j], v = flat + col_idx[k];
          adjs[u].emplace_back(v);
          if (row[col_idx[j]] == row[col_idx[k]])
            ufs.add_link(u, v);
        }
    }
    for (int j = 0; j < n; j++) {
      auto row_idx = tmp2;
      std::sort(row_idx.begin(), row_idx.end(),
                [&matrix, j](const int &a, const int &b) {
                  return matrix[a][j] < matrix[b][j];
                });
      for (int i = 0; i < m; ++i)
        for (int k = i + 1; k < m; ++k) {
          auto u = j + row_idx[i] * n, v = j + row_idx[k] * n;
          adjs[u].emplace_back(v);
          if (matrix[row_idx[i]][j] == matrix[row_idx[k]][j])
            ufs.add_link(u, v);
        }
    }
    //    cout << adjs << endl;

    vector<int> maxx(mn, 0);
    vector<int> in_deg(mn, 0);
    for (const auto &tos : adjs)
      for (auto to : tos)
        in_deg[to]++;
    queue<int> q;
    for (int i = 0; i < mn; ++i)
      if (in_deg[i] == 0)
        q.push(i), maxx[ufs.find_par(i)] = 1;
    while (!q.empty()) {
      auto cur = q.front();
      auto x = cur / n, y = cur % n;
      for (auto to : adjs[cur]) {
        auto nx = to / n, ny = to % n;
        auto nxt_rank =
            maxx[ufs.find_par(cur)] + (matrix[x][y] != matrix[nx][ny]);
        maxx[ufs.find_par(to)] = max(maxx[ufs.find_par(to)], nxt_rank);
        if (--in_deg[to] == 0)
          q.push(to);
      }
      q.pop();
    }
    //    cout << "hi";
    for (int i = 0, j = 0, flat = 0; flat < mn; ++j, ++flat) {
      if (j == n)
        j = 0, ++i;
      ans[i][j] = maxx[ufs.find_par(flat)];
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
