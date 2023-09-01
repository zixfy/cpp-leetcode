// 给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质：
// counts[i] 的值是 nums[i] 右侧小于 nums[i] 的元素的数量。
//
//
//
//  示例 1：
//
//
// 输入：nums = [5,2,6,1]
// 输出：[2,1,1,0]
// 解释：
// 5 的右侧有 2 个更小的元素 (2 和 1)
// 2 的右侧仅有 1 个更小的元素 (1)
// 6 的右侧有 1 个更小的元素 (1)
// 1 的右侧有 0 个更小的元素
//
//
//  示例 2：
//
//
// 输入：nums = [-1]
// 输出：[0]
//
//
//  示例 3：
//
//
// 输入：nums = [-1,-1]
// 输出：[0,0]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  -10⁴ <= nums[i] <= 10⁴
//
//
//  Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 1000
//  👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

template <typename T> class BITree {
public:
  BITree() = delete;
  BITree(const std::vector<T>& a) : _n(a.size()) {
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
  vector<int> countSmaller(vector<int> &nums) {
    auto const n = nums.size();
    auto cp = nums, ans = nums;
    std::sort(cp.begin(), cp.end());
    cp.erase(std::unique(cp.begin(), cp.end()), cp.end());
    auto t = BITree(vector(cp.size(), 0));
    for (auto iter = nums.rbegin(); iter != nums.rend(); ++iter) {
      auto cur = *iter;
      auto idx = std::distance(cp.begin(), std::lower_bound(cp.begin(), cp.end(), cur));
//      cout << cur << ", " << idx << endl;
      t.add(idx, 1);
      auto cnt = t.get(0, idx - 1);
      ans[n - 1 - std::distance(nums.rbegin(), iter)] = cnt;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
