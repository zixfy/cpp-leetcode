// 我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
//
//  您想要拼写出给定的字符串 target
//  ，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
//
//  返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。
//
//  注意：在所有的测试用例中，所有的单词都是从 1000
//  个最常见的美国英语单词中随机选择的，并且 target 被选择为两个随机单词的连接。
//
//
//
//  示例 1：
//
//
// 输入： stickers = ["with","example","science"], target = "thehat"
// 输出：3
// 解释：
// 我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
// 把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
// 此外，这是形成目标字符串所需的最小贴纸数量。
//
//
//  示例 2:
//
//
// 输入：stickers = ["notice","possible"], target = "basicbasic"
// 输出：-1
// 解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
//
//
//
//  提示:
//
//
//  n == stickers.length
//  1 <= n <= 50
//  1 <= stickers[i].length <= 10
//  1 <= target.length <= 15
//  stickers[i] 和 target 由小写英文单词组成
//
//
//  Related Topics 位运算 数组 字符串 动态规划 回溯 状态压缩 👍 266 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int minStickers(vector<string> &stickers, string target) {
    auto n = stickers.size(), m = target.size();
    auto expm = 1 << m;
    unordered_set base(target.begin(), target.end());
    vector<std::array<int, 26>> masks;
    std::transform(stickers.begin(), stickers.end(), back_inserter(masks),
                   [&](auto const &stk) {
                     std::array<int, 26> ret{};
                     for (auto c : stk)
                       ret[c - 'a']++;
                     return ret;
                   });
    vector dp(expm, numeric_limits<int>::max() / 2);
    dp.front() = 0;
    for (size_t s = 0; s < expm; ++s) {
      for (auto const &_mask : masks) {
        auto nxt_s = s;
        auto mask = _mask;
        for (int j = 0; j < m; ++j)
          if (!(s & (1 << j)) && mask[target[j] - 'a'])
            nxt_s |= (1 << j), mask[target[j] - 'a']--;
        dp[nxt_s] = min(dp[nxt_s], dp[s] + 1);
      }
    }

    return dp.back() > 114514 ? -1 : dp.back();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
