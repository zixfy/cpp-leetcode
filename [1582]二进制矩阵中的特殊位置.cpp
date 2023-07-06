// 给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵
// mat 中特殊位置的数目 。
//
//  特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j 列中的所有其他元素均为
//  0（行和列的下标均 从 0 开始 ），则位置 (i,
// j) 被称为特殊位置。
//
//
//
//  示例 1：
//
//  输入：mat = [[1,0,0],
//             [0,0,1],
//             [1,0,0]]
// 输出：1
// 解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1
// 且所处的行和列上所有其他元素都是 0
//
//
//  示例 2：
//
//  输入：mat = [[1,0,0],
//             [0,1,0],
//             [0,0,1]]
// 输出：3
// 解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
//
//
//  示例 3：
//
//  输入：mat = [[0,0,0,1],
//             [1,0,0,0],
//             [0,1,1,0],
//             [0,0,0,0]]
// 输出：2
//
//
//  示例 4：
//
//  输入：mat = [[0,0,0,0,0],
//             [1,0,0,0,0],
//             [0,1,0,0,0],
//             [0,0,1,0,0],
//             [0,0,0,1,1]]
// 输出：3
//
//
//
//
//  提示：
//
//
//  rows == mat.length
//  cols == mat[i].length
//  1 <= rows, cols <= 100
//  mat[i][j] 是 0 或 1
//
//
//  Related Topics 数组 矩阵 👍 98 👎 0

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
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    const auto [m, n] = make_pair(mat.size(), mat[0].size());
    vector row_one_idx(m, -2), col_one_idx(n, -2);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]==0)
          continue ;
        if (auto &roi = row_one_idx[i]; roi == -2)
          row_one_idx[i] = j;
        else if (roi > -1)
          roi = -1;
        if (auto &coi = col_one_idx[j]; coi == -2)
          col_one_idx[j] = i;
        else if (coi > -1)
          coi = -1;
      }
//    cout << row_one_idx << endl << col_one_idx;
    int ans = 0;
    for (int i = 0; i < m; ++i)
      if (auto j = row_one_idx[i]; j > -1)
        if (col_one_idx[j] == i)
          ++ans;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
