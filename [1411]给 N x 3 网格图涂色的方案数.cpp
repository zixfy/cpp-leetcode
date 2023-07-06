// 你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿
// 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜
// 色不同）。
//
//  给你网格图的行数 n 。
//
//  请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7
//  取余的结果。
//
//
//
//  示例 1：
//
//  输入：n = 1
// 输出：12
// 解释：总共有 12 种可行的方法：
//
//
//
//  示例 2：
//
//  输入：n = 2
// 输出：54
//
//
//  示例 3：
//
//  输入：n = 3
// 输出：246
//
//
//  示例 4：
//
//  输入：n = 7
// 输出：106494
//
//
//  示例 5：
//
//  输入：n = 5000
// 输出：30228214
//
//
//
//
//  提示：
//
//
//  n == grid.length
//  grid[i].length == 3
//  1 <= n <= 5000
//
//
//  Related Topics 动态规划 👍 112 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v);

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]\n";
}
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int numOfWays(int n) {
    vector<array<int, 3>> stat;
    for (int i = 0; i < 3 * 3 * 3; ++i) {
      int c1 = i % 3, c2 = (i / 3) % 3, c3 = i / 9;
      if (c1 != c2 && c2 != c3)
        stat.push_back({c1, c2, c3});
    }
    const auto sn = stat.size();
    vector ans(sn, 1);
    vector nxt(sn, 0);
    vector pre(sn, vector<int>());
    for (auto i = 0; i < sn; ++i)
      for (auto j = 0; j < sn; ++j)
        if (stat[i][0] != stat[j][0] && stat[i][1] != stat[j][1] &&
            stat[i][2] != stat[j][2])
          pre[j].push_back(i);
//    cout << pre << endl;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < sn; ++j) {
        nxt[j] = 0;
        for (auto k : pre[j])
          nxt[j] = (nxt[j] + ans[k]) % MOD;

      }ans.swap(nxt);
    }
    int anss = 0;
    for (auto a : ans)
      anss = (anss + a) % MOD;
    //    cout << stat << endl;
    return anss;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
