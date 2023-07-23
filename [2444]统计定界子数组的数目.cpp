// 给你一个整数数组 nums 和两个整数 minK 以及 maxK 。
//
//  nums 的定界子数组是满足下述条件的一个子数组：
//
//
//  子数组中的 最小值 等于 minK 。
//  子数组中的 最大值 等于 maxK 。
//
//
//  返回定界子数组的数目。
//
//  子数组是数组中的一个连续部分。
//
//
//
//  示例 1：
//
//  输入：nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// 输出：2
// 解释：定界子数组是 [1,3,5] 和 [1,3,5,2] 。
//
//
//  示例 2：
//
//  输入：nums = [1,1,1,1], minK = 1, maxK = 1
// 输出：10
// 解释：nums 的每个子数组都是一个定界子数组。共有 10 个子数组。
//
//
//
//  提示：
//
//
//  2 <= nums.length <= 10⁵
//  1 <= nums[i], minK, maxK <= 10⁶
//
//
//  Related Topics 队列 数组 滑动窗口 单调队列 👍 77 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  long long countSubarrays(std::vector<int> &nums, int minK, int maxK) {
    if (minK > maxK)
      return 0;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
