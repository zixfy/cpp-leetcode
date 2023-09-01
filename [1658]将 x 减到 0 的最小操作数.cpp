// 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums
// 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改
//  数组以供接下来的操作使用。
//
//  如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,1,4,2,3], x = 5
// 输出：2
// 解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
//
//
//  示例 2：
//
//
// 输入：nums = [5,6,7,8,9], x = 4
// 输出：-1
//
//
//  示例 3：
//
//
// 输入：nums = [3,2,20,1,1,3], x = 10
// 输出：5
// 解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0
// 。
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  1 <= nums[i] <= 10⁴
//  1 <= x <= 10⁹
//
//
//  Related Topics 数组 哈希表 二分查找 前缀和 滑动窗口 👍 294 👎 0

#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    auto sumy = std::accumulate(nums.begin(), nums.end(), 0);
    if (sumy < x)
      return -1;
    int n = nums.size();
    auto ans = numeric_limits<int>::max();
    auto prefix = nums;
    std::transform(prefix.begin(), prefix.end(), prefix.begin(),
                   [acc = 0](int i) mutable { return acc += i; });

    for (int i = n, acc = 0; i >= 0; acc += (--i, i >= 0 ? nums[i] : 0)) {
      if (acc > x)
        break;
      if (acc == x) {
        ans = std::min(ans, n - i);
        continue;
      }
      auto [p1, p2] = std::equal_range(prefix.begin(), prefix.end(), x - acc);
      if (p1 == p2)
        continue;
      ans = min(ans, n - i + int(p1 - prefix.begin() + 1));
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
