// 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个
// answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和：
//
//
//  i - k <= r <= i + k,
//  j - k <= c <= j + k 且
//  (r, c) 在矩阵内。
//
//
//
//
//  示例 1：
//
//
// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// 输出：[[12,21,16],[27,45,33],[24,39,28]]
//
//
//  示例 2：
//
//
// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// 输出：[[45,45,45],[45,45,45],[45,45,45]]
//
//
//
//
//  提示：
//
//
//  m == mat.length
//  n == mat[i].length
//  1 <= m, n, k <= 100
//  1 <= mat[i][j] <= 100
//
//
//  Related Topics 数组 矩阵 前缀和 👍 169 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)

template <typename T> class PrefixView2D {
public:
  PrefixView2D() = delete;
  explicit PrefixView2D(std::vector<std::vector<T>> &mat)
      : _prefix(mat), _m(mat.size()), _n(mat[0].size()) {
    for (int i = 0; i < _m; ++i)
      for (int j = 0; j < _n; ++j)
        _prefix[i][j] += _get(i, j - 1) + _get(i - 1, j) - _get(i - 1, j - 1);
  }
  T get_area_sum(int i1, int j1, int i2, int j2) const {
    return _get(i2, j2) + _get(i1 - 1, j1 - 1) - _get(i1 - 1, j2) -
           _get(i2, j1 - 1);
  }
  inline pair<size_t, size_t> get_dims() { return {_m, _n}; };

private:
  inline T _get(int i, int j) const {
    if (i < 0 || j < 0)
      return T();
    if (i >= _m)
      i = _m - 1;
    if (j >= _n)
      j = _n - 1;
    return _prefix[i][j];
  }
  const size_t _m, _n;
  std::vector<std::vector<T>> &_prefix;
};
class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    auto tmp = vector<vector<int>>(mat);
    auto pre = PrefixView2D(tmp);
    auto [m, n] = pre.get_dims();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        mat[i][j] = pre.get_area_sum(i - k, j - k, i + k, j + k);
    return mat;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
