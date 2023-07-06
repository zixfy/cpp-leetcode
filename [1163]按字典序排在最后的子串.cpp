// 给你一个字符串 s ，找出它的所有子串并按字典序排列，返回排在最后的那个子串。
//
//
//
//  示例 1：
//
//
// 输入：s = "abab"
// 输出："bab"
// 解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba",
// "bab"]。按字典序排在最后的子串是 "bab"。
//
//
//  示例 2：
//
//
// 输入：s = "leetcode"
// 输出："tcode"
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 4 * 10⁵
//  s 仅含有小写英文字符。
//
//
//  Related Topics 双指针 字符串 👍 77 👎 0
#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  string lastSubstring(string s) {
    auto n{s.size()};
    char maxx = 'a' - 1;
    int maxx_cnt{}, cur_maxx_cnt{};
    int idx{};
    for (auto i{n}; i-- > 0;) {
      if (s[i] > maxx) {
        maxx = s[i];
        maxx_cnt = 1;
        idx = i;
      } else if (s[i] == maxx) {
        ++cur_maxx_cnt;
        if (cur_maxx_cnt > maxx_cnt)
          maxx_cnt = cur_maxx_cnt, idx = i;
        else if (cur_maxx_cnt == maxx_cnt &&
                 s.substr(idx, min(idx - i, n - idx)) <= s.substr(i, idx - i)) {
          idx = i;
        }
      } else {
        cur_maxx_cnt = 0;
      }
    }
    return s.substr(idx, n - idx);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
