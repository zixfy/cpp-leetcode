// 有 n 根长度互不相同的木棍，长度为从 1 到 n
// 的整数。请你将这些木棍排成一排，并满足从左侧 可以看到 恰好 k 根木棍。从左侧
// 可以看到 木棍的前提是 这个木棍的 左侧 不存在比它 更长的 木棍。
//
//
//  例如，如果木棍排列为 [1,3,2,5,4] ，那么从左侧可以看到的就是长度分别为 1、3
//  、5 的木棍。
//
//
//  给你 n 和 k ，返回符合题目要求的排列 数目 。由于答案可能很大，请返回对 10⁹ +
//  7 取余 的结果。
//
//
//
//  示例 1：
//
//  输入：n = 3, k = 2
// 输出：3
// 解释：[1,3,2], [2,3,1] 和 [2,1,3] 是仅有的能满足恰好 2 根木棍可以看到的排列。
// 可以看到的木棍已经用粗体+斜体标识。
//
//
//  示例 2：
//
//  输入：n = 5, k = 5
// 输出：1
// 解释：[1,2,3,4,5] 是唯一一种能满足全部 5 根木棍可以看到的排列。
// 可以看到的木棍已经用粗体+斜体标识。
//
//
//  示例 3：
//
//  输入：n = 20, k = 11
// 输出：647427950
// 解释：总共有 647427950 (mod 109 + 7) 种能满足恰好有 11 根木棍可以看到的排列。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 1000
//  1 <= k <= n
//
//
//  Related Topics 数学 动态规划 组合数学 👍 65 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
constexpr int MOD = 1e9 + 7;
using i64 = long long;
class Solution {

public:
  int rearrangeSticks(int n, int k) {
    vector dp(n + 1, vector(k + 1, i64(0)));
    vector frac(n, i64(1));
    for (int i = 1; i < n ;++i)
      frac[i] = frac[i - 1] * (n - i);
    for (int i = 0; i <= k ;++i)
      dp[0][i] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i][1] =
      for (int j = 2; j <= min(i, k); ++j)
        for (int l = j - 1; l < i; ++l)
          dp[i][j] = (dp[i][j] + dp[l][j - 1] * frac[i - l - 1]) % MOD;
    }
    // n >= k
    // m >= k - 1
    // dp[n][k] = dp[m][k - 1] * frac(n - m  - 1)
    return dp[n][k];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
