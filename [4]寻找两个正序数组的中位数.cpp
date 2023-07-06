// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和
// nums2。请你找出并返回这两个正序数组的 中位数 。
//
//  算法的时间复杂度应该为 O(log (m+n)) 。
//
//
//
//  示例 1：
//
//
// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
//
//
//  示例 2：
//
//
// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//
//
//
//
//
//
//  提示：
//
//
//  nums1.length == m
//  nums2.length == n
//  0 <= m <= 1000
//  0 <= n <= 1000
//  1 <= m + n <= 2000
//  -10⁶ <= nums1[i], nums2[i] <= 10⁶
//
//
//  Related Topics 数组 二分查找 分治 👍 6482 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
inline int gety(const vector<int> &num, int i) {
  if (i < 0)
    return numeric_limits<int>::min();
  if (i == num.size())
    return numeric_limits<int>::max();
  return num[i];
}
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      nums1.swap(nums2);
    auto n = nums1.size() + nums2.size();
    auto half_n = (n + 1) >> 1;
    int l = 0, r = nums1.size(), p = 0;
    while (l <= r) {
      p = (l + r) >> 1;
      if (gety(nums1, p - 1) > gety(nums2, half_n - p))
        r = p - 1;
      else if (gety(nums1, p) < gety(nums2, half_n - p - 1))
        l = p + 1;
      else
        break;
    }
//    cout << p-1 << " " << half_n-p-1 << endl;
    return (n & 1) ? max(gety(nums1, p - 1), gety(nums2, half_n - p - 1))
                   : (max(gety(nums1, p - 1), gety(nums2, half_n - p - 1)) +
                      min(gety(nums1, p), gety(nums2, half_n - p))) *
                         .5;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
