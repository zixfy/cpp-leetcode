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
template <typename... T> void print(T... t) {
  ((cout << t << ", "), ..., (cout << endl));
}
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
template <typename T> struct BasicSegTreeNode {
  using DataType = T;
  using p_node = BasicSegTreeNode<T> *;
  BasicSegTreeNode(size_t l, size_t r, DataType d)
      : data(d), left_bound(l), right_bound(r), right_child(nullptr),
        left_child(nullptr), lazy{} {};
  BasicSegTreeNode(size_t l, size_t r) : BasicSegTreeNode(l, r, DataType{}){};
  void push_down() {
    if (!lazy)
      return;
    left_child->lazy_inc(lazy);
    right_child->lazy_inc(lazy);
    lazy = DataType{};
  }
  void pull_up() { data = left_child->data + right_child->data; }
  void lazy_inc(DataType inc) {
    lazy += inc;
    data += inc * (right_bound - left_bound + 1);
  }
  bool within(size_t ql, size_t qr) const {
    return ql <= left_bound && right_bound <= qr;
  }
  bool overlap(size_t ql, size_t qr) const {
    return !(ql > right_bound || qr < left_bound);
  }
  DataType val() { return data; }
  decltype(auto) left() { return *left_child; }
  decltype(auto) right() { return *right_child; }
  void set_child(BasicSegTreeNode<T> &l, BasicSegTreeNode<T> &r) {
    left_child = &l, right_child = &r;
  }

private:
  p_node left_child, right_child;
  size_t left_bound, right_bound;
  DataType data, lazy;
};
template <typename T = int> class SegTree {
  using Node = BasicSegTreeNode<T>;
  vector<Node> tree;
  std::reference_wrapper<const vector<T>> arr;

public:
  explicit SegTree(const vector<T> &v) : arr(v) {
    int n = arr.get().size();
    tree.reserve(n << 1);
    _build(0, n - 1);
  }
  SegTree() = delete;
  T range_sum(int l, int r) { return _range_query(l, r, tree.front()); }
  void range_add(int l, int r, int val) {
    _range_modify(l, r, val, tree.front());
  }

private:
  T _range_query(int ql, int qr, Node &cur) {
    if (!cur.overlap(ql, qr))
      return {};
    if (cur.within(ql, qr))
      return cur.val();
    cur.push_down();
    return _range_query(ql, qr, cur.left()) + _range_query(ql, qr, cur.right());
  }

  void _range_modify(int ql, int qr, T val, Node &cur) {
    if (!cur.overlap(ql, qr))
      return;
    if (cur.within(ql, qr)) {
      cur.lazy_inc(val);
      return;
    }
    cur.push_down();
    _range_modify(ql, qr, val, cur.left());
    _range_modify(ql, qr, val, cur.right());
    cur.pull_up();
  }

  Node &_build(size_t l, size_t r) {
    if (l == r) {
      tree.emplace_back(l, r, arr.get()[l]);
      return tree.back();
    }
    tree.emplace_back(l, r);
    auto &ret = tree.back();
    auto m = l + ((r - l) >> 1);
    ret.set_child(_build(l, m), _build(m + 1, r));
    ret.pull_up();
    return ret;
  }
};
class NumArray {
private:
  SegTree<int>  bit;

public:
  NumArray(vector<int> &nums) : bit(nums) {}

  void update(int index, int val) {
    bit.range_add(index, index, val - bit.range_sum(index, index));
  }

  int sumRange(int left, int right) {
    return bit.range_sum(left, right);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// leetcode submit region end(Prohibit modification and deletion)
