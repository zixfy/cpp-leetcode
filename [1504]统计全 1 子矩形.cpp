// 给你一个 m x n 的二进制矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：mat = [[1,0,1],[1,1,0],[1,1,0]]
// 输出：13
// 解释：
// 有 6 个 1x1 的矩形。
// 有 2 个 1x2 的矩形。
// 有 3 个 2x1 的矩形。
// 有 1 个 2x2 的矩形。
// 有 1 个 3x1 的矩形。
// 矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
//
//
//  示例 2：
//
//
//
//
// 输入：mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
// 输出：24
// 解释：
// 有 8 个 1x1 的子矩形。
// 有 5 个 1x2 的子矩形。
// 有 2 个 1x3 的子矩形。
// 有 4 个 2x1 的子矩形。
// 有 2 个 2x2 的子矩形。
// 有 2 个 3x1 的子矩形。
// 有 1 个 3x2 的子矩形。
// 矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
//
//
//
//
//
//  提示：
//
//
//  1 <= m, n <= 150
//  mat[i][j] 仅包含 0 或 1
//
//
//  Related Topics 栈 数组 动态规划 矩阵 单调栈 👍 179 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include "stack"
#include "vector"
using namespace std;

class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    // dp[i][j] =
    int ans = 0;
    auto m = mat.size(), n = mat.front().size();
    vector width(m, vector(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        if (mat[i][j])
          width[i][j] = j + 1 < n ? width[i][j + 1] + 1 : 1;
      }
    }
    for (int j = 0; j < n; ++j) {
      std::vector<int> st{};
      int cur_area = 0;

      for (int i = 0; i < m; ++i) {
        auto cur = width[i][j];
        int repeat = 1;
        while (not st.empty() and st.back() > cur) {
          repeat ++;
          cur_area -= st.back();
          cur_area += cur;
          st.pop_back();
        }
        ans += cur + cur_area;
        cur_area += cur;
//        if (cur_area)
//        cout << i << ", " << j << ", " << cur_area << endl;
        for (int ii = 0; ii < repeat; ++ii)
        st.emplace_back(cur);
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
