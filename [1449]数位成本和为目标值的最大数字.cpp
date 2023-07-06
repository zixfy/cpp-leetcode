// 给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大
// 整数：
//
//
//  给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
//  总成本必须恰好等于 target 。
//  添加的数位中没有数字 0 。
//
//
//  由于答案可能会很大，请你以字符串形式返回。
//
//  如果按照上述要求无法得到任何整数，请你返回 "0" 。
//
//
//
//  示例 1：
//
//
// 输入：cost = [4,3,2,5,6,7,2,5,5], target = 9
// 输出："7772"
// 解释：添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772"
// 的代价为 2*3+ 3*1 = 9 。 "977" 也是满足要 求的数字，但 "7772" 是较大的数字。
//  数字     成本
//   1  ->   4
//   2  ->   3
//   3  ->   2
//   4  ->   5
//   5  ->   6
//   6  ->   7
//   7  ->   2
//   8  ->   5
//   9  ->   5
//
//
//  示例 2：
//
//
// 输入：cost = [7,6,5,5,5,6,8,7,8], target = 12
// 输出："85"
// 解释：添加数位 '8' 的成本是 7 ，添加数位 '5' 的成本是 5 。"85" 的成本为 7 + 5
// = 12 。
//
//
//  示例 3：
//
//
// 输入：cost = [2,4,6,2,4,6,4,4,4], target = 5
// 输出："0"
// 解释：总成本是 target 的条件下，无法生成任何整数。
//
//
//  示例 4：
//
//
// 输入：cost = [6,10,15,40,40,40,40,40,40], target = 47
// 输出："32211"
//
//
//
//
//  提示：
//
//
//  cost.length == 9
//  1 <= cost[i] <= 5000
//  1 <= target <= 5000
//
//
//  Related Topics 数组 动态规划 👍 163 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  if (!v.empty())
    std::copy(v.begin(), v.end(), ostream_iterator<T, char>(o, ", "));
  return o << "]";
}
const string &maxx(const string &a, const string &b) {
  if (a.length() != b.length())
    return a.length() > b.length() ? a : b;
  for (size_t i{}; i < a.length(); ++i)
    if (a[i] > b[i])
      return a;
    else if (a[i] < b[i])
      return b;
  return a;
}
class Solution {
public:
  auto largestNumber(vector<int> &cost, int target) {
    vector<pair<bool, string>> dp(target + 1);
    //    int low_bd{114514};
    //    for (const auto &c: cost)
    //      low_bd = min(low_bd, c);
    dp[0].first = true;
    for (int t{1}; t <= target; ++t) {
      //      cout << dp << endl;

      for (int i{}; i < 9; ++i) {
        if (t >= cost[i] && dp[t - cost[i]].first)
          dp[t].first = true,
          dp[t].second =
              maxx(dp[t].second, to_string(i + 1) + dp[t - cost[i]].second);
      }
    }
    //    cout << dp << endl;
    return dp[target].first ? dp[target].second : "0";
  }
};
// leetcode submit region end(Prohibit modification and deletion)
