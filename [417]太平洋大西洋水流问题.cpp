// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋”
// 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
//
//  这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵
//  heights ， heights[r][c] 表示坐标 (r, c) 上
// 单元格 高于海平面的高度 。
//
//  岛上雨水较多，如果相邻单元格的高度 小于或等于
//  当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
//
//  返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格
//  (ri, ci) 流动 既可流向太平洋也可
// 流向大西洋 。
//
//
//
//  示例 1：
//
//
//
//
// 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
//
//
//  示例 2：
//
//
// 输入: heights = [[2,1],[1,2]]
// 输出: [[0,0],[0,1],[1,0],[1,1]]
//
//
//
//
//  提示：
//
//
//  m == heights.length
//  n == heights[r].length
//  1 <= m, n <= 200
//  0 <= heights[r][c] <= 10⁵
//
//
//  Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 601 👎 0

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

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    unordered_set<pair<int, int>> vis1, vis2;
    constexpr array<pair<int, int>, 4> dirs{{{0, -1}, {0, 1}, {1, 0}, {-1, 0}}};
    const auto [m, n] = make_pair(heights.size(), heights[0].size());
    for (int i = 0; i < m; ++i)
      vis1.emplace(i, 0), vis2.emplace(i, n - 1);
    for (int j = 0; j < n; ++j)
      vis1.emplace(0, j), vis2.emplace(m - 1, j);
    queue<pair<int, int>> q1, q2;
    for (const auto &p : vis1)
      q1.emplace(p);
    for (const auto &p : vis2)
      q2.emplace(p);
    while (!q1.empty()) {
      const auto &cur = q1.front();
      for (const auto [dx, dy] : dirs) {
        auto nx = cur.first + dx, ny = cur.second + dy;
        if (nx > -1 && ny > -1 && nx < m && ny < n &&
            heights[nx][ny] >= heights[cur.first][cur.second] &&
            vis1.count(make_pair(nx, ny)) == 0) {
          vis1.emplace(nx, ny);
          q1.emplace(nx, ny);
        }
      }
      q1.pop();
    }

    vector<vector<int>> ans;

    while (!q2.empty()) {
      const auto &cur = q2.front();
      if (vis1.count(cur))
        ans.emplace_back(initializer_list<int>{cur.first, cur.second});
      for (const auto [dx, dy] : dirs) {
        auto nx = cur.first + dx, ny = cur.second + dy;
        if (nx > -1 && ny > -1 && nx < m && ny < n &&
            heights[nx][ny] >= heights[cur.first][cur.second] &&
            vis2.count(make_pair(nx, ny)) == 0) {
          vis2.emplace(nx, ny);
          q2.emplace(nx, ny);
        }
      }
      q2.pop();
    }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
