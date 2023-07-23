// 给你两个整数数组 nums1 和 nums2
// ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现
// 次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
//
//
//
//  示例 1：
//
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2,2]
//
//
//  示例 2:
//
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[4,9]
//
//
//
//  提示：
//
//
//  1 <= nums1.length, nums2.length <= 1000
//  0 <= nums1[i], nums2[i] <= 1000
//
//
//
//
//  进阶：
//
//
//  如果给定的数组已经排好序呢？你将如何优化你的算法？
//  如果 nums1 的大小比 nums2 小，哪种方法更优？
//  如果 nums2
//  的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
//
//
//  Related Topics 数组 哈希表 双指针 二分查找 排序 👍 986 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using std::vector;
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      nums1.swap(nums2);
    std::unordered_map<int, int> cnt;
    for (auto num : nums1)
      cnt[num]++;
    vector<int> ans;
    for (auto num : nums2) {
      if (cnt.count(num) && cnt[num] > 0)
        cnt[num]--, ans.emplace_back(num);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
