//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
// 
// 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 10⁴ 
// s[i] 为 '(' 或 ')' 
// 
//
// Related Topics 栈 字符串 动态规划 👍 2317 👎 0


#include <string>
#include <stack>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
//leetcode submit region begin(Prohibit modification and deletion)

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
      stack<pair<int, char>> st;
      int ans = 0 ;
      st.emplace(-1, ')');
      for (int i = 0; i < s.size(); ++i) {
        auto c = s[i];
        if (c == ')' &&   st.top().second == '(') {
          st.pop();
        }
        else st.emplace(i, c);
        ans = max(ans, i - st.top().first);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




