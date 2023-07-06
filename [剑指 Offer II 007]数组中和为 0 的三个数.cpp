// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i
// != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//
//  你返回所有和为 0 且不重复的三元组。
//
//  注意：答案中不可以包含重复的三元组。
//
//
//
//
//
//  示例 1：
//
//
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
//
//
//  示例 2：
//
//
// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。
//
//
//  示例 3：
//
//
// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。
//
//
//
//
//  提示：
//
//
//  3 <= nums.length <= 3000
//  -10⁵ <= nums[i] <= 10⁵
//
//
//
//  注意：本题与主站 15 题相同：leetcode.cn/problems/3sum/
//
//  Related Topics 数组 双指针 排序 👍 112 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return {};
    sort(nums.begin(), nums.end());
    const size_t n = nums.size();
    vector<vector<int>> ans;
    for (size_t i = 0; i < n - 2; ++i) {
      while (i && i < n && nums[i] == nums[i - 1])
        ++i;
      size_t j = i + 1, k = n - 1;
      while (j < k) {
        while (j < k && (nums[i] + nums[k] + nums[j]) < 0)
          ++j;
        int sum = nums[i] + nums[k] + nums[j];
        if (j < k && !sum) {
          ans.emplace_back(initializer_list<int>{nums[i], nums[j], nums[k]});
        }
        --k;
        while (j < k && nums[k] == nums[k + 1])
          --k;
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
