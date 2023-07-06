// 你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指
// 相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
//  示例：
//  输入：
//[
//   [0,2,1,0],
//   [0,1,0,1],
//   [1,1,0,1],
//   [0,1,0,1]
//]
// 输出： [1,2,4]
//
//  提示：
//
//  0 < len(land) <= 1000
//  0 < len(land[i]) <= 1000
//
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 93 👎 0

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
constexpr auto dirs() {
  array<pair<int, int>, 8> ans{{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
//  int idx = 0;
//  for (int i = -1; i < 2; ++i)
//    for (int j = -1; j < 2; ++j)
//      if (i || j)
//        ans[idx++] = make_pair(i, j);
  return ans;
}
constexpr auto VISITED = 1;
class Solution {
public:
  vector<int> pondSizes(vector<vector<int>> &land) {
    multiset<int> ans;
    queue<pair<int, int>> q;
    const auto [m, n] = make_pair(land.size(), land[0].size());
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (land[i][j])
          continue;
        land[i][j] = VISITED;
        int cnt = 0;
        q.emplace(i, j);
        while (!q.empty()) {
          auto [x, y] = q.front();
          ++cnt;
          for (auto [dx, dy] : dirs()) {
            auto nx = x + dx, ny = y + dy;
            if (nx > -1 && nx < m && ny > -1 && ny < n && land[nx][ny] == 0)
              land[nx][ny]  = VISITED, q.emplace(nx, ny);
          }
          q.pop();
        }
        ans.emplace(cnt);
      }

    return {ans.begin(), ans.end()};
  }
};
// leetcode submit region end(Prohibit modification and deletion)
