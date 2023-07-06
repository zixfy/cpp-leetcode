// 给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k
// 个相邻的非空子数组 。 分数 由每个子数组内的平均值的总和构成。
//
//  注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数。
//
//  返回我们所能得到的最大 分数 是多少。答案误差在 10⁻⁶ 内被视为是正确的。
//
//
//
//  示例 1:
//
//
// 输入: nums = [9,1,2,3,9], k = 3
// 输出: 20.00000
// 解释:
// nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9
// = 20. 我们也可以把 nums 分成[9, 1], [2], [3, 9]. 这样的分组得到的分数为 5 + 2
// + 6 = 13, 但不是最大值.
//
//
//  示例 2:
//
//
// 输入: nums = [1,2,3,4,5,6,7], k = 4
// 输出: 20.50000
//
//
//
//
//  提示:
//
//
//  1 <= nums.length <= 100
//  1 <= nums[i] <= 10⁴
//  1 <= k <= nums.length
//
//
//  Related Topics 数组 动态规划 前缀和 👍 390 👎 0
#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
template <typename Iterator> class PrefixView {
public:
  using value_type = typename std::iterator_traits<Iterator>::value_type;
  using size_type = typename std::vector<value_type>::size_type;
  PrefixView() = delete;
  explicit PrefixView(Iterator begin, Iterator end) {
    value_type sum{};
    for (auto it = begin; it != end; ++it)
      sum += *it, _prefix.emplace_back(sum);
  }
  value_type get_range_sum(int l, int r) {
    return l > 0 ? (_prefix[r] - _prefix[l - 1]) : _prefix[r];
  }
  auto get_range_avg(int l, int r) {
    return static_cast<double>(get_range_sum(l, r)) / (r - l + 1);
  }
  const value_type &get_prefix(int i) { return _prefix[i]; }

private:
  std::vector<value_type> _prefix;
};
class Solution {
public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    // dp[i][g] = dp[j][g - 1] + avg(nums[j + 1, ... i])
    // i >= g, j >= g - 1
    auto pre = PrefixView(nums.begin(), nums.end());
    const auto n = nums.size();
    vector dp(n, .0);
    for (int i = 0; i < n; ++i)
      dp[i] = pre.get_range_avg(0, i);
    for (int g = 1; g < k; ++g) {
      for (int i = n - 1; i >= g; --i)
        for (int j = i - 1; j >= g - 1; --j) {
          dp[i] = max(dp[i], dp[j] + pre.get_range_avg(j + 1, i));
        }
    }
    return dp[n - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
