// 给你一个整数数组 nums 和一个整数 k ，请你返回 非空
// 子序列元素和的最大值，子序列需要满足：子序列中每两个 相邻 的整数 nums[i] 和
// nums[j] ，它们在原数组中的下标 i 和 j 满足 i < j 且 j - i <= k 。
//
//  数组的子序列定义为：将数组中的若干个数字删除（可以删除 0
//  个数字），剩下的数字按照原本的顺序排布。
//
//
//
//  示例 1：
//
//  输入：nums = [10,2,-10,5,20], k = 2
// 输出：37
// 解释：子序列为 [10, 2, 5, 20] 。
//
//
//  示例 2：
//
//  输入：nums = [-1,-2,-3], k = 1
// 输出：-1
// 解释：子序列必须是非空的，所以我们选择最大的数字。
//
//
//  示例 3：
//
//  输入：nums = [10,-2,-10,-5,20], k = 2
// 输出：23
// 解释：子序列为 [10, -2, -5, 20] 。
//
//
//
//
//  提示：
//
//
//  1 <= k <= nums.length <= 10^5
//  -10^4 <= nums[i] <= 10^4
//
//
//  Related Topics 队列 数组 动态规划 滑动窗口 单调队列 堆（优先队列） 👍 118 👎
//  0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
using xy = pair<int, int>;
struct cmp {
  bool operator()(const xy &a, const xy &b) { return a.first < b.first; }
};
class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    priority_queue<xy, vector<xy>, cmp> q;
    auto maxx = max_element(nums.begin(), nums.end());
    if (*maxx < 0)
      return *maxx;
    int ans = numeric_limits<int>::min();
    q.emplace(0, -1);

    for (int i = 0; i < nums.size(); ++i) {
      while (i - q.top().second > k)
        q.pop();
      int t = max(q.top().first, 0) + nums[i];
      ans = max(ans, t);
      q.emplace(t, i);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
