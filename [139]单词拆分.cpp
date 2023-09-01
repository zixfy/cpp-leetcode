// 给你一个字符串 s 和一个字符串列表 wordDict
// 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//
//  注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//
//
//
//  示例 1：
//
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
//
//
//  示例 2：
//
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//      注意，你可以重复使用字典中的单词。
//
//
//  示例 3：
//
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 300
//  1 <= wordDict.length <= 1000
//  1 <= wordDict[i].length <= 20
//  s 和 wordDict[i] 仅有小写英文字母组成
//  wordDict 中的所有字符串 互不相同
//
//
//  Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 👍 2205 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string_view> wset(wordDict.begin(), wordDict.end());
    auto mwl = std::max_element(wset.begin(), wset.end(),
                                [](auto const &a, auto const &b) {
                                  return a.length() < b.length();
                                })
                   ->length();
    auto n = s.length();
    vector dp(n, char(0));
    for (int i = 0; i < n; ++i) {
      for (string_view w : wset) {
        if (w.size() <= i + 1 &&
            w == string_view(s.c_str() + i + 1 - w.size(), w.size())) {
          if (w.size() == i + 1)
            dp[i] = 1;
          else
            dp[i] |= dp[i - w.size()];

          if (dp[i] == 1)
            break;
        }
      }
    }
    return dp.back();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
