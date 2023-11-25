//
// 给你一个输入字符串 (
// s) 和一个字符模式 (
// p) ，请你实现一个支持
// '?' 和
// '*' 匹配规则的通配符匹配：
//
//
//
// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符序列（包括空字符序列）。
//
//
//
//
// 判定匹配成功的充要条件是：字符模式必须能够 完全匹配
// 输入字符串（而不是部分匹配）。
//
//
//
// 示例 1：
//
//
// 输入：s = "aa", p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。
//
//
// 示例 2：
//
//
// 输入：s = "aa", p = "*"
// 输出：true
// 解释：'*' 可以匹配任意字符串。
//
//
// 示例 3：
//
//
// 输入：s = "cb", p = "?a"
// 输出：false
// 解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
//
//
//
//
// 提示：
//
//
// 0 <= s.length, p.length <= 2000
// s 仅由小写英文字母组成
// p 仅由小写英文字母、'?' 或 '*' 组成
//
//
// Related Topics 贪心 递归 字符串 动态规划 👍 1102 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include "set"
#include "string_view"
#include "vector"
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    using usize = std::size_t;
    usize n = s.size(), m = p.size();
    vector dp(n + 1, vector(m + 1, false));
    // case0: p[j] is alpha, and s[i] == p[j], dp[i][j] = dp[i - 1][j - 1]
    // case1: p[j] is '?', dp[i][j] = dp[i - 1][j - 1]
    // case1: p[j] is '*', dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
    dp[0][0] = true;
    for (usize j = 1; j <= m; ++j)
      if (p[j - 1] == '*')
        dp[0][j] = true;
    else
        break;
    for (usize i = 1; i <= n; ++i)
      for (usize j = 1; j <= m; ++j) {
        if (p[j - 1] == '?' or p[j - 1] == s[i - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else if (p[j - 1] == '*')
          dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
      }

    return dp[n][m];
  }
};
// leetcode submit region end(Prohibit modification and deletion)