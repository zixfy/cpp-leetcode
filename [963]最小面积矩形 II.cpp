// 给定在 xy
// 平面上的一组点，确定由这些点组成的任何矩形的最小面积，其中矩形的边不一定平行于
// x 轴和 y 轴。
//
//  如果没有任何矩形，就返回 0。
//
//
//
//  示例 1：
//
//
//
//  输入：[[1,2],[2,1],[1,0],[0,1]]
// 输出：2.00000
// 解释：最小面积的矩形出现在 [1,2],[2,1],[1,0],[0,1] 处，面积为 2。
//
//  示例 2：
//
//
//
//  输入：[[0,1],[2,1],[1,1],[1,0],[2,0]]
// 输出：1.00000
// 解释：最小面积的矩形出现在 [1,0],[1,1],[2,1],[2,0] 处，面积为 1。
//
//
//  示例 3：
//
//
//
//  输入：[[0,3],[1,2],[3,1],[1,3],[2,1]]
// 输出：0
// 解释：没法从这些点中组成任何矩形。
//
//
//  示例 4：
//
//
//
//  输入：[[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
// 输出：2.00000
// 解释：最小面积的矩形出现在 [2,1],[2,3],[3,3],[3,1] 处，面积为 2。
//
//
//
//
//  提示：
//
//
//  1 <= points.length <= 50
//  0 <= points[i][0] <= 40000
//  0 <= points[i][1] <= 40000
//  所有的点都是不同的。
//  与真实值误差不超过 10^-5 的答案将视为正确结果。
//
//
//  Related Topics 几何 数组 数学 👍 66 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
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
  double minAreaFreeRect(vector<vector<int>> &points) {}
};
// leetcode submit region end(Prohibit modification and deletion)
