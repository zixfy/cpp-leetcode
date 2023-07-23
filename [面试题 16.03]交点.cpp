// 给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2,
// Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。
//
//  要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X
//  坐标相同则返回 Y 值最小的点。
//
//
//
//  示例 1：
//
//  输入：
// line1 = {0, 0}, {1, 0}
// line2 = {1, 1}, {0, -1}
// 输出： {0.5, 0}
//
//
//  示例 2：
//
//  输入：
// line1 = {0, 0}, {3, 3}
// line2 = {1, 1}, {2, 2}
// 输出： {1, 1}
//
//
//  示例 3：
//
//  输入：
// line1 = {0, 0}, {1, 1}
// line2 = {1, 0}, {2, 1}
// 输出： {}，两条线段没有交点
//
//
//
//
//  提示：
//
//
//  坐标绝对值不会超过 2^7
//  输入的坐标均是有效的二维坐标
//
//
//  Related Topics 几何 数学 👍 84 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {

public:
  vector<double> intersection(vector<int> &start1, vector<int> &end1,
                              vector<int> &start2, vector<int> &end2) {

    auto x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
    auto x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
    auto l1 = Line(x1, y1, x2, y2);
    auto l2 = Line(x3, y3, x4, y4);
    //    cout << l1.to_string() << endl << l2.to_string() << endl;
    if (l1.a == l2.a && l1.b == l2.b) {
      if (l1.c != l2.c)
        return {};
      if (l1.b != 0) {
        auto l1l = min(x1, x2), l1r = max(x1, x2);
        auto l2l = min(x3, x4), l2r = max(x3, x4);
        if (l1l > l2r || l2l > l1r)
          return {};
        double x = max(l1l, l2l);
        return {x, (l1.c - l1.a * x) / l1.b};
      } else {

        auto l1b = min(y1, y2), l1t = max(y1, y2);
        auto l2b = min(y3, y4), l2t = max(y3, y4);
        if (l1b > l2t || l2b > l1t)
          return {};
        return {static_cast<double>(x1), static_cast<double>(max(l1b, l2b))};
      }
    }
    auto x = (l1.c * l2.b - l2.c * l1.b) / double(l1.a * l2.b - l2.a * l1.b);
    auto y = (l1.c * l2.a - l2.c * l1.a) / double(l2.a * l1.b - l1.a * l2.b);
    if ((x - x1) * (x - x2) > 0 || (x - x3) * (x - x4) > 0 ||
        (y - y1) * (y - y2) > 0 || (y - y3) * (y - y4) > 0)
      return {};
    return {x, y};
  }

private:
  static int gcd(int a, int b) {
    while (b != 0) {
      auto o = b;
      b = a % b;
      a = o;
    }
    return a;
  }
  struct Line {
    int a, b, c;
    Line(int x1, int y1, int x2, int y2) {
      // ax + by = c
      a = y2 - y1;
      b = x1 - x2;
      c = x1 * y2 - x2 * y1;
      if (a < 0)
        tie(a, b, c) = make_tuple(-a, -b, -c);
      auto g = abs(gcd(a, gcd(b, c)));
      if (g != 1)
        tie(a, b, c) = make_tuple(a / g, b / g, c / g);
    }
  };
};
// leetcode submit region end(Prohibit modification and deletion)
