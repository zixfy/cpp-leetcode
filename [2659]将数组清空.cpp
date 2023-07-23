// 给你一个包含若干 互不相同 整数的数组 nums ，你需要执行以下操作 直到数组为空
// ：
//
//
//  如果数组中第一个元素是当前数组中的 最小值 ，则删除它。
//  否则，将第一个元素移动到数组的 末尾 。
//
//
//  请你返回需要多少个操作使 nums 为空。
//
//
//
//  示例 1：
//
//
// 输入：nums = [3,4,-1]
// 输出：5
//
//
//
//
//
//  Operation
//  Array
//
//
//
//
//  1
//  [4, -1, 3]
//
//
//  2
//  [-1, 3, 4]
//
//
//  3
//  [3, 4]
//
//
//  4
//  [4]
//
//
//  5
//  []
//
//
//
//
//
//
//  示例 2：
//
//
// 输入：nums = [1,2,4,3]
// 输出：5
//
//
//
//
//
//  Operation
//  Array
//
//
//
//
//  1
//  [2, 4, 3]
//
//
//  2
//  [4, 3]
//
//
//  3
//  [3, 4]
//
//
//  4
//  [4]
//
//
//  5
//  []
//
//
//
//
//
//
//  示例 3：
//
//
// 输入：nums = [1,2,3]
// 输出：3
//
//
//
//
//
//  Operation
//  Array
//
//
//
//
//  1
//  [2, 3]
//
//
//  2
//  [3]
//
//
//  3
//  []
//
//
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  -109 <= nums[i] <= 10⁹
//  nums 中的元素 互不相同 。
//
//
//  Related Topics 贪心 树状数组 线段树 数组 二分查找 有序集合 排序 👍 21 👎 0

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
  long long countOperationsToEmptyArray(vector<int> &nums) {
    auto const n = nums.size();
    using xy = std::pair<int, int>;
    vector<xy> idxs;
    idxs.reserve(n);
    std::generate_n(back_inserter(idxs), n, [i = -1, &nums]() mutable {
      ++i;
      return xy{nums[i], i};
    });
    std::sort(idxs.begin(), idxs.end());
    auto bit = BITree(vector(n, 1));
    int pivot = 0;
    auto move_cost = [&bit, n](int from, int to) -> int {
      if (from <= to)
        return bit.get(from, to);
      return bit.get(from, n - 1) + bit.get(0, to);
    };
    long long ans = 0;
    for (auto [_, i] : idxs) {
      ans += move_cost(pivot, i);
      //      cout << pivot << ", " << i << endl;
      bit.add(i, -1);
      pivot = (i + 1) % n;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
