// 你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。
//
//  你有一堆可以焊接在一起的钢筋 rods。举个例子，如果钢筋的长度为 1、2 和
//  3，则可以将它们焊接在一起形成长度为 6 的支架。
//
//  返回 广告牌的最大可能安装高度 。如果没法安装广告牌，请返回 0 。
//
//
//
//  示例 1：
//
//
// 输入：[1,2,3,6]
// 输出：6
// 解释：我们有两个不相交的子集 {1,2,3} 和 {6}，它们具有相同的和 sum = 6。
//
//
//  示例 2：
//
//
// 输入：[1,2,3,4,5,6]
// 输出：10
// 解释：我们有两个不相交的子集 {2,3,5} 和 {4,6}，它们具有相同的和 sum = 10。
//
//  示例 3：
//
//
// 输入：[1,2]
// 输出：0
// 解释：没法安装广告牌，所以返回 0。
//
//
//
//  提示：
//
//
//  0 <= rods.length <= 20
//  1 <= rods[i] <= 1000
//  sum(rods[i]) <= 5000
//
//
//  Related Topics 数组 动态规划 👍 142 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    // dp[i] = max(lower_bound of i)
    // dp[i] += j if dp[i] + j <= i
    // dp[i+j]=max(dp[i], dp[i+j]);
    // dp + j , dp
    // dp[i][j]=max(dp[i-1][j], dp[i-1][j+r[i]], dp[i-1][j-r[i]]+)
    // dp[i][j] = max(~, dp[i][j+r[i]] + r[i], dp[i][j-r[i])
    //
    auto sumy = std::accumulate(rods.begin(), rods.end(), 0);
    // -sumy, sumy
    vector dp(sumy + 1, 0);
    vector<char> vis(sumy + 1, 0);
    vis[0] = 1;
    for (auto r : rods) {
      auto tmp = dp;
      auto tmp2 = vis;
      for (int j = 0; j <= sumy; ++j) {
        if (tmp2[j]) {
          if (auto nj = j + r; nj <= sumy)
            vis[nj] = true, dp[nj] = max(dp[nj], tmp[j]);
          auto nj = abs(j - r);
            vis[nj] = true, dp[nj] = max(dp[nj], tmp[j] + min(j, r));
        }
      }
    }
    return dp[0];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
