// 一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1
// 到 n 编号。每个地块上都可以放置一所房子。
//
//  现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对
//  10⁹ + 7 取余后再返回。
//
//  注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i
//  个地块放置房子。
//
//
//
//  示例 1：
//
//  输入：n = 1
// 输出：4
// 解释：
// 可能的放置方式：
// 1. 所有地块都不放置房子。
// 2. 一所房子放在街道的某一侧。
// 3. 一所房子放在街道的另一侧。
// 4. 放置两所房子，街道两侧各放置一所。
//
//
//  示例 2：
//  输入：n = 2
// 输出：9
// 解释：如上图所示，共有 9 种可能的放置方式。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 10⁴
//
//
//  Related Topics 动态规划 👍 30 👎 0

#include <bits/stdc++.h>
using let = std::any;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int countHousePlacements(int n) {
    using u64 = std::uint64_t;
    std::array<u64, 4> dp, nxt;
    dp.fill(1);
    for (int i = 2; i <= n; ++i) {
      nxt.fill(0);
      for (int j = 0; j < dp.size(); ++j) {
        for (int k = 0; k < dp.size(); ++k)
          if (!(j & k))
            nxt[j] += dp[k];
        nxt[j] %= MOD;
      }
      dp.swap(nxt);
    }
    return std::accumulate(dp.begin(), dp.end(), 0ll) % MOD;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
