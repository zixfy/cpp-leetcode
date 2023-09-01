// 给你一个字符串数组 words 和一个字符串 s ，请你判断 s 是不是 words 的
// 首字母缩略词 。
//
//  如果可以按顺序串联 words 中每个字符串的第一个字符形成字符串 s ，则认为 s 是
//  words 的首字母缩略词。例如，"ab" 可以由 [
//"apple", "banana"] 形成，但是无法从 ["bear", "aardvark"] 形成。
//
//  如果 s 是 words 的首字母缩略词，返回 true ；否则，返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：words = ["alice","bob","charlie"], s = "abc"
// 输出：true
// 解释：words 中 "alice"、"bob" 和 "charlie" 的第一个字符分别是 'a'、'b' 和
// 'c'。因此，s = "abc" 是首字母 缩略词。
//
//
//  示例 2：
//
//
// 输入：words = ["an","apple"], s = "a"
// 输出：false
// 解释：words 中 "an" 和 "apple" 的第一个字符分别是 'a' 和 'a'。
// 串联这些字符形成的首字母缩略词是 "aa" 。
// 因此，s = "a" 不是首字母缩略词。
//
//
//  示例 3：
//
//
// 输入：words = ["never","gonna","give","up","on","you"], s = "ngguoy"
// 输出：true
// 解释：串联数组 words 中每个字符串的第一个字符，得到字符串 "ngguoy" 。
// 因此，s = "ngguoy" 是首字母缩略词。
//
//
//
//
//  提示：
//
//
//  1 <= words.length <= 100
//  1 <= words[i].length <= 10
//  1 <= s.length <= 100
//  words[i] 和 s 由小写英文字母组成
//
//
//  👍 2 👎 0

#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using std::vector, std::string;
class Solution {
public:
  bool isAcronym(vector<string> &words, string s) {
    if (s.size() != words.size())
      return false;
    for (int i = 0; i < s.size(); ++i)
      if (words[i].front() != s[i])
        return false;
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
