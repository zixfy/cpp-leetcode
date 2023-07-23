// 给你一个轴对齐的二维数组 rectangles 。 对于 rectangle[i] = [x1, y1, x2,
// y2]，其中（x1，y1）是矩形 i 左下 角的坐标，
//  (xi1, yi1) 是该矩形 左下角 的坐标，
//  (xi2, yi2) 是该矩形 右上角 的坐标。
//
//  计算平面中所有 rectangles 所覆盖的 总面积
//  。任何被两个或多个矩形覆盖的区域应只计算 一次 。
//
//  返回 总面积 。因为答案可能太大，返回
//  10⁹ + 7 的 模 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
// 输出：6
// 解释：如图所示，三个矩形覆盖了总面积为 6 的区域。
// 从(1,1)到(2,2)，绿色矩形和红色矩形重叠。
// 从(1,0)到(2,3)，三个矩形都重叠。
//
//
//  示例 2：
//
//
// 输入：rectangles = [[0,0,1000000000,1000000000]]
// 输出：49
// 解释：答案是 10¹⁸ 对 (10⁹ + 7) 取模的结果， 即 49 。
//
//
//
//
//  提示：
//
//
//  1 <= rectangles.length <= 200
//  rectanges[i].length = 4
//
//  0 <= xi1, yi1, xi2, yi2 <= 10⁹
//
//
//  Related Topics 线段树 数组 有序集合 扫描线 👍 242 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)

using namespace std;
template <typename> class SegTree;
template <typename T> struct BasicSegTreeNode {
  using DataType = T;
  using p_node = BasicSegTreeNode<T> *;
  friend class SegTree<T>;
  BasicSegTreeNode(size_t l, size_t r, DataType d)
      : data(d), left_bound(l), right_bound(r), right_child(nullptr),
        left_child(nullptr), lazy{}, cnt{}, val{} {};
  BasicSegTreeNode(size_t l, size_t r) : BasicSegTreeNode(l, r, DataType{}){};
  void push_down() {
    if (!lazy)
      return;
    left_child->lazy_inc(lazy);
    right_child->lazy_inc(lazy);
    lazy = DataType{};
  }
  void pull_up() {
    val = left_child->val + right_child->val;
    cnt = min(left_child->cnt, right_child->cnt);
  }
  void lazy_inc(DataType inc) {
    lazy += inc;
    cnt += inc;
    if (left_child == nullptr)
      val = cnt ? data : 0;
    else
      push_down(), pull_up();
  }
  bool within(size_t ql, size_t qr) const {
    return ql <= left_bound && right_bound <= qr;
  }
  bool overlap(size_t ql, size_t qr) const {
    return !(ql > right_bound || qr < left_bound);
  }
  decltype(auto) left() { return *left_child; }
  decltype(auto) right() { return *right_child; }
  void set_child(BasicSegTreeNode<T> &l, BasicSegTreeNode<T> &r) {
    left_child = &l, right_child = &r;
  }

private:
  p_node left_child, right_child;
  size_t left_bound, right_bound;
  DataType data, lazy, cnt, val;
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
      return cur.val;
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
    ret.data = ret.right_child->data + ret.left_child->data;
    return ret;
  }
};
struct line {
  int xl, xr;
  int type, y;
};
ostream &operator<<(ostream &os, const line &a) {
  return os << a.xl << ", " << a.xr << ", " << a.type << ", " << a.y;
}
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int rectangleArea(std::vector<std::vector<int>> &rectangles) {
    long long ans = 0;
    const auto n = rectangles.size();
    vector<int> xs, lens;
    vector<line> lines;
    xs.reserve(n * 2);
    lens.reserve(n * 2);
    lines.reserve(n * 2);
    for (auto const &rec : rectangles)
      xs.emplace_back(rec[0]), xs.emplace_back(rec[2]);
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    for (int i = 1; i < xs.size(); ++i)
      lens.emplace_back(xs[i] - xs[i - 1]);
    auto tree = SegTree(lens);

    for (auto const &rec : rectangles) {
      int xl =
          distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), rec[0]));
      int xr =
          distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), rec[2])) -
          1;
      lines.push_back({xl, xr, 1, rec[1]});
      lines.push_back({xl, xr, -1, rec[3]});
    }
    std::sort(lines.begin(), lines.end(),
              [](line const &a, line const &b) { return a.y < b.y; });
    auto last_y = lines.front().y;

    auto m = lens.size();
    for (auto const &line : lines) {
      long long y = line.y;
      if (last_y != y) {
        ans = (ans + tree.range_sum(0, m - 1) * (y - last_y)) % MOD;
        last_y = y;
      }
      tree.range_add(line.xl, line.xr, line.type);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
