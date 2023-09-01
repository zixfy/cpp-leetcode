// 给你一个由 正 整数组成的数组 nums 。
//
//  如果 nums 的子数组中位于 不同 位置的每对元素按位 与（AND）运算的结果等于 0
//  ，则称该子数组为 优雅 子数组。
//
//  返回 最长 的优雅子数组的长度。
//
//  子数组 是数组中的一个 连续 部分。
//
//  注意：长度为 1 的子数组始终视作优雅子数组。
//
//
//
//  示例 1：
//
//  输入：nums = [1,3,8,48,10]
// 输出：3
// 解释：最长的优雅子数组是 [3,8,48] 。子数组满足题目条件：
//- 3 AND 8 = 0
//- 3 AND 48 = 0
//- 8 AND 48 = 0
// 可以证明不存在更长的优雅子数组，所以返回 3 。
//
//  示例 2：
//
//  输入：nums = [3,1,5,11,13]
// 输出：1
// 解释：最长的优雅子数组长度为 1 ，任何长度为 1 的子数组都满足题目条件。
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  1 <= nums[i] <= 10⁹
//
//
//  Related Topics 位运算 数组 滑动窗口 👍 44 👎 0

#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using std::vector;
class Solution {
private:
  struct RangeOrs {
    std::array<int, 32> digits;
    int s;
    inline auto get() { return s; }
    void operator+=(int x) {
      s |= x;
      for (int i = 0, d = 1; d <= x; ++i, d <<= 1)
        if (d & x)
          digits[i]++;
    }
    void operator-=(int x) {
      for (int i = 0, d = 1; d <= x; ++i, d <<= 1)
        if ((d & x) && (--digits[i] == 0))
          s -= d;
    }
  };

public:
  int longestNiceSubarray(vector<int> &nums) {
    int ans = 0;
    int l = 0, r = 0;
    auto ors = RangeOrs{};
    for (; r < nums.size(); ++r) {
      while (l < r && (ors.get() & nums[r]))
        ors -= nums[l++];
      ors += nums[r];
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
