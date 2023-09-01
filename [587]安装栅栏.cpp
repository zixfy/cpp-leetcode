// 给定一个数组 trees，其中 trees[i] = [xi, yi] 表示树在花园中的位置。
//
//  你被要求用最短长度的绳子把整个花园围起来，因为绳子很贵。只有把
//  所有的树都围起来，花园才围得很好。
//
//  返回恰好位于围栏周边的树木的坐标。
//
//  示例 1:
//
//
//
//
// 输入: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
// 输出: [[1,1],[2,0],[3,3],[2,4],[4,2]]
//
//  示例 2:
//
//
//
//
// 输入: points = [[1,2],[2,2],[4,2]]
// 输出: [[4,2],[2,2],[1,2]]
//
//
//
//  注意:
//
//
//  1 <= points.length <= 3000
//  points[i].length == 2
//  0 <= xi, yi <= 100
//  所有给定的点都是 唯一 的。
//
//
//  Related Topics 几何 数组 数学 👍 214 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include "bits/stdc++.h"
using namespace std;
struct Point2D {
  int x, y;
  bool operator<(Point2D const &oth) const noexcept {
    if (x == oth.x)
      return y < oth.y;
    return x < oth.x;
  }
  int operator*(Point2D const &oth) const noexcept {
    return x * oth.y - y * oth.x;
  }
  Point2D operator-(Point2D const &oth) const noexcept {
    return {x - oth.x, y - oth.y};
  }
  vector<int> to_vec() const { return vector{x, y}; }
};
class Solution {
public:
  vector<vector<int>> outerTrees(vector<vector<int>> &trees) {

    vector<Point2D> pts;
    auto const n = trees.size();
    if (n < 4)
      return trees;
    pts.reserve(n);
    for (auto const &t : trees)
      pts.emplace_back(Point2D{t[0], t[1]});
    std::sort(pts.begin(), pts.end());
    vector<int> stk, vis(n, 0);
    stk.emplace_back(0);
    // 栈内添加第一个元素，且不更新 used，使得 1 在最后封闭凸包时也对单调栈更新
    for (int i = 1; i < n; ++i) {
      while (stk.size() >= 2 && (pts[stk.back()] - pts[stk[stk.size() - 2]]) *
                                        (pts[i] - pts[stk.back()]) <
                                    0)
        vis[stk.back()] = 0, stk.pop_back();
      vis[i] = 1;
      stk.emplace_back(i);
    }
    int tmp = stk.size();
    for (int i = n - 2; i >= 0; --i)
      if (!vis[i]) {
        // ↓求上凸壳时不影响下凸壳
        while (stk.size() > tmp &&
               (pts[stk.back()] - pts[stk[stk.size() - 2]]) *
                       (pts[i] - pts[stk.back()]) <
                   0)
          vis[stk.back()] = 0, stk.pop_back();
        vis[i] = 1;
        stk.emplace_back(i);
      }
    vector<vector<int>> ans;
    for (auto i : stk)
      ans.emplace_back(pts[i].to_vec());
    ans.pop_back();
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
