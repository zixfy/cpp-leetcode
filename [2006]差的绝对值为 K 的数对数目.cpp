// 给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j
// 且 |nums[i] - nums[j]| == k 。
//
//
//  |x| 的值定义为：
//
//
//  如果 x >= 0 ，那么值为 x 。
//  如果 x < 0 ，那么值为 -x 。
//
//
//
//
//  示例 1：
//
//  输入：nums = [1,2,2,1], k = 1
// 输出：4
// 解释：差的绝对值为 1 的数对为：
//- [1,2,2,1]
//- [1,2,2,1]
//- [1,2,2,1]
//- [1,2,2,1]
//
//
//  示例 2：
//
//  输入：nums = [1,3], k = 3
// 输出：0
// 解释：没有任何数对差的绝对值为 3 。
//
//
//  示例 3：
//
//  输入：nums = [3,2,1,5,4], k = 2
// 输出：3
// 解释：差的绝对值为 2 的数对为：
//- [3,2,1,5,4]
//- [3,2,1,5,4]
//- [3,2,1,5,4
// History
//
// Ask any technical question or use shortcuts for code selected in your IDE
//
//
//" Generate code in Java to convert a number from one base to another "
//
//" Generate code to implement a simple REST API in go "
//
//" How to set global variables in git "
//
//" Create an encrypted s3 bucket using the AWS CLI "
//
//" Explain B+ trees, give an example with code "
//
// Ask any technical question… (CTRL+Enter for newline)
// Shortcuts
//
// Explain Code
//
// Generate Comment
//
// Performance Check
//
// Security Check
//
// Style Check
//
// Improve Readability
//
// Clean Code
//
// Generate unit tests
// The latest version 1.0.135 of Bito is ava]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 200
//  1 <= nums[i] <= 100
//  1 <= k <= 99
//
//
//  Related Topics 数组 哈希表 计数 👍 92 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    int ans = 0;
    unordered_map<int, int> cnt;
    for (auto n : nums)
      cnt[n]++;
    for (auto n : nums) {
      cnt[n]--;
      ans += cnt[n - k] + cnt[n + k];
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
