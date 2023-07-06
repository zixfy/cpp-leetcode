// 给你一个整数数组 nums 和一个整数 k 。你需要将这个数组划分到 k
// 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。
//
//  一个子集的 不兼容性 是该子集里面最大值和最小值的差。
//
//  请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值
//  ，如果无法分成分成 k 个子集，返回 -1 。
//
//  子集的定义是数组中一些数字的集合，对数字顺序没有要求。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,1,4], k = 2
// 输出：4
// 解释：最优的分配是 [1,2] 和 [1,4] 。
// 不兼容性和为 (2-1) + (4-1) = 4 。
// 注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2
// 个相同的元素，所以不可行。
//
//  示例 2：
//
//
// 输入：nums = [6,3,8,1,3,1,2,2], k = 4
// 输出：6
// 解释：最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
// 不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。
//
//
//  示例 3：
//
//
// 输入：nums = [5,3,3,6,3,3], k = 3
// 输出：-1
// 解释：没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。
//
//
//
//
//  提示：
//
//
//  1 <= k <= nums.length <= 16
//  nums.length 能被 k 整除。
//  1 <= nums[i] <= nums.length
//
//
//  Related Topics 位运算 数组 动态规划 状态压缩 👍 131 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
constexpr int MAXX = numeric_limits<int>::max() / 2;
class Solution {
public:
  int minimumIncompatibility(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    const auto n = nums.size();
    const auto exp_n = 1 << n;
    int frac = n / k;
    vector dp(exp_n, MAXX);
    vector cost(exp_n, MAXX);
    for (int s = 0; s < exp_n; ++s) {
      auto cnt = 0;
      set<int> pool;
      bool v = true;
      for (int i = 0; i < n; ++i)
        if (s & (1 << i)) {
          if (++cnt > frac || pool.count(nums[i])) {
            v = false;
            break;
          }
          pool.insert(nums[i]);
        }
      if (v && (cnt == frac))
        cost[s] = (*pool.rbegin()) - (*pool.begin());
    }
    dp[0] = 0;
    for (int s = 0; s < exp_n; ++s) {
      if (dp[s] == MAXX)
        continue;
      unordered_map<int, int> seen;
      for (int i = 0; i < n; i++)
        if ((s & (1 << i)) == 0)
          seen[nums[i]] = 1 << i;
      if (seen.size() < frac)
        continue;
      int wild = 0;
      for (auto &pair : seen)
        wild |= pair.second;

      for (int nxt = wild; nxt; nxt = (nxt - 1) & wild) {
        dp[s | nxt] = min(dp[s | nxt], dp[s] + cost[nxt]);
        //        cout << (s | nxt) << " " << dp[s | nxt] << endl;
      }
    }
    return (dp[exp_n - 1] == MAXX) ? -1 : dp[exp_n - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
