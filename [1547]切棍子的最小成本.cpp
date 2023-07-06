// 有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6
// 的棍子可以标记如下：
//
//
//
//  给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。
//
//  你可以按顺序完成切割，也可以根据需要更改切割的顺序。
//
//  每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前
// 木棍的长度）。请参阅第一个示例以获得更直观的解释。
//
//  返回切棍子的 最小总成本 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 7, cuts = [1,3,4,5]
// 输出：16
// 解释：按 [1, 3, 4, 5] 的顺序切割的情况如下所示：
//
// 第一次切割长度为 7 的棍子，成本为 7 。第二次切割长度为 6
// 的棍子（即第一次切割得到的第二根棍子），第三次切割为长度 4
// 的棍子，最后切割长度为 3 的棍子。总成本为 7 + 6 + 4 + 3 = 20 。
// 而将切割顺序重新排列为 [3, 5, 1, 4] 后，总成本 = 16（如示例图中 7 + 4 + 3 + 2
// = 16）。
//
//
//  示例 2：
//
//
// 输入：n = 9, cuts = [5,6,1,4,2]
// 输出：22
// 解释：如果按给定的顺序切割，则总成本为 25 。总成本 <= 25
// 的切割顺序很多，例如，[4, 6, 5, 2, 1] 的总成本 = 22，是所有可能方案
// 中成本最小的。
//
//
//
//  提示：
//
//
//  2 <= n <= 10^6
//  1 <= cuts.length <= min(n - 1, 100)
//  1 <= cuts[i] <= n - 1
//  cuts 数组中的所有整数都 互不相同
//
//
//  Related Topics 数组 动态规划 排序 👍 82 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>);
template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);

template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

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
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int minCost(int n, vector<int> &cuts) {
    // dp[i][j] = len(i, j) + dp[i][k-1] + dp[k+1][j]
    std::sort(cuts.begin(), cuts.end());
    const auto m = cuts.size();
    auto gety = [&cuts, m, n](int i) {
      if (i < 0)
        return 0;
      if (i >= m)
        return n;
      return cuts[i];
    };
    auto len = [&gety](int i, int j) { return gety(j + 1) - gety(i - 1); };
    vector dp(m, vector(m, 0));
    for (int i = 0; i < m; i++)
      dp[i][i] = len(i, i);
    for (int k = 2; k <= m; ++k)
      for (int i = 0, j = k - 1; j < m; ++i, ++j) {
        auto cost = len(i, j);
        auto tmp = min(dp[i + 1][j], dp[i][j - 1]);
        for (int t = i + 1; t < j; ++t)
          tmp = min(tmp, dp[i][t - 1] + dp[t + 1][j]);
        dp[i][j] = tmp + cost;
      }

    return dp[0][m - 1];
  };
};
// leetcode submit region end(Prohibit modification and deletion)
