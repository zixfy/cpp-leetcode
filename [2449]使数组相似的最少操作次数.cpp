// 给你两个正整数数组 nums 和 target ，两个数组长度相等。
//
//  在一次操作中，你可以选择两个 不同 的下标 i 和 j ，其中 0 <= i, j <
//  nums.length ，并且：
//
//
//  令 nums[i] = nums[i] + 2 且
//  令 nums[j] = nums[j] - 2 。
//
//
//  如果两个数组中每个元素出现的频率相等，我们称两个数组是 相似 的。
//
//  请你返回将 nums 变得与 target 相似的最少操作次数。测试数据保证 nums
//  一定能变得与 target 相似。
//
//
//
//  示例 1：
//
//
// 输入：nums = [8,12,6], target = [2,14,10]
// 输出：2
// 解释：可以用两步操作将 nums 变得与 target 相似：
//- 选择 i = 0 和 j = 2 ，nums = [10,12,4] 。
//- 选择 i = 1 和 j = 2 ，nums = [10,14,2] 。
// 2 次操作是最少需要的操作次数。
//
//
//  示例 2：
//
//
// 输入：nums = [1,2,5], target = [4,1,3]
// 输出：1
// 解释：一步操作可以使 nums 变得与 target 相似：
//- 选择 i = 1 和 j = 2 ，nums = [1,4,3] 。
//
//
//  示例 3：
//
//
// 输入：nums = [1,1,1,1,1], target = [1,1,1,1,1]
// 输出：0
// 解释：数组 nums 已经与 target 相似。
//
//
//
//
//  提示：
//
//
//  n == nums.length == target.length
//  1 <= n <= 10⁵
//  1 <= nums[i], target[i] <= 10⁶
//  nums 一定可以变得与 target 相似。
//
//
//  Related Topics 贪心 数组 排序 👍 23 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  long long makeSimilar(vector<int> &nums, vector<int> &target) {
    auto f = [](const int a, const int b) {
      if ((a & 1) ^ (b & 1))
        return bool(a & 1);
      return a > b;
    };
    sort(nums.begin(), nums.end(), f);
    sort(target.begin(), target.end(), f);
    const auto n = nums.size();
    long long odd_above = 0, odd_below = 0, even_above = 0, even_below = 0;
    for (int i = 0; i < n; ++i) {
      int dif = abs(nums[i] - target[i]);
      if (nums[i] & 1)
        (nums[i] > target[i] ? odd_above : odd_below) += dif;
      else
        (nums[i] > target[i] ? even_above : even_below) += dif;
    }
    long long ans = 0;
    ans += abs(odd_below - odd_above) + min(odd_below, odd_above) + min(even_above, even_below);
    return ans >> 1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
