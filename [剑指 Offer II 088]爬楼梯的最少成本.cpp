//数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。 
//
// 每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。 
//
// 请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。 
//
// 
//
// 示例 1： 
//
// 
//输入：cost = [10, 15, 20]
//输出：15
//解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
// 
//
// 示例 2： 
//
// 
//输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//输出：6
//解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
// 
//
// 
//
// 提示： 
//
// 
// 2 <= cost.length <= 1000 
// 0 <= cost[i] <= 999 
// 
//
// 
//
// 
// 注意：本题与主站 746 题相同： https://leetcode-cn.com/problems/min-cost-climbing-stairs/ 
//
//
// Related Topics 数组 动态规划 👍 74 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/2/22.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    const int n = cost.size();
    vector<int> dp(n);
    dp[n - 1] = cost[n - 1];
    dp[n - 2] = cost[n - 2];
    for (int i = n - 3; i > -1; i--)
      dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    return min(dp[0], dp[1]);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
