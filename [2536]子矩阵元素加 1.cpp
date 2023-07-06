// 给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩阵 mat
// ，矩阵中填满了 0 。
//
//  另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i,
//  col2i] ，请你执行下述操作：
//
//
//
//  找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i)
//  的子矩阵，将子矩阵中的 每个元素 加 1 。也就是给所有满足 row1i <= x <= row2i
//  和 col1i <= y <= col2i 的 mat[x][y] 加 1 。
//
//
//  返回执行完所有操作后得到的矩阵 mat 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 3, queries = [[1,1,2,2],[0,0,1,1]]
// 输出：[[1,1,0],[1,2,1],[0,1,1]]
// 解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后的矩阵。
//- 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。
//- 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。
//
//
//  示例 2：
//
//
//
//
// 输入：n = 2, queries = [[0,0,1,1]]
// 输出：[[1,1],[1,1]]
// 解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。
//- 第一个操作：将矩阵中的每个元素加 1 。
//
//
//
//  提示：
//
//
//  1 <= n <= 500
//  1 <= queries.length <= 10⁴
//  0 <= row1i <= row2i < n
//  0 <= col1i <= col2i < n
//
//
//  Related Topics 数组 矩阵 前缀和 👍 34 👎 0

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
class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    vector ans(n, vector(n, 0));
    for (const auto &q : queries) {
      auto r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
      for (int r = r1; r <= r2; ++r)
        ans[r][c1]++;
      if (c2 == n - 1)
        for (int r = r1 + 1, re = min(n - 1, r2 + 1); r <= re; ++r)
          ans[r][0]--;
      else
        for (int r = r1; r <= r2; ++r)
          ans[r][c2 + 1]--;
    }
    int pre = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ans[i][j] = (pre += ans[i][j]);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
