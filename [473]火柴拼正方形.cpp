// 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i
// 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能 折断
// 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
//
//  如果你能使这个正方形，则返回 true ，否则返回 false 。
//
//
//
//  示例 1:
//
//
//
//
// 输入: matchsticks = [1,1,2,2,2]
// 输出: true
// 解释: 能拼成一个边长为2的正方形，每边两根火柴。
//
//
//  示例 2:
//
//
// 输入: matchsticks = [3,3,3,3,4]
// 输出: false
// 解释: 不能用所有火柴拼成一个正方形。
//
//
//
//
//  提示:
//
//
//  1 <= matchsticks.length <= 15
//  1 <= matchsticks[i] <= 10⁸
//
//
//  Related Topics 位运算 数组 动态规划 回溯 状态压缩 👍 495 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  bool makesquare(vector<int> &matchsticks) {
    auto const n = matchsticks.size();
    auto sumy = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sumy % 4)
      return false;
    auto frac = sumy / 4;

    unordered_map<int, int> bit2num;
    for (int i = 0; i < n; ++i)
      bit2num[1 << i] = matchsticks[i];
    auto expn = 1 << n;
    vector dp(expn, 0);
    vector<int> vaild1;
    unordered_set<int> vaild2;
    for (int i = 1; i < expn; ++i) {
      auto lb = i & (-i);
      dp[i] = dp[i - lb] + bit2num[lb];
      if (dp[i] == frac)
        vaild1.emplace_back(i);
    }
    for (int i = 0; i < vaild1.size(); ++i)
      for (int j = i + 1; j < vaild1.size(); ++j) {
        auto s1 = vaild1[i] , s2 = vaild1[j];
        if ((s1 & s2) == 0)
          vaild2.insert(s1 | s2);
      }
    for (auto s: vaild2)
      if (vaild2.count(expn - 1 - s))
        return true;
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
