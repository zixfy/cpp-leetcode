// 给你一个整数数组 nums ，它包含 2 * n 个整数。
//
//  你需要将 nums 划分成 n 个数对，满足：
//
//
//  每个元素 只属于一个 数对。
//  同一数对中的元素 相等 。
//
//
//  如果可以将 nums 划分成 n 个数对，请你返回 true ，否则返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：nums = [3,2,3,2,2,2]
// 输出：true
// 解释：
// nums 中总共有 6 个元素，所以它们应该被划分成 6 / 2 = 3 个数对。
// nums 可以划分成 (2, 2) ，(3, 3) 和 (2, 2) ，满足所有要求。
//
//
//  示例 2：
//
//
// 输入：nums = [1,2,3,4]
// 输出：false
// 解释：
// 无法将 nums 划分成 4 / 2 = 2 个数对且满足所有要求。
//
//
//
//
//  提示：
//
//
//  nums.length == 2 * n
//  1 <= n <= 500
//  1 <= nums[i] <= 500
//
//
//  Related Topics 位运算 数组 哈希表 计数 👍 25 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_multiset cnt(nums.begin(), nums.end());
    return std::accumulate(cnt.begin(), cnt.end(), true, [&](bool b, int v) {
      return b && ! (cnt.count(v) & 1);
    });
  }
};
// leetcode submit region end(Prohibit modification and deletion)
