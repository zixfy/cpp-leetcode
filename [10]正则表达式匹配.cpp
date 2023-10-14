// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*'
// 的正则表达式匹配。
//
//
//  '.' 匹配任意单个字符
//  '*' 匹配零个或多个前面的那一个元素
//
//
//  所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//
//  示例 1：
//
//
// 输入：s = "aa", p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。
//
//
//  示例 2:
//
//
// 输入：s = "aa", p = "a*"
// 输出：true
// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是
// 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//
//
//  示例 3：
//
//
// 输入：s = "ab", p = ".*"
// 输出：true
// 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 20
//  1 <= p.length <= 20
//  s 只包含从 a-z 的小写字母。
//  p 只包含从 a-z 的小写字母，以及字符 . 和 *。
//  保证每次出现字符 * 时，前面都匹配到有效的字符
//
//
//  Related Topics 递归 字符串 动态规划 👍 3605 👎 0

#include <string>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
#include "vector"
class Solution {
public:
  bool isMatch(string s, string p) {
    auto m = s.size(), n = p.size();
    vector dp(m + 1, vector(n + 1, false));
    dp[0][0] = true;
    using uz = size_t;
    for (int i = 2; i <= n; i += 2)
      if (p[i - 1] == '*')
        dp[0][i] = true;
      else
        break;
    for (uz i = 1; i <= m; ++i)
      for (uz j = 1; j <= n; ++j) {
        if (j < n && p[j] == '*') {
          auto need = p[j - 1];
          ++j;
          if (need == '.') {
            for (uz k = 0; k <= i; ++k)
              dp[i][j] = dp[i][j] || dp[k][j - 2];
          } else {
            dp[i][j] = dp[i][j - 2];
            for (uz k = i; k > 0 && s[k - 1] == need; --k)
              dp[i][j] = dp[k - 1][j - 2] || dp[i][j];
          }
        } else if (p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else
          dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
        //        cout << i << ", " << j << ", " << dp[i][j] << endl;
      }
    // p[j] is alpha, dp[i][j] = s[i] == p[j] && dp[i - 1][j -1]
    // p[j] is dot, dp[i][j] = dp[i - 1][j - 1]
    // p[j] is star , dp[i][j] = (dp[k <= i][j - 1] || ...)

    return dp[m][n];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
