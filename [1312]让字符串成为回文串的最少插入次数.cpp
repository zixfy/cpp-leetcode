// 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
//
//  请你返回让 s 成为回文串的 最少操作次数 。
//
//  「回文串」是正读和反读都相同的字符串。
//
//
//
//  示例 1：
//
//
// 输入：s = "zzazz"
// 输出：0
// 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
//
//
//  示例 2：
//
//
// 输入：s = "mbadm"
// 输出：2
// 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
//
//
//  示例 3：
//
//
// 输入：s = "leetcode"
// 输出：5
// 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 500
//  s 中所有字符都是小写字母。
//
//
//  Related Topics 字符串 动态规划 👍 183 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int minInsertions(string s) {
    const auto n = s.length();
    string ss(s.rbegin(), s.rend());
    vector dp(n + 1, vector(n + 1, 0));
    for (auto i = 1; i <= n; ++i)
      for (auto j = 1; j <= n; ++j) {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        if (s[i - 1] == ss[j - 1])
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    return n - dp[n][n];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
