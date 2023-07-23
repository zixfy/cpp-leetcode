// 给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回
// true 。
//
//  点的坐标 pi 表示为 [xi, yi] 。 输入没有任何顺序 。
//
//  一个 有效的正方形 有四条等边和四个等角(90度角)。
//
//
//
//  示例 1:
//
//
// 输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// 输出: True
//
//
//  示例 2:
//
//
// 输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
// 输出：false
//
//
//  示例 3:
//
//
// 输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
// 输出：true
//
//
//
//
//  提示:
//
//
//  p1.length == p2.length == p3.length == p4.length == 2
//  -10⁴ <= xi, yi <= 10⁴
//
//
//  Related Topics 几何 数学 👍 175 👎 0

#include <bits/stdc++.h>
// leetcode submit region begin(Prohibit modification and deletion)
using std::vector;
class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    using xy = std::pair<int, int>;
    vector<xy> points{
        {p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}};
    auto cp = points.front();
    auto dis = [](xy const &a, xy const &b) {
      return (a.first - b.first) * (a.first - b.first) +
             (a.second - b.second) * (a.second - b.second);
    };
    std::sort(points.begin(), points.end(),
              [cp, dis](xy const &a, xy const &b) {
                return dis(a, cp) < dis(b, cp);
              });
    auto const &far = points[3];
    auto const &mid1 = points[1];
    auto const &mid2 = points[2];
    auto lsq = dis(mid1, cp);
    if (lsq == 0)
      return 0;
    return lsq == dis(mid2, cp) && lsq == dis(mid1, far) &&
           lsq == dis(mid2, far) && 2 * lsq == dis(mid1, mid2) &&
           2 * lsq == dis(cp, far);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
