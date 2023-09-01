// 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,3]
// 输出：6
//
//
//  示例 2：
//
//
// 输入：nums = [1,2,3,4]
// 输出：24
//
//
//  示例 3：
//
//
// 输入：nums = [-1,-2,-3]
// 输出：-6
//
//
//
//
//  提示：
//
//
//  3 <= nums.length <= 10⁴
//  -1000 <= nums[i] <= 1000
//
//
//  Related Topics 数组 数学 排序 👍 449 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    auto const n = nums.size();
    std::sort(nums.begin(), nums.end());
    return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
               max(nums[n - 1] * nums[n - 2] * nums[0],
                   nums[n - 1] * nums[1] * nums[0]));
  }
};
// leetcode submit region end(Prohibit modification and deletion)
