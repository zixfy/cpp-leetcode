// 给你一个字符串 s ，它包含一个或者多个单词。单词之间用单个空格 ' ' 隔开。
//
//  如果字符串 t 中第 i 个单词是 s 中第 i 个单词的一个 排列 ，那么我们称字符串 t
//  是字符串 s 的同位异构字符串。
//
//
//  比方说，"acb dfe" 是 "abc def" 的同位异构字符串，但是 "def cab" 和 "adc bef"
//  不是。
//
//
//  请你返回 s 的同位异构字符串的数目，由于答案可能很大，请你将它对 10⁹ + 7 取余
//  后返回。
//
//
//
//  示例 1：
//
//  输入：s = "too hot"
// 输出：18
// 解释：输入字符串的一些同位异构字符串为 "too hot" ，"oot hot" ，"oto toh"
// ，"too toh" 以及 "too oht" 。
//
//
//  示例 2：
//
//  输入：s = "aa"
// 输出：1
// 解释：输入字符串只有一个同位异构字符串。
//
//
//
//  提示：
//
//
//  1 <= s.length <= 10⁵
//  s 只包含小写英文字母和空格 ' ' 。
//  相邻单词之间由单个空格隔开。
//
//
//  Related Topics 哈希表 数学 字符串 组合数学 计数 👍 14 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
constexpr int MOD = 1e9 + 7;
long long qpow(int i) {
  if (i == 1)
    return 1;
  auto modd = MOD - 2;
  long long ans = 1ll, base = i;
  while (modd) {
    if (modd & 1)
      ans = ans * base % MOD;
    modd >>= 1;
    base = base * base % MOD;
  }
  return ans;
}
auto split(std::string_view const &s, const char sep = ' ') {
  std::vector<std::string_view> tokens;
  size_t start = 0;
  size_t end = s.find(sep);
  while (end != std::string_view::npos) {
    tokens.push_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find(sep, start);
  }
  if (start < s.length())
    tokens.emplace_back(s.begin() + start, s.length() - start);
  return tokens;
}
class Solution {
public:
  int countAnagrams(std::string s) {
//    cout << qpow(2) * 2 % MOD << endl;
    auto words = split(s);
    auto ans = 1ll;
    for (const auto &w : words)
      ans = (ans * f(w)) % MOD;
    return ans;
  }

private:
  long long f(std::string_view const &);
};
long long Solution::f(const std::string_view &s) {
  std::unordered_map<char, int> cnt;
  for (auto c : s)
    cnt[c]++;
  auto ans = 1ll;
  int idx = 1;
  for (auto [k, v] : cnt)
    for (int jdx = 1; jdx <= v; ++jdx, ++idx)
      ans = ans * idx % MOD, ans = ans * qpow(jdx) % MOD;
  return ans;
}
// leetcode submit region end(Prohibit modification and deletion)
