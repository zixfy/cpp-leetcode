//给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。 
//
// 请你找出并返回只出现一次的那个数。 
//
// 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,1,2,3,3,4,4,8,8]
//输出: 2
// 
//
// 示例 2: 
//
// 
//输入: nums =  [3,3,7,7,10,11,11]
//输出: 10
// 
//
// 
//
// 
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 10⁵ 
// 0 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 二分查找 👍 608 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    const int n = nums.size();
    int l = -1, r = n;
    // (l, r)
    while (r - l > 1) {
      int m = (r + l) >> 1;
      if (m < n - 1 && nums[m] == nums[m ^ 1])
        l = m;
      else if (m > 0 && nums[m] == nums[m - 1 + ((m & 1) << 1)])
        r = m;
      else return nums[m];
    }
    throw runtime_error("shit");
  }
};


//leetcode submit region end(Prohibit modification and deletion)
