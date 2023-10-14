// 有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。
//
//  每次移动（move）需要将连续的 K 堆石头合并为一堆，而这个移动的成本为这 K
//  堆石头的总数。
//
//  找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。
//
//
//
//  示例 1：
//
//  输入：stones = [3,2,4,1], K = 2
// 输出：20
// 解释：
// 从 [3, 2, 4, 1] 开始。
// 合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
// 合并 [4, 1]，成本为 5，剩下 [5, 5]。
// 合并 [5, 5]，成本为 10，剩下 [10]。
// 总成本 20，这是可能的最小值。
//
//
//  示例 2：
//
//  输入：stones = [3,2,4,1], K = 3
// 输出：-1
// 解释：任何合并操作后，都会剩下 2
// 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
//
//
//  示例 3：
//
//  输入：stones = [3,5,1,2,6], K = 3
// 输出：25
// 解释：
// 从 [3, 5, 1, 2, 6] 开始。
// 合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
// 合并 [3, 8, 6]，成本为 17，剩下 [17]。
// 总成本 25，这是可能的最小值。
//
//
//
//
//  提示：
//
//
//  1 <= stones.length <= 30
//  2 <= K <= 30
//  1 <= stones[i] <= 100
//
//
//  Related Topics 数组 动态规划 👍 350 👎 0

#include <vector>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    auto n{stones.size()};
    if ((n < k) || (n - k) % (k - 1))
      return -1;
    vector prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];
    vector dp(n, vector(n, 0));
    for (int i = 0, j = k - 1; j < n; ++i, ++j)
      dp[i][j] = prefix[j + 1] - prefix[i];
    for (int len = k + k - 1; len <= n; len += k - 1) {
      auto last_len = len - k + 1;
      for (int i = 0, j = len - 1; j < n; ++i, ++j) {
        dp[i][j] = INT_MAX;
        for (int l = i, r = i + last_len - 1; r <= j; ++l, ++r)
          dp[i][j] = min(dp[i][j], dp[l][r]);
        dp[i][j] += prefix[j + 1] - prefix[i];
        cout << i << ", " << j << ", " << dp[i][j] << endl;
      }

    }
    return dp[0][n - 1];
    // dp[i][j] = dp[i][k]  + dp
  }
};
// leetcode submit region end(Prohibit modification and deletion)
