// 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
//
//  元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
//
//
//
//  示例 1：
//
//
// 输入：s = "hello"
// 输出："holle"
//
//
//  示例 2：
//
//
// 输入：s = "leetcode"
// 输出："leotcede"
//
//
//
//  提示：
//
//
//  1 <= s.length <= 3 * 10⁵
//  s 由 可打印的 ASCII 字符组成
//
//
//  Related Topics 双指针 字符串 👍 292 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
unordered_set yuan{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
class Solution {
public:
  string reverseVowels(string s) {
    int p1 = 0, p2 = s.length() - 1;
    while (p1 < p2) {
      if (yuan.count(s[p1]) && yuan.count(s[p2]))
        swap(s[p1++], s[p2--]);
      else {
        if (!yuan.count(s[p1]))
          p1++;
        if (!yuan.count(s[p2]))
          p2--;
      }
    }
    return s;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
