// 给你一个下标从 1 开始、大小为 m x n 的整数矩阵 mat，你可以选择任一单元格作为
// 起始单元格 。
//
//  从起始单元格出发，你可以移动到 同一行或同一列
//  中的任何其他单元格，但前提是目标单元格的值 严格大于 当前单元格的值。
//
//  你可以多次重复这一过程，从一个单元格移动到另一个单元格，直到无法再进行任何移动。
//
//  请你找出从某个单元开始访问矩阵所能访问的 单元格的最大数量 。
//
//  返回一个表示可访问单元格最大数量的整数。
//
//
//
//  示例 1：
//
//
//
//  输入：mat = [[3,1],[3,4]]
// 输出：2
// 解释：上图展示了从第 1 行、第 2 列的单元格开始，可以访问 2
// 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 2 个单元格，因此答案是
// 2 。
//
//
//
//  示例 2：
//
//
//
//  输入：mat = [[1,1],[1,1]]
// 输出：1
// 解释：由于目标单元格必须严格大于当前单元格，在本示例中只能访问 1 个单元格。
//
//
//  示例 3：
//
//
//
//  输入：mat = [[3,1,6],[-9,5,7]]
// 输出：4
// 解释：上图展示了从第 2 行、第 1 列的单元格开始，可以访问 4
// 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 4 个单元格，因此答案是
// 4 。
//
//
//
//
//
//  提示：
//
//
//  m == mat.length
//  n == mat[i].length
//  1 <= m, n <= 10⁵
//  1 <= m * n <= 10⁵
//  -10⁵ <= mat[i][j] <= 10⁵
//
//
//  Related Topics 记忆化搜索 数组 二分查找 动态规划 矩阵 排序 👍 25 👎 0

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
  int maxIncreasingCells(vector<vector<int>> &mat) {

  }
};
// leetcode submit region end(Prohibit modification and deletion)
