// Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，排成一行；每堆都有 正
// 整数颗石子，数目为 piles[i] 。
//
//  游戏以谁手中的石子最多来决出胜负。石子的 总数 是 奇数 ，所以没有平局。
//
//  Alice 和 Bob 轮流进行，Alice 先开始 。 每回合，玩家从行的 开始 或 结束
//  处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此
// 时手中 石子最多 的玩家 获胜 。
//
//  假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回 true ，当 Bob
//  赢得比赛时返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：piles = [5,3,4,5]
// 输出：true
// 解释：
// Alice 先开始，只能拿前 5 颗或后 5 颗石子 。
// 假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
// 如果 Bob 拿走前 3 颗，那么剩下的是 [4,5]，Alice 拿走后 5 颗赢得 10 分。
// 如果 Bob 拿走后 5 颗，那么剩下的是 [3,4]，Alice 拿走后 4 颗赢得 9 分。
// 这表明，取前 5 颗石子对 Alice 来说是一个胜利的举动，所以返回 true 。
//
//
//  示例 2：
//
//
// 输入：piles = [3,7,2,3]
// 输出：true
//
//
//
//
//  提示：
//
//
//  2 <= piles.length <= 500
//  piles.length 是 偶数
//  1 <= piles[i] <= 500
//  sum(piles[i]) 是 奇数
//
//
//  Related Topics 数组 数学 动态规划 博弈 👍 489 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
using namespace std;
template <typename Container> class PrefixView {
public:
  using Iter = typename Container::iterator;
  using T = typename std::iterator_traits<Iter>::value_type;
  PrefixView() = delete;
  explicit PrefixView(Iter begin, Iter end) {
    T sum{};
    for (auto it = begin; it != end; ++it)
      sum += *it, _prefix.emplace_back(sum);
  }
  PrefixView(Container &vec) : PrefixView(vec.begin(), vec.end()) {}
  T get_range_sum(int l, int r) {
    return l > 0 ? (_prefix[r] - _prefix[l - 1]) : _prefix[r];
  }
  const T &get_prefix(int i) { return _prefix[i]; }
  friend class Solution;

private:
  std::vector<T> _prefix;
};
class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    // dp[i][j] = dp[i-1][j]
    const auto n = piles.size();
    auto pre = PrefixView(piles);
    cout << pre._prefix << endl;
    vector dp(n, vector(n, 0));
    for (int len = 0; len < n; ++len)
      dp[len][len] = piles[len];
    for (int len = 2; len <= n; ++len)
      for (int i = 0, j = len - 1; j < n; ++i, ++j) {
//        cout << i << ", " << j << ", " << dp[i][j] << endl;
        dp[i][j] = pre.get_range_sum(i, j) - min(dp[i + 1][j], dp[i][j - 1]);
      }
    //      cout << dp << endl;
    return dp[0][n - 1] * 2 > pre.get_range_sum(0, n - 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
