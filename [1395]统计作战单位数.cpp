// n 名士兵站成一排。每个士兵都有一个 独一无二 的评分 rating 。
//
//  每 3 个士兵可以组成一个作战单位，分组规则如下：
//
//
//  从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为
//  rating[i]、rating[j]、rating[k] 作战单位需满足： rating[i] < rating[j] <
//  rating[k] 或者 rating[i] > rating[j] > rating[
// k] ，其中 0 <= i < j < k < n
//
//
//  请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。
//
//
//
//  示例 1：
//
//
// 输入：rating = [2,5,3,4,1]
// 输出：3
// 解释：我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
//
//
//  示例 2：
//
//
// 输入：rating = [2,1,3]
// 输出：0
// 解释：根据题目条件，我们无法组建作战单位。
//
//
//  示例 3：
//
//
// 输入：rating = [1,2,3,4]
// 输出：4
//
//
//
//
//  提示：
//
//
//  n == rating.length
//  3 <= n <= 1000
//  1 <= rating[i] <= 10^5
//  rating 中的元素都是唯一的
//
//
//  Related Topics 树状数组 数组 动态规划 👍 127 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)

template <typename T> class BITree {
public:
  BITree() = delete;
  BITree(const std::vector<T> a) : _n(a.size()) {
    _pre.resize(_n + 1, T());
    for (auto i = 1; i <= _n; ++i) {
      _pre[i] += a[i - 1];
      int j = i + low_bit(i);
      if (j <= _n)
        _pre[j] += _pre[i];
    }
  }
  void add(int x, const T &k) {
    x += 1;
    while (x <= _n) { // 不能越界
      _pre[x] = _pre[x] + k;
      x = x + low_bit(x);
    }
  }
  T get(int l, int r) { return get_sum(r + 1) - get_sum(l); }

private:
  inline int low_bit(int x) { return x & -x; }
  T get_sum(int x) { // a[1]..a[x]的和
    T ans{};
    while (x > 0) {
      ans += _pre[x];
      x = x - low_bit(x);
    }
    return ans;
  }
  std::vector<T> _pre;
  std::size_t _n;
};
class Solution {
public:
  int numTeams(vector<int> &rating) {
    const auto n = rating.size();
    auto tmp = rating;
    std::sort(tmp.begin(), tmp.end());
    auto bit = BITree(vector(n, 0));
    vector dp1(n, 0), dp2(n, 0);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      auto seq =
          std::lower_bound(tmp.begin(), tmp.end(), rating[i]) - tmp.begin();
      dp1[i] = bit.get(0, seq - 1);
      dp2[i] = bit.get(seq + 1, n - 1);
      bit.add(seq, 1);
    }
    bit = BITree(vector(n, 0));
    for (int i = n - 1; i > -1; --i) {
      auto seq =
          std::lower_bound(tmp.begin(), tmp.end(), rating[i]) - tmp.begin();
      ans += dp1[i] * bit.get(seq + 1, n - 1) + dp2[i] * bit.get(0, seq - 1);
      bit.add(seq, 1);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
