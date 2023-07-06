// 给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j]
// 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语
// 的小写字母。如果没有不包含相同字符的一对字符串，返回 0。
//
//
//
//  示例 1:
//
//
// 输入: words = ["abcw","baz","foo","bar","fxyz","abcdef"]
// 输出: 16
// 解释: 这两个单词为 "abcw", "fxyz"。它们不包含相同字符，且长度的乘积最大。
//
//  示例 2:
//
//
// 输入: words = ["a","ab","abc","d","cd","bcd","abcd"]
// 输出: 4
// 解释: 这两个单词为 "ab", "cd"。
//
//  示例 3:
//
//
// 输入: words = ["a","aa","aaa","aaaa"]
// 输出: 0
// 解释: 不存在这样的两个单词。
//
//
//
//
//  提示：
//
//
//  2 <= words.length <= 1000
//  1 <= words[i].length <= 1000
//  words[i] 仅包含小写字母
//
//
//
//
//
//  注意：本题与主站 318
//  题相同：https://leetcode-cn.com/problems/maximum-product-of-word-
// lengths/
//
//  Related Topics 位运算 数组 字符串 👍 142 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int maxProduct(vector<string> &words) {
    int ans = 0;
    const auto n = words.size();
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      return a.length() > b.length();
    });
    vector<unordered_set<char>> vs;
    for (const string &w : words)
      vs.emplace_back(w.begin(), w.end());
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        const auto &w1 = words[i], &w2 = words[j];
        auto t = w1.length() * w2.length();
        if (t <= ans)
          break;
        bool v = true;
        for (auto c1 : vs[i])
          if (vs[j].count(c1)) {
            v = false;
            break;
          }
        if (v)
          ans = t;
      }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
