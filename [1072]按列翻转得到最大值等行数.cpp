// 给定 m x n 矩阵 matrix 。
//
//  你可以从中选出任意数量的列并翻转其上的 每个 单元格。（即翻转后，单元格的值从
//  0 变成 1，或者从 1 变为 0 。）
//
//  返回 经过一些翻转后，行与行之间所有值都相等的最大行数 。
//
//
//
//
//
//
//  示例 1：
//
//
// 输入：matrix = [[0,1],[1,1]]
// 输出：1
// 解释：不进行翻转，有 1 行所有值都相等。
//
//
//  示例 2：
//
//
// 输入：matrix = [[0,1],[1,0]]
// 输出：2
// 解释：翻转第一列的值之后，这两行都由相等的值组成。
//
//
//  示例 3：
//
//
// 输入：matrix = [[0,0,0],[0,0,1],[1,1,0]]
// 输出：2
// 解释：翻转前两列的值之后，后两行由相等的值组成。
//
//
//
//  提示：
//
//
//  m == matrix.length
//  n == matrix[i].length
//  1 <= m, n <= 300
//  matrix[i][j] == 0 或 1
//
//
//  Related Topics 数组 哈希表 矩阵 👍 68 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
#include <iterator>

class Range {
public:
  class iterator {
  public:
    iterator(int current) : current(current) {}

    int operator*() const { return current; }

    iterator &operator++() {
      ++current;
      return *this;
    }

    bool operator!=(const iterator &other) const {
      return current != other.current;
    }

  private:
    int current;
  };

  Range(int begin, int end) : begin_(begin), end_(end) {}

  Range(int end) : begin_(0), end_(end) {}
  iterator begin() const { return iterator(begin_); }

  iterator end() const { return iterator(end_); }

private:
  int begin_;
  int end_;
};

Range range(int begin, int end) { return Range(begin, end); }
class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int ans = 0;
    const auto m = matrix.size();
    if (m == 0)
      return 0;
    const auto n = matrix[0].size();
    if (n == 0)
      return 0;
    vector<char> fliped(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        fliped[j] = matrix[i][j] != 0;
      int cnt = 0;
      for (int i_ = 0; i_ < m; ++i_) {
        ++cnt;
        auto ori = fliped[0] ^ matrix[i_][0];
        for (int j_ = 1; j_ < n; ++j_)
          if ((fliped[j_] ^ matrix[i_][j_]) != ori) {
            --cnt;
            break;
          }
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
