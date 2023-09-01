// 给定一个非负整数数组
// A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。
//
//  返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引
//  i，使得 A1[i] != A2[i]。
//
//
//
//  示例 1：
//
//  输入：[1,17,8]
// 输出：2
// 解释：
//[1,8,17] 和 [17,8,1] 都是有效的排列。
//
//
//  示例 2：
//
//  输入：[2,2,2]
// 输出：1
//
//
//
//
//  提示：
//
//
//  1 <= A.length <= 12
//  0 <= A[i] <= 1e9
//
//
//  Related Topics 位运算 数组 数学 动态规划 回溯 状态压缩 👍 112 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
using i64 = int64_t;
class Solution {
  unordered_set<int> sqs;

public:
  Solution() {
    i64 b = 0;
    while (b * b <= numeric_limits<int>::max())
      sqs.insert(b * b), ++b;
  }
  int numSquarefulPerms(vector<int> &nums) {
    auto const n = nums.size();
    auto expn = 1 << n;
    vector dp(expn, vector(n, 0));
    for (int i = 0; i < n; ++i)
      dp[1 << i][i] = 1;
    for (int s = 1; s < expn; ++s) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if ((s & (1 << i)) && !(s & (1 << j)) && sqs.count(nums[i] + nums[j]))
            dp[s | (1 << j)][j] += dp[s][i];
    }
    unordered_map<int, int> cnt;
    std::for_each(nums.begin(), nums.end(), [&cnt](int num) { cnt[num]++; });
    auto ret = std::accumulate(dp.back().begin(), dp.back().end(), 0ll);
    for (auto [k, v] : cnt) {
      for (int d = 2; d <= v; ++d)
        ret /= d;
    }
    return ret;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
