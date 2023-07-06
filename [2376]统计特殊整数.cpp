// 如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。
//
//  给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。
//
//
//
//  示例 1：
//
//
// 输入：n = 20
// 输出：19
// 解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19
// 个特殊整数。
//
//
//  示例 2：
//
//
// 输入：n = 5
// 输出：5
// 解释：1 到 5 所有整数都是特殊整数。
//
//
//  示例 3：
//
//
// 输入：n = 135
// 输出：110
// 解释：从 1 到 135 总共有 110 个整数是特殊整数。
// 不特殊的部分数字为：22 ，114 和 131 。
//
//
//
//  提示：
//
//
//  1 <= n <= 2 * 10⁹
//
//
//  Related Topics 数学 动态规划 👍 55 👎 0
#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << " " << p.second << ")";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    o << a << ", ";
  return o << "]";
}
class Solution {
public:
  int countSpecialNumbers(int n) {
    // dp[i][restricted] = dp[i-1][restrict] + new_digits - 1
    //
    vector<int> digits;
    while (n)
      digits.emplace_back(n % 10), n /= 10;
    reverse(digits.begin(), digits.end());
    cout << digits << endl;
    vector dp(digits.size() + 1, make_pair(0, 0));
    dp[0].first = 9;
    dp[0].second = digits[0];


    return dp[digits.size() - 1].second;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
