// 给你一个披萨，它由 3n
// 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：
//
//
//  你挑选 任意 一块披萨。
//  Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨。
//  Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨。
//  重复上述过程直到没有披萨剩下。
//
//
//  每一块披萨的大小按顺时针方向由循环数组 slices 表示。
//
//  请你返回你可以获得的披萨大小总和的最大值。
//
//
//
//  示例 1：
//
//
//
//
// 输入：slices = [1,2,3,4,5,6]
// 输出：10
// 解释：选择大小为 4 的披萨，Alice 和 Bob 分别挑选大小为 3 和 5
// 的披萨。然后你选择大小为 6 的披萨，Alice 和 Bob 分别挑选大小 为 2 和 1
// 的披萨。你获得的披萨总大小为 4 + 6 = 10 。
//
//
//  示例 2：
//
//
//
//
// 输入：slices = [8,9,8,6,1,1]
// 输出：16
// 解释：两轮都选大小为 8 的披萨。如果你选择大小为 9
// 的披萨，你的朋友们就会选择大小为 8 的披萨，这种情况下你的总和不是最大的。
//
//
//
//
//  提示：
//
//
//  1 <= slices.length <= 500
//  slices.length % 3 == 0
//  1 <= slices[i] <= 1000
//
//
//  Related Topics 贪心 数组 动态规划 堆（优先队列） 👍 119 👎 0

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
  int maxSizeSlices(vector<int> &slices) {
    auto f = [&slices](int l, int r) -> int {
      const auto n = slices.size() / 3;
      vector<pair<int, int>> dp(n + 1);
      for (; l <= r; ++l)
        for (int k = n; k > 0; --k)
          dp[k].first = max(dp[k].first, dp[k].second),
          dp[k].second = dp[k - 1].first + slices[l];
      return max(dp[n].first, dp[n].second);
    };
    return max(f(0, slices.size() - 2), f(1, slices.size() - 1));
  }
};
// leetcode submit region end(Prohibit modification and deletion)
