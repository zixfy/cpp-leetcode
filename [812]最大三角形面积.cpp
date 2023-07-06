// 给你一个由 X-Y 平面上的点组成的数组 points ，其中 points[i] = [xi, yi]
// 。从其中取任意三个不同的点组成三角形，返回能组成的
// 最大三角形的面积。与真实值误差在 10⁻⁵ 内的答案将会视为正确答案。
//
//
//
//  示例 1：
//
//
// 输入：points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// 输出：2.00000
// 解释：输入中的 5 个点如上图所示，红色的三角形面积最大。
//
//
//  示例 2：
//
//
// 输入：points = [[1,0],[0,0],[0,1]]
// 输出：0.50000
//
//
//
//
//  提示：
//
//
//  3 <= points.length <= 50
//  -50 <= xi, yi <= 50
//  给出的所有点 互不相同
//
//
//  Related Topics 几何 数组 数学 👍 186 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename Iter> class Enumerate {
private:
  Iter _begin, _end;
  class iterator {
  public:
    iterator(Iter iter, int current) : idx(current), iter(iter) {}
    auto operator*() const { return make_pair(idx, *iter); }
    iterator &operator++() {
      ++iter, ++idx;
      return *this;
    }
    bool operator!=(const iterator &other) const { return iter != other.iter; }

  private:
    Iter iter;
    int idx;
  };

public:
  Enumerate() = delete;
  Enumerate(const Iter &begin, const Iter &end) : _begin(begin), _end(end){};
  iterator begin() const { return iterator(_begin, 0); }
  iterator end() const { return iterator(_end, -1); }
};
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

int cross_dot(const vector<int> &a, const vector<int> &b) {
  return a[0] * b[1] - a[1] * b[0];
}
class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    double ans = .0;
    for (const auto &[i, p1] : Enumerate(points.begin(), points.end()))
      for (const auto &[j, p2] :
           Enumerate(points.begin() + i + 1, points.end()))
        for (const auto &[k, p3] :
             Enumerate(points.begin() + j + i + 2, points.end())) {
//          if (ans < abs(cross_dot(p1, p2) + cross_dot(p2, p3) + cross_dot(p3, p1)) / 2.)
//cout << p1 << ", " << p2 << ", " << p3 << endl;
          ans = max(
              ans,
              abs(cross_dot(p1, p2) + cross_dot(p2, p3) + cross_dot(p3, p1)) / 2.);
        }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
