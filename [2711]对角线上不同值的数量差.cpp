// 给你一个下标从 0 开始、大小为 m x n 的二维矩阵 grid ，请你求解大小同样为 m x
// n 的答案矩阵 answer 。
//
//  矩阵 answer 中每个单元格 (r, c) 的值可以按下述方式进行计算：
//
//
//  令 topLeft[r][c] 为矩阵 grid 中单元格 (r, c) 左上角对角线上 不同值 的数量。
//  令 bottomRight[r][c] 为矩阵 grid 中单元格 (r, c) 右下角对角线上 不同值
//  的数量。
//
//
//  然后 answer[r][c] = |topLeft[r][c] - bottomRight[r][c]| 。
//
//  返回矩阵 answer 。
//
//  矩阵对角线
//  是从最顶行或最左列的某个单元格开始，向右下方向走到矩阵末尾的对角线。
//
//  如果单元格 (r1, c1) 和单元格 (r, c) 属于同一条对角线且 r1 < r ，则单元格
//  (r1, c1) 属于单元格 (r, c) 的左上对角
// 线。类似地，可以定义右下对角线。
//
//
//
//  示例 1：
//
//
// 输入：grid = [[1,2,3],[3,1,5],[3,2,1]]
// 输出：[[1,1,0],[1,0,1],[0,1,1]]
// 解释：第 1 个图表示最初的矩阵 grid 。 
// 第 2 个图表示对单元格 (0,0) 计算，其中蓝色单元格是位于右下对角线的单元格。
// 第 3 个图表示对单元格 (1,2) 计算，其中红色单元格是位于左上对角线的单元格。
// 第 4 个图表示对单元格 (1,1)
// 计算，其中蓝色单元格是位于右下对角线的单元格，红色单元格是位于左上对角线的单元格。
//- 单元格 (0,0) 的右下对角线包含 [1,1] ，而左上对角线包含 [] 。对应答案是 |1 -
// 0| = 1 。
//- 单元格 (1,2) 的右下对角线包含 [] ，而左上对角线包含 [2] 。对应答案是 |0 - 1|
//= 1 。
//- 单元格 (1,1) 的右下对角线包含 [1] ，而左上对角线包含 [1] 。对应答案是 |1 -
// 1| = 0 。 其他单元格的对应答案也可以按照这样的流程进行计算。
//
//
//  示例 2：
//
//
// 输入：grid = [[1]]
// 输出：[[0]]
// 解释：- 单元格 (0,0) 的右下对角线包含 [] ，左上对角线包含 [] 。对应答案是 |0
// - 0| = 0 。
//
//
//
//
//  提示：
//
//
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n, grid[i][j] <= 50
//
//
//  Related Topics 数组 哈希表 矩阵 👍 8 👎 0

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
  vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
    const auto m = grid.size(), n = grid[0].size();
    auto f = [&grid, m, n](int i, int j) {
      auto k = min(m - i, n - j)
    };
    for (int k = 0, eye_n = m + n - 1; k < eye_n; ++k) {
      for (int i = min(k, int(m - 1)), j = k - i; i >= 0 && j < n; i--, j++)
        cout << grid[i][j] << ", ";
      cout << endl;
    }
    return {};
  }
};
// leetcode submit region end(Prohibit modification and deletion)
