// 给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y
// 平面上的一个点。求最多有多少个点在同一条直线上。
//
//
//
//  示例 1：
//
//
// 输入：points = [[1,1],[2,2],[3,3]]
// 输出：3
//
//
//  示例 2：
//
//
// 输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// 输出：4
//
//
//
//
//  提示：
//
//
//  1 <= points.length <= 300
//  points[i].length == 2
//  -10⁴ <= xi, yi <= 10⁴
//  points 中的所有点 互不相同
//
//
//  Related Topics 几何 数组 哈希表 数学 👍 498 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)

namespace std {
namespace {

template <class T> inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// Recursive template code derived from Matthieu M.
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  static void apply(size_t &seed, Tuple const &tuple) {
    HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
    hash_combine(seed, get<Index>(tuple));
  }
};

template <class Tuple> struct HashValueImpl<Tuple, 0> {
  static void apply(size_t &seed, Tuple const &tuple) {
    hash_combine(seed, get<0>(tuple));
  }
};
} // namespace

template <typename... TT> struct hash<std::tuple<TT...>> {
  size_t operator()(std::tuple<TT...> const &tt) const {
    size_t seed = 0;
    HashValueImpl<std::tuple<TT...>>::apply(seed, tt);
    return seed;
  }
};
} // namespace std
class Solution {
  bool inline _in_line(int x, int y, int a, int b, int c) {
    return a * x + b * y == c;
  }
  int gcd(int a, int b) {
    while (b != 0) {
      auto o = b;
      b = a % b;
      a = o;
    }
    return a;
  }

public:
  int maxPoints(std::vector<std::vector<int>> &points) {
    const auto n = points.size();
    // x1, y1, x2, y2, x3, y3
    using xyz = std::tuple<int, int, int>;
    std::unordered_set<xyz> lines;
    int ans = 1;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        auto x1 = points[i][0], y1 = points[i][1];
        auto x2 = points[j][0], y2 = points[j][1];
        auto a = y2 - y1, b = x1 - x2, c = x1 * y2 - x2 * y1;
        if (a < 0)
          a = -a, b = -b, c = -c;
        auto g = gcd(a, gcd(b, c));
        a /= g, b /= g, c /= g;
        lines.emplace(a, b, c);
      }
    for (const auto &l : lines) {
      int cnt = 0;
      for (const auto &p : points)
        cnt += _in_line(p[0], p[1], std::get<0>(l), std::get<1>(l),
                        std::get<2>(l));
      ans = std::max(ans, cnt);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
