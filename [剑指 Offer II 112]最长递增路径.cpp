//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。 
//
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
//输出：4 
//解释：最长递增路径为 [1, 2, 6, 9]。 
//
// 示例 2： 
//
// 
//
// 
//输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
//输出：4 
//解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 
//
// 示例 3： 
//
// 
//输入：matrix = [[1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 2³¹ - 1 
// 
//
// 
//
// 
// 注意：本题与主站 329 题相同： https://leetcode-cn.com/problems/longest-increasing-path-
//in-a-matrix/ 
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 记忆化搜索 数组 动态规划 矩阵 👍 39 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using namespace std;
int n, m;
const int dic[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int dfs(int i, int j, int** dp, vector<vector<int>>& matrix) {
  if (dp[i][j]) return dp[i][j];
  dp[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int ii = i + dic[k][0], jj = j + dic[k][1];
    if (ii >= 0 && ii < n && jj >= 0 && jj < m && matrix[i][j] < matrix[ii][jj]) {
      dp[i][j] = max(dp[i][j], dfs(ii, jj, dp, matrix) + 1);
    }
  }
  //printf("i:%d j:%d dp = %d\n", i, j, dp[i][j]);
  return dp[i][j];
}

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();
    int ans = -0x7fffffff;
    int **dp = new int*[n];
    for (int i = 0; i < n; i++)
      dp[i] = new int[m]{};
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        ans = max(ans, dfs(i, j, dp, matrix));
      }
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
