// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//  请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//
//
//  示例 1:
//
//
// 输入: [3,2,1,5,6,4] 和 k = 2
// 输出: 5
//
//
//  示例 2:
//
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
// 输出: 4
//
//
//
//  提示：
//
//
//  1 <= k <= nums.length <= 10⁴
//  -10⁴ <= nums[i] <= 10⁴
//
//
//
//
//
//  注意：本题与主站 215 题相同：
//  https://leetcode-cn.com/problems/kth-largest-element-in-an-
// array/
//
//  Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 68 👎 0
#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  int _findKth(vector<int> &nums, int i, int j, int k) {

    int base = nums[i];
    int p1 = i + 1, p2 = j + 1;
    while (p1 < p2) {
      if (nums[p1] >= base)
        ++p1;
      else
        swap(nums[p1], nums[--p2]);
    }
    swap(nums[i], nums[p1 - 1]);
    int cur_k = p1 - i;
    if (cur_k == k)
      return base;
    else if (cur_k > k)
      return _findKth(nums, i, p1 - 2, k);
    return _findKth(nums, p1, j, k - cur_k);
  }

public:
  int findKthLargest(vector<int> &nums, int k) {
    return _findKth(nums, 0, nums.size() - 1, k);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
