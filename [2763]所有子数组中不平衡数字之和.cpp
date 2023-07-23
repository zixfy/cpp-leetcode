// 一个长度为 n 下标从 0 开始的整数数组 arr 的 不平衡数字 定义为，在 sarr =
// sorted(arr) 数组中，满足以下条件的下标数目：
//
//
//  0 <= i < n - 1 ，和
//  sarr[i+1] - sarr[i] > 1
//
//
//  这里，sorted(arr) 表示将数组 arr 排序后得到的数组。
//
//  给你一个下标从 0 开始的整数数组 nums ，请你返回它所有 子数组 的 不平衡数字
//  之和。
//
//  子数组指的是一个数组中连续一段 非空 的元素序列。
//
//
//
//  示例 1：
//
//  输入：nums = [2,3,1,4]
// 输出：3
// 解释：总共有 3 个子数组有非 0 不平衡数字：
//- 子数组 [3, 1] ，不平衡数字为 1 。
//- 子数组 [3, 1, 4] ，不平衡数字为 1 。
//- 子数组 [1, 4] ，不平衡数字为 1 。
// 其他所有子数组的不平衡数字都是 0 ，所以所有子数组的不平衡数字之和为 3 。
//
//
//  示例 2：
//
//  输入：nums = [1,3,3,3,5]
// 输出：8
// 解释：总共有 7 个子数组有非 0 不平衡数字：
//- 子数组 [1, 3] ，不平衡数字为 1 。
//- 子数组 [1, 3, 3] ，不平衡数字为 1 。
//- 子数组 [1, 3, 3, 3] ，不平衡数字为 1 。
//- 子数组 [1, 3, 3, 3, 5] ，不平衡数字为 2 。
//- 子数组 [3, 3, 3, 5] ，不平衡数字为 1 。
//- 子数组 [3, 3, 5] ，不平衡数字为 1 。
//- 子数组 [3, 5] ，不平衡数字为 1 。
// 其他所有子数组的不平衡数字都是 0 ，所以所有子数组的不平衡数字之和为 8 。
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 1000
//  1 <= nums[i] <= nums.length
//
//
//  Related Topics 数组 哈希表 有序集合 👍 11 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int sumImbalanceNumbers(vector<int> &nums) {}
};
// leetcode submit region end(Prohibit modification and deletion)
