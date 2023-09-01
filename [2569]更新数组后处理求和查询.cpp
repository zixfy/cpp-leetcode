// 给你两个下标从 0 开始的数组 nums1 和 nums2 ，和一个二维数组 queries
// 表示一些操作。总共有 3 种类型的操作：
//
//
//  操作类型 1 为 queries[i] = [1, l, r] 。你需要将 nums1 从下标 l 到下标 r
//  的所有 0 反转成 1 或将 1 反转成
// 0 。l 和 r 下标都从 0 开始。
//  操作类型 2 为 queries[i] = [2, p, 0] 。对于 0 <= i < n 中的所有下标，令
//  nums2[i] = nums2[i] + nums1[i] * p 。 操作类型 3 为 queries[i] = [3, 0, 0]
//  。求 nums2 中所有元素的和。
//
//
//  请你返回一个数组，包含所有第三种操作类型的答案。
//
//
//
//  示例 1：
//
//
// 输入：nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
// 输出：[3]
// 解释：第一个操作后 nums1 变为 [1,1,1] 。第二个操作后，nums2 变成 [1,1,1]
// ，所以第三个操作的答案为 3 。所以返回 [3] 。
//
//
//
//  示例 2：
//
//
// 输入：nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
// 输出：[5]
// 解释：第一个操作后，nums2 保持不变为 [5] ，所以第二个操作的答案是 5
// 。所以返回 [5] 。
//
//
//
//
//  提示：
//
//
//  1 <= nums1.length,nums2.length <= 10⁵
//  nums1.length = nums2.length
//  1 <= queries.length <= 10⁵
//  queries[i].length = 3
//  0 <= l <= r <= nums1.length - 1
//  0 <= p <= 10⁶
//  0 <= nums1[i] <= 1
//  0 <= nums2[i] <= 10⁹
//
//
//  Related Topics 线段树 数组 👍 16 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
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
    if (inc & 1) {
      lazy += inc;
      data = (right_bound - left_bound + 1 - data);
    }
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
class Solution {
public:
  vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2,
                                vector<vector<int>> &queries) {
    auto t = SegTree(nums1);
    vector<long long> ans;
    long long cur = std::accumulate(nums2.begin(), nums2.end(), 0ll);
    for (auto const &q : queries) {
      auto type = q[0], l = q[1], r = q[2];
      if (type == 1) {
        t.range_add(l, r, 1);
      } else if (type == 2) {
//        cout << t.range_sum(0, 0) <<  endl;
//        cout << t.range_sum(0, 0) <<  endl;
//        cout << nums1.size() << endl;
//        cout << l << ", " << t.range_sum(0, nums1.size() - 1) << endl;
        cur += int64_t(l) * t.range_sum(0, nums1.size() - 1);
      } else {
        ans.emplace_back(cur);
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
