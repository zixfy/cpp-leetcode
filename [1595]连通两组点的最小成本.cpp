// 给你两组点，其中第一组中有 size1 个点，第二组中有 size2 个点，且 size1 >=
// size2 。
//
//  任意两点间的连接成本 cost 由大小为 size1 x size2 矩阵给出，其中 cost[i][j]
//  是第一组中的点 i 和第二组中的点 j 的连接
// 成本。如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至
// 少与第一组中的一个点连接。
//
//  返回连通两组点所需的最小成本。
//
//
//
//  示例 1：
//
//
//
//  输入：cost = [[15, 96], [36, 2]]
// 输出：17
// 解释：连通两组点的最佳方法是：
// 1--A
// 2--B
// 总成本为 17 。
//
//
//  示例 2：
//
//
//
//  输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
// 输出：4
// 解释：连通两组点的最佳方法是：
// 1--A
// 2--B
// 2--C
// 3--A
// 最小成本为 4 。
// 请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A
// ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。
//
//  示例 3：
//
//  输入：cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
// 输出：10
//
//
//
//
//  提示：
//
//
//  size1 == cost.length
//  size2 == cost[i].length
//  1 <= size1, size2 <= 12
//  size1 >= size2
//  0 <= cost[i][j] <= 100
//
//
//  Related Topics 位运算 数组 动态规划 状态压缩 矩阵 👍 67 👎 0

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
  int connectTwoGroups(vector<vector<int>> &cost) {
    const auto [m, n] = make_pair(cost.size(), cost[0].size());
    // dp[s_i][s_j] = min(dp[s_i^-, s_j^-]) + cost(s_i^+, s_j^+);
    //  1 << 12 = 4096
    //  dp[i][s] = dp[i-1][s'] + cost(lef[i], rig[s - s'])
    auto exp_n = 1 << n;
    vector dp(m + 1, vector(exp_n, numeric_limits<int>::max()>>1));

    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i)
      for (int s = 0; s < exp_n; ++s)
        for (int j = 0; j < n; ++j)
          dp[i][s | (1 << j)] = min(dp[i][s | (1 << j)],
                                    min(dp[i - 1][s], dp[i][s]) + cost[i-1][j]);

    return dp[m][exp_n - 1];
  }
};

//runtime:84 ms
//memory:9.7 MB

// leetcode submit region end(Prohibit modification and deletion)
