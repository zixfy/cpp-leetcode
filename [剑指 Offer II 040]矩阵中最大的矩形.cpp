// 给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。
//
//  注意：此题 matrix 输入格式为一维 01 字符串数组。
//
//
//
//  示例 1：
//
//
//
//
// 输入：matrix = ["10100","10111","11111","10010"]
// 输出：6
// 解释：最大矩形如上图所示。
//
//
//  示例 2：
//
//
// 输入：matrix = []
// 输出：0
//
//
//  示例 3：
//
//
// 输入：matrix = ["0"]
// 输出：0
//
//
//  示例 4：
//
//
// 输入：matrix = ["1"]
// 输出：1
//
//
//  示例 5：
//
//
// 输入：matrix = ["00"]
// 输出：0
//
//
//
//
//  提示：
//
//
//  rows == matrix.length
//  cols == matrix[0].length
//  0 <= row, cols <= 200
//  matrix[i][j] 为 '0' 或 '1'
//
//
//
//
//  注意：本题与主站 85 题相同（输入参数格式不同）：
//  https://leetcode-cn.com/problems/maximal-
// rectangle/
//
//  Related Topics 栈 数组 动态规划 矩阵 单调栈 👍 78 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximalRectangle(vector<string> &matrix) {
    if (matrix.size() == 0)
      return 0;
    const auto [m, n] = make_pair(matrix.size(), matrix[0].size());
    vector pre(n, 0);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      deque<pair<int, int>> stk;
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1')
          pre[j]++;
        else
          pre[j] = 0;
        if (pre[j]) {
          auto cur = pre[j];
          ans = max(ans, cur);
          for (const auto [v, idx] : stk)
            ans = max(ans, min(v, cur) * (j - idx + 1));
          int greedy_j = j;
          while (!stk.empty() && stk.back().first >= pre[j])
            greedy_j = stk.back().second, stk.pop_back();
          stk.emplace_back(pre[j], greedy_j);
        } else
          stk.clear();
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
