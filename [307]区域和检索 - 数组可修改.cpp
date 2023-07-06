// 给你一个数组 nums ，请你完成两类查询。
//
//
//  其中一类查询要求 更新 数组 nums 下标对应的值
//  另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含
//  ）的nums元素的 和 ，其中 left <= right
//
//
//  实现 NumArray 类：
//
//
//  NumArray(int[] nums) 用整数数组 nums 初始化对象
//  void update(int index, int val) 将 nums[index] 的值 更新 为 val
//  int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right
//  之间（ 包含 ）的nums元
// 素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
//
//
//
//
//  示例 1：
//
//
// 输入：
//["NumArray", "sumRange", "update", "sumRange"]
//[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// 输出：
//[null, 9, null, 8]
//
// 解释：
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1,2,5]
// numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 3 * 10⁴
//  -100 <= nums[i] <= 100
//  0 <= index < nums.length
//  -100 <= val <= 100
//  0 <= left <= right < nums.length
//  调用 update 和 sumRange 方法次数不大于 3 * 10⁴
//
//
//  Related Topics 设计 树状数组 线段树 数组 👍 602 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
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
  void add(int x, const T& k) {
    x += 1;
    while (x <= _n) { // 不能越界
      _pre[x] = _pre[x] + k;
      x = x + low_bit(x);
    }
  }
  T get(int l, int r) { return get_sum(r + 1) - get_sum(l); }

private:
  inline int low_bit(int x) { return x & -x; }
  T get_sum(int x) {  // a[1]..a[x]的和
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
class NumArray {
private:
  BITree<int> bit;

public:
  NumArray(vector<int> &nums) : bit(nums) {
  }

  void update(int index, int val) { bit.add(index, val - bit.get(index, index)); }

  int sumRange(int left, int right) {return bit.get(left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// leetcode submit region end(Prohibit modification and deletion)
