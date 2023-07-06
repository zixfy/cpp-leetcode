// 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径
// 的长度。如果不存在这样的路径，返回 -1 。
//
//  二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角
//  单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求
// ：
//
//
//  路径途经的所有单元格都的值都是 0 。
//  路径中所有相邻的单元格应当在 8 个方向之一
//  上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
//
//
//  畅通路径的长度 是该路径途经的单元格总数。
//
//
//
//  示例 1：
//
//
// 输入：grid = [[0,1],[1,0]]
// 输出：2
//
//
//  示例 2：
//
//
// 输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
// 输出：4
//
//
//  示例 3：
//
//
// 输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
// 输出：-1
//
//
//
//
//  提示：
//
//
//  n == grid.length
//  n == grid[i].length
//  1 <= n <= 100
//  grid[i][j] 为 0 或 1
//
//
//  Related Topics 广度优先搜索 数组 矩阵 👍 292 👎 0

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
namespace std {
namespace {

template <class T> inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// Recursive template code derived from Matthieu M.
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  static void apply(size_t &seed, Tuple const &tuple) {
    HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
    hash_combine(seed, get<Index>(tuple));
  }
};

template <class Tuple> struct HashValueImpl<Tuple, 0> {
  static void apply(size_t &seed, Tuple const &tuple) {
    hash_combine(seed, get<0>(tuple));
  }
};
} // namespace

template <typename... TT> struct hash<std::tuple<TT...>> {
  size_t operator()(std::tuple<TT...> const &tt) const {
    size_t seed = 0;
    HashValueImpl<std::tuple<TT...>>::apply(seed, tt);
    return seed;
  }
};
template <typename U, typename V> struct hash<std::pair<U, V>> {
  size_t operator()(std::pair<U, V> const &tt) const {
    size_t seed = 0;
    hash_combine(seed, tt.first);
    hash_combine(seed, tt.second);
    return seed;
  }
};

} // namespace std
using xy = pair<int, int>;
constexpr array<xy, 8> eight_dirs{
    {{1, 0}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {-1, -1}, {0, -1}, {1, -1}}};
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0] == 1)
      return -1;
    const auto n = grid.size();
    unordered_set<xy> vis;
    queue<xy> q;
    q.emplace(0, 0);
    vis.emplace(0, 0);
    int ans = 1;
    while (!q.empty()) {
      auto q_size = q.size();
      for (int i = 0; i < q_size; ++i) {
        auto [x, y] = q.front();
//        cout << x << ", " << y << endl;
        if (x == n - 1 && y == n - 1)
          return ans;
        for (const auto [dx, dy] : eight_dirs) {
          auto nx = dx + x, ny = dy + y;
          if (nx > -1 && ny > -1 && nx < n && ny < n && grid[nx][ny] == 0)
            if (auto nxt_pos = make_pair(nx, ny); !vis.count(nxt_pos))
              vis.emplace(nxt_pos), q.emplace(nxt_pos);
        }
        q.pop();
      }
      ++ans;
    }

    return -1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
