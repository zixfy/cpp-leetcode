// 给定一个字符串 s，请将 s 分割成一些子串，使每个子串都是回文串。
//
//  返回符合要求的 最少分割次数 。
//
//
//
//
//
//
//
//  示例 1：
//
//
// 输入：s = "aab"
// 输出：1
// 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
//
//
//  示例 2：
//
//
// 输入：s = "a"
// 输出：0
//
//
//  示例 3：
//
//
// 输入：s = "ab"
// 输出：1
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 2000
//  s 仅由小写英文字母组成
//
//
//
//
//
//  注意：本题与主站 132 题相同：
//  https://leetcode-cn.com/problems/palindrome-partitioning-
// ii/
//
//  Related Topics 字符串 动态规划 👍 63 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  int minCut(string s) {
    // dp[i] = min(dp[j]) + 1 where s[j+1,,,i] is palindrome
    const auto n = s.length();
    vector is_palindrome(n, vector(n, '\0'));
    for (size_t i = 0; i < n; ++i)
      for (size_t l = i + 1, r = i; l-- > 0 && r < n; ++r)
        if (s[l] == s[r])
          is_palindrome[l][r] = '1';
        else
          break;
    for (size_t i = 1; i < n; ++i)
      for (size_t l = i, r = i; l-- > 0 && r < n; ++r)
        if (s[l] == s[r])
          is_palindrome[l][r] = '1';
        else
          break;
    //    cout << is_palindrome << endl;
    vector dp(n, 0);
    for (size_t i = 0; i < n; ++i) {
      if (is_palindrome[0][i])
        continue;
      dp[i] = n;
      for (size_t j = 0; j < i; ++j)
        if (is_palindrome[j + 1][i])
          dp[i] = min(dp[j] + 1, dp[i]);
    }
    return dp[n - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
