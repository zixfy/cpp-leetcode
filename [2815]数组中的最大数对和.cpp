//给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。 
//
// 返回最大和，如果不存在满足题意的数字对，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [51,71,17,24,42]
//输出：88
//解释：
//i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。 
//i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
//可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。 
//
// 示例 2： 
//
// 输入：nums = [1,2,3,4]
//输出：-1
//解释：不存在数对满足数位上最大的数字相等。
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 100 
// 1 <= nums[i] <= 10⁴ 
// 
//
// 👍 2 👎 0


#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
using std::vector;
struct Data{
  int min1 = std::numeric_limits<int>::min() / 2;
  int min2 = std::numeric_limits<int>::min() / 2;
  void operator+=(int i) {

  }
};
class Solution {
public:
    int maxSum(vector<int>& nums) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




