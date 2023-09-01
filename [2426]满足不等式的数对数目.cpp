// 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两个数组的大小都为 n
// ，同时给你一个整数 diff ，统计满足以下条件的 数对 (i, j) ：
//
//
//  0 <= i < j <= n - 1 且
//  nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
//
//
//  请你返回满足条件的 数对数目 。
//
//
//
//  示例 1：
//
//  输入：nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
// 输出：3
// 解释：
// 总共有 3 个满足条件的数对：
// 1. i = 0, j = 1：3 - 2 <= 2 - 2 + 1 。因为 i < j 且 1 <= 1
// ，这个数对满足条件。
// 2. i = 0, j = 2：3 - 5 <= 2 - 1 + 1 。因为 i < j 且 -2 <= 2
// ，这个数对满足条件。
// 3. i = 1, j = 2：2 - 5 <= 2 - 1 + 1 。因为 i < j 且 -3 <= 2
// ，这个数对满足条件。 所以，我们返回 3 。
//
//
//  示例 2：
//
//  输入：nums1 = [3,-1], nums2 = [-2,2], diff = -1
// 输出：0
// 解释：
// 没有满足条件的任何数对，所以我们返回 0 。
//
//
//
//
//  提示：
//
//
//  n == nums1.length == nums2.length
//  2 <= n <= 10⁵
//  -10⁴ <= nums1[i], nums2[i] <= 10⁴
//  -10⁴ <= diff <= 10⁴
//
//
//  Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 16 👎
//  0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

template <typename T> class BITree {
public:
  BITree() = delete;
  BITree(const std::vector<T> &a) : _n(a.size()) {
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
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
    auto const n = nums1.size();
    for (int i = 0; i < n; ++i)
      nums1[i] -= nums2[i];
    nums2 = nums1;
    std::generate_n(back_inserter(nums2), n, [i = 0, &nums1, diff]() mutable {
      return nums1[i++] + diff;
    });
    std::sort(nums2.begin(), nums2.end());
    nums2.erase(std::unique(nums2.begin(), nums2.end()), nums2.end());
    auto const m = nums2.size();
    auto bit = BITree(vector(m, 0));
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      auto n2 = std::lower_bound(nums2.begin(), nums2.end(), nums1[i] + diff) -
                nums2.begin();
      auto n1 = std::lower_bound(nums2.begin(), nums2.end(), nums1[i]) -
                nums2.begin();
      ans += bit.get(0, n2);
      bit.add(n1, 1);
    }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
