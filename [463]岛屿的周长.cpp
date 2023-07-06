// 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地，
// grid[i][j] = 0 表示水域。
//
//  网格中的格子 水平和垂直
//  方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
//
//  岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为
//  1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿
// 的周长。
//
//
//
//  示例 1：
//
//
//
//
// 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// 输出：16
// 解释：它的周长是上面图片中的 16 个黄色的边
//
//  示例 2：
//
//
// 输入：grid = [[1]]
// 输出：4
//
//
//  示例 3：
//
//
// 输入：grid = [[1,0]]
// 输出：4
//
//
//
//
//  提示：
//
//
//  row == grid.length
//  col == grid[i].length
//  1 <= row, col <= 100
//  grid[i][j] 为 0 或 1
//
//
//  Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 662 👎 0

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

#include <bits/stdc++.h>
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

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U>
std::ostream &operator<<(std::ostream &o, std::unordered_set<U> p) {
  o << "map {";
  for (const auto &a : p)
    o << a << ", ";
  return o << "}\n";
}
constexpr array<pair<int, int>, 4> dirs{{{0, -1}, {0, 1}, {1, 0}, {-1, 0}}};
class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    const auto [m, n] = make_pair(grid.size(), grid[0].size());
    int x, y;
    for (x = 0, y = 0; grid[x][y] != 1;)
      if (++y == n)
        y = 0, ++x;
    int ans = 0;
    unordered_set<pair<int, int>> vis;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    while (!q.empty()) {
      auto [x, y] = q.front();
      if (const auto &pos = q.front(); !vis.count(pos)) {
        ans += 4, vis.emplace(pos);
        for (const auto [dx, dy] : dirs) {
          auto nx = x + dx, ny = y + dy;
          if (nx > -1 && ny > -1 && nx < m && ny < n && grid[nx][ny] == 1) {
//            cout << vis << endl;
//            cout << make_pair(nx, ny) << endl << endl;
            if (auto nxt_pos = make_pair(nx, ny); !vis.count(nxt_pos)) {
              q.emplace(nxt_pos);
            } else
              ans -= 2;
            //          cout << ans << endl;
          }
        }
      }
      q.pop();
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
