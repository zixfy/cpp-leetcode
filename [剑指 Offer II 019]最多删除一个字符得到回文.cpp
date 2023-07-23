// 给定一个非空字符串 s，请判断如果 最多
// 从字符串中删除一个字符能否得到一个回文字符串。
//
//
//
//  示例 1:
//
//
// 输入: s = "aba"
// 输出: true
//
//
//  示例 2:
//
//
// 输入: s = "abca"
// 输出: true
// 解释: 可以删除 "c" 字符 或者 "b" 字符
//
//
//  示例 3:
//
//
// 输入: s = "abc"
// 输出: false
//
//
//
//  提示:
//
//
//  1 <= s.length <= 10⁵
//  s 由小写英文字母组成
//
//
//
//
//
//  注意：本题与主站 680 题相同：
//  https://leetcode-cn.com/problems/valid-palindrome-ii/
//
//  Related Topics 贪心 双指针 字符串 👍 74 👎 0

#include <bits/stdc++.h>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  bool _is_pure_pali(std::string_view s) {
    size_t l = 0, r = s.length() - 1;
    while (l < r) {
      if (s[l] != s[r])
        return false;
      l++, r--;
    }
    return true;
  }

public:
  bool validPalindrome(std::string s) {
    const auto n = s.size();
    size_t l = 0, r = n - 1;
    while (l < r) {
      if (s[l] != s[r])
        return _is_pure_pali({s.c_str() + l, r - l}) ||
               _is_pure_pali({s.c_str() + l + 1, r - l});
      l++, r--;
    }
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
