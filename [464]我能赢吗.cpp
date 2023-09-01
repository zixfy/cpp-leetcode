// 在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10
// 的任意整数，累计整数和，先使得累计整数和 达到或超过 100 的玩家，即为胜者。
//
//  如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？
//
//  例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15
//  的整数（不放回），直到累计整数和 >= 100。
//
//  给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和
//  desiredTotal（累计和），若先出手的玩家能稳赢则返回
// true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。
//
//
//
//  示例 1：
//
//
// 输入：maxChoosableInteger = 10, desiredTotal = 11
// 输出：false
// 解释：
// 无论第一个玩家选择哪个整数，他都会失败。
// 第一个玩家可以选择从 1 到 10 的整数。
// 如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
// 第二个玩家可以通过选择整数 10（那么累积和为 11 >=
// desiredTotal），从而取得胜利.
// 同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
//
//
//  示例 2:
//
//
// 输入：maxChoosableInteger = 10, desiredTotal = 0
// 输出：true
//
//
//  示例 3:
//
//
// 输入：maxChoosableInteger = 10, desiredTotal = 1
// 输出：true
//
//
//
//
//  提示:
//
//
//  1 <= maxChoosableInteger <= 20
//  0 <= desiredTotal <= 300
//
//
//  Related Topics 位运算 记忆化搜索 数学 动态规划 状态压缩 博弈 👍 516 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal == 0)
      return true;
    if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal)
      return false;
    using u8 = uint8_t;
    auto expn = 1 << maxChoosableInteger;
    std::vector dp(expn, u8{});
    auto sumy = [](int s) {
      int base = 1;
      int ret = 0;
      while (s) {
        if (s & 1)
          ret += base;
        s >>= 1;
        ++base;
      }
      return ret;
    };
    auto cur_sum = sumy(expn);

    for (int s = expn - 1; s >= 0; --s) {
      int s_dif = s ^ (s + 1);
      cur_sum += sumy(s_dif & (s)) - sumy(s_dif & (s + 1));
      if (cur_sum >= desiredTotal)
        dp[s] = false;
      if (dp[s])
        continue;
      auto tmp = s;
      while (tmp) {
        auto low_bit = tmp & -tmp;
        dp[s ^ low_bit] = true;
        tmp ^= low_bit;
      }
    }
    return dp[0];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
