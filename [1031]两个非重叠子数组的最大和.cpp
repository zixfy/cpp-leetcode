// 给你一个整数数组 nums 和两个整数 firstLen 和
// secondLen，请你找出并返回两个非重叠 子数组 中元素的最大和，长度分别为
// firstLen 和 secondLen 。
//
//  长度为 firstLen 的子数组可以出现在长为 secondLen
//  的子数组之前或之后，但二者必须是不重叠的。
//
//  子数组是数组的一个 连续 部分。
//
//
//
//  示例 1：
//
//
// 输入：nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
// 输出：20
// 解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
//
//
//  示例 2：
//
//
// 输入：nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
// 输出：29
// 解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
//
//
//  示例 3：
//
//
// 输入：nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
// 输出：31
// 解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
//
//
//
//
//  提示：
//
//
//  1 <= firstLen, secondLen <= 1000
//  2 <= firstLen + secondLen <= 1000
//  firstLen + secondLen <= nums.length <= 1000
//  0 <= nums[i] <= 1000
//
//
//  Related Topics 数组 动态规划 滑动窗口 👍 229 👎 0
#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen);
};

int Solution::maxSumTwoNoOverlap(vector<int> &nums, int firstLen,
                                 int secondLen) {
  const auto n{nums.size()};
  auto ans{-1};
  for (int j{}, i{-firstLen + 1}, sum1{}; j < n; ++j, ++i) {
    sum1 += nums[j];
    if (i > 0)
      sum1 -= nums[i - 1];
    for (int k = j + 1 - secondLen + 1, l = j + 1, sum2 = 0; l < n; ++k, ++l) {
      sum2 += nums[l];
      if (k > j + 1)
        sum2 -= nums[k - 1];
      if (k >= j + 1)
        ans = max(ans, sum1 + sum2);
    }
  }
  swap(firstLen, secondLen);
  for (int j{}, i{-firstLen + 1}, sum1{}; j < n; ++j, ++i) {
    sum1 += nums[j];
    if (i > 0)
      sum1 -= nums[i - 1];
    for (int k = j + 1 - secondLen + 1, l = j + 1, sum2 = 0; l < n; ++k, ++l) {
      sum2 += nums[l];
      if (k > j + 1)
        sum2 -= nums[k - 1];
      if (k >= j + 1)
        ans = max(ans, sum1 + sum2);
    }
  }
  // static_assert(is_same< decltype(i), size_t>::value);
  return ans;
}
// leetcode submit region end(Prohibit modification and deletion)
