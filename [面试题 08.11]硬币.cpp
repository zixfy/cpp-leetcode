// 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
//
//  示例1:
//
//
//  输入: n = 5
//  输出：2
//  解释: 有两种方式可以凑成总金额:
// 5=5
// 5=1+1+1+1+1
//
//
//  示例2:
//
//
//  输入: n = 10
//  输出：4
//  解释: 有四种方式可以凑成总金额:
// 10=10
// 10=5+5
// 10=5+1+1+1+1+1
// 10=1+1+1+1+1+1+1+1+1+1
//
//
//  说明：
//
//  注意:
//
//  你可以假设：
//
//
//  0 <= n (总金额) <= 1000000
//
//
//  Related Topics 数组 数学 动态规划 👍 274 👎 0

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
constexpr int MOD = 1000000007;
class Solution {
public:
  int waysToChange(int n) {
    // dp[i] = dp[i-1] + dp[i-5]
    constexpr array<int, 4> coins{1, 5, 10, 25};
    constexpr auto max_coin_v = *max_element(coins.begin(), coins.end());
    vector  dp_init(n+1, 0);
    dp_init[0] = 1;

    for (auto coin : coins)
      for (int i = 1; i <= n; ++i)
        if (auto j = i - coin; j >= 0)
          dp_init[i] = (dp_init[i] + dp_init[j]) % MOD;

    return dp_init.back();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
