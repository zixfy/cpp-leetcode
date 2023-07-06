// 给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词
// 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//
//  变位词 指字母相同，但排列不同的字符串。
//
//
//
//  示例 1：
//
//
// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的变位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的变位词。
//
//
//  示例 2：
//
//
// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的变位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的变位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的变位词。
//
//
//
//
//  提示:
//
//
//  1 <= s.length, p.length <= 3 * 10⁴
//  s 和 p 仅包含小写字母
//
//
//
//
//  注意：本题与主站 438 题相同：
//  https://leetcode-cn.com/problems/find-all-anagrams-in-a-
// string/
//
//  Related Topics 哈希表 字符串 滑动窗口 👍 52 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
auto string_cnt_chars(const string_view &s) {
  unordered_map<char, int> ans;
  for (auto c : s)
    ans[c]++;
  return ans;
}
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    const auto s_len = s.length(), p_len = p.length();
    if (s_len < p_len)
      return {};
    vector<int> ans;
    auto p_dict = string_cnt_chars(p);
    int l = 0, r = 0;
    // [l, r)
    decltype(p_dict) s_dict;
    int okay_cnt = 0;
    for (; r < s_len; ++r) {
      auto cr = s[r];
      if (p_dict.count(cr) && ++s_dict[cr] == p_dict[cr])
        ++okay_cnt;
      if (r >= p_len) {
        auto cl = s[l];
        if (p_dict.count(cl) && --s_dict[cl] == p_dict[cl] - 1)
          --okay_cnt;
        ++l;
      }
      if (okay_cnt == p_dict.size())
        ans.push_back(l);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
