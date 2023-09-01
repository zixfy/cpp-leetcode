// 给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。
//
//
//
//  示例 1:
//
//
// 输入: n = 5
// 输出: 2
// 解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
//
//  示例 2:
//
//
// 输入: n = 9
// 输出: 3
// 解释: 9 = 4 + 5 = 2 + 3 + 4
//
//  示例 3:
//
//
// 输入: n = 15
// 输出: 4
// 解释: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
//
//
//
//  提示:
//
//
//  1 <= n <= 10⁹
//
//
//  Related Topics 数学 枚举 👍 266 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int consecutiveNumbersSum(int n) {
    int i;
    int ans = 0;
    int n2 = n * 2;
    for (i = 1; i * (i + 1) <= n2; ++i) {
      if ((n2 + i * (1 - i)) % (2 * i) == 0)
        ++ans;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
