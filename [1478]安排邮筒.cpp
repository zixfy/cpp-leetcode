// 给你一个房屋数组houses 和一个整数 k ，其中 houses[i] 是第 i
// 栋房子在一条街上的位置，现需要在这条街上安排 k 个邮筒。
//
//  请你返回每栋房子与离它最近的邮筒之间的距离的 最小 总和。
//
//  答案保证在 32 位有符号整数范围以内。
//
//
//
//  示例 1：
//
//
//
//  输入：houses = [1,4,8,10,20], k = 3
// 输出：5
// 解释：将邮筒分别安放在位置 3， 9 和 20 处。
// 每个房子到最近邮筒的距离和为 |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 。
//
//
//  示例 2：
//
//
//
//  输入：houses = [2,3,5,12,18], k = 2
// 输出：9
// 解释：将邮筒分别安放在位置 3 和 14 处。
// 每个房子到最近邮筒距离和为 |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9 。
//
//

// 示例 3：
//
// 输入：houses = [7,4,6,1], k = 1
// 输出：8
//
//
// 示例 4：
//
// 输入：houses = [3,6,14,10], k = 4
// 输出：0
//
//
//
//
// 提示：
//
//
// n == houses.length
// 1 <= n <= 100
// 1 <= houses[i] <= 10^4
// 1 <= k <= n
// 数组 houses 中的整数互不相同。
//
//
// Related Topics 数组 数学 动态规划 排序 👍 115 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}
class Solution {
public:
  int minDistance(vector<int> &houses, int k) {
    sort(houses.begin(), houses.end());
    const auto n = houses.size();
    vector cost(n, vector(n, 0));
    vector dp(n, 0);
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) {
        int tmp = accumulate(houses.begin() + i, houses.begin() + j + 1,
                             -(j - i + 1) * houses[i]);
        int base = tmp;
        for (int k = i + 1; k <= j; ++k)
          tmp += (k + k - i - j - 1) * (houses[k] - houses[k - 1]),
              base = min(base, tmp);
        cost[i][j] = base;
//        cout << make_tuple(i, j, cost[i][j]) << endl;
      }
    for (int i = 0; i < n; ++i)
      dp[i] = cost[0][i];
    for (int g = 1; g < k; ++g) {
      for (int i = n - 1; i >= g; --i)
        for (int j = i - 1; j >= g - 1; --j)
          dp[i] = min(dp[i], dp[j] + cost[j + 1][i]);
    }
    return dp[n - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
