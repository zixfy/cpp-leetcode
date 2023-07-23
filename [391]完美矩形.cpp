// 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
// 表示一个坐标轴平行的矩形。这个矩形的左下顶点是
//  (xi, yi) ，右上顶点是 (ai, bi) 。
//
//  如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
//
//  示例 1：
//
//
// 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
// 输出：true
// 解释：5 个矩形一起可以精确地覆盖一个矩形区域。
//
//
//  示例 2：
//
//
// 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
// 输出：false
// 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
//
//  示例 3：
//
//
// 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
// 输出：false
// 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
//
//
//
//  提示：
//
//
//  1 <= rectangles.length <= 2 * 10⁴
//  rectangles[i].length == 4
//  -10⁵ <= xi, yi, ai, bi <= 10⁵
//
//
//  Related Topics 数组 扫描线 👍 255 👎 0

#include <bits/stdc++.h>
using namespace std;

auto recursive_lambda = [](auto &&lam) {
  return [lam_impl = lam](auto &&...args) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};

// leetcode submit region begin(Prohibit modification and deletion)

template <typename> class SegTree;
template <typename T> struct BasicSegTreeNode {
  using DataType = T;
  using p_node = BasicSegTreeNode<T> *;
  friend class SegTree<T>;
  BasicSegTreeNode(size_t l, size_t r)
      : left_bound(l), right_bound(r), right_child(nullptr),
        left_child(nullptr), lazy{}, maxx{}, val{} {};
  void push_down() {
    if (!lazy)
      return;
    left_child->lazy_inc(lazy);
    right_child->lazy_inc(lazy);
    lazy = DataType{};
  }
  void pull_up() {
    val = left_child->val + right_child->val;
    maxx = max(left_child->maxx, right_child->maxx);
  }
  void lazy_inc(DataType inc) {
    lazy += inc;
    val += inc * (right_bound - left_bound + 1);
    maxx += inc;
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
  DataType lazy, val, maxx;
};
template <typename T = int> class SegTree {
  using Node = BasicSegTreeNode<T>;
  vector<Node> tree;

public:
  explicit SegTree(int n) {
    tree.reserve(n << 1);
    _build(0, n - 1);
  }
  SegTree() = delete;
  decltype(auto) range_sum(int l, int r) {
    return _range_query(l, r, tree.front());
  }
  void range_add(int l, int r, int val) {
    _range_modify(l, r, val, tree.front());
  }

private:
  pair<T, T> _range_query(int ql, int qr, Node &cur) {
    if (!cur.overlap(ql, qr))
      return {};
    if (cur.within(ql, qr))
      return {cur.val, cur.maxx};
    cur.push_down();
    auto [v1, m1] = _range_query(ql, qr, cur.left());
    auto [v2, m2] = _range_query(ql, qr, cur.right());
    return {v1 + v2, max(m1, m2)};
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
      tree.emplace_back(l, r);
      return tree.back();
    }
    tree.emplace_back(l, r);
    auto &ret = tree.back();
    auto m = l + ((r - l) >> 1);
    ret.set_child(_build(l, m), _build(m + 1, r));
    return ret;
  }
};
struct line {
  int xl, xr;
  int type, y;
};
class Solution {
public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    const auto n = rectangles.size();
    vector<int> xs;
    vector<line> lines;
    xs.reserve(n * 2);
    lines.reserve(n * 2);
    for (auto const &rec : rectangles)
      xs.emplace_back(rec[0]), xs.emplace_back(rec[2]);
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    auto my = std::max_element(rectangles.begin(), rectangles.end(), [](auto const &a, auto const &b) {
      return a[3] < b[3];
    })->at(3);
    for (auto const &rec : rectangles) {
      int xl =
          distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), rec[0]));
      int xr =
          distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), rec[2])) -
          1;
      lines.push_back({xl, xr, 1, rec[1]});
      lines.push_back({xl, xr, rec[3] == my ? 0 : -1, rec[3]});
    }
    std::sort(lines.begin(), lines.end(),
              [](line const &a, line const &b) { return a.y < b.y; });
    auto m = xs.size() - 1, nl = lines.size();
    auto tree = SegTree(m);
    for (auto idx = 0; idx < nl;) {
      auto cy = lines[idx].y;
      while (idx < nl && lines[idx].y == cy) {
        tree.range_add(lines[idx].xl, lines[idx].xr, lines[idx].type);
        ++idx;
      }
      auto [sumy, maxx] = tree.range_sum(0, m - 1);
//      cout << sumy << ", " << maxx << ", " << cy << endl;
      if (!(sumy == m && maxx == 1))
        return false;
    }
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
