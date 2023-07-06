// 一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币。
//
//  每一次操作中，你可以从任意一个栈的 顶部 取出 1
//  个硬币，从栈中移除它，并放入你的钱包里。
//
//  给你一个列表 piles ，其中 piles[i] 是一个整数数组，分别表示第 i 个栈里
//  从顶到底 的硬币面值。同时给你一个正整数 k ，请你返回在 恰
// 好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：piles = [[1,100,3],[7,8,9]], k = 2
// 输出：101
// 解释：
// 上图展示了几种选择 k 个硬币的不同方法。
// 我们可以得到的最大面值为 101 。
//
//
//  示例 2：
//
//
// 输入：piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
// 输出：706
// 解释：
// 如果我们所有硬币都从最后一个栈中取，可以得到最大面值和。
//
//
//
//
//  提示：
//
//
//  n == piles.length
//  1 <= n <= 1000
//  1 <= piles[i][j] <= 10⁵
//  1 <= k <= sum(piles[i].length) <= 2000
//
//
//  Related Topics 数组 动态规划 前缀和 👍 55 👎 0

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

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
template <typename Container> class PrefixView {
public:
  using Iter = typename Container::iterator;
  using T = typename std::iterator_traits<Iter>::value_type;
  PrefixView() = delete;
  template <typename IterAny>
  PrefixView(IterAny begin, IterAny end) : _bg(begin), _ed(end) {
    T sum{};
    for (auto it = begin; it != end; ++it)
      *it = (sum += *it);
  }
  PrefixView(Container &vec) : PrefixView(vec.begin(), vec.end()) {}
  T get_range_sum(int l, int r) {
    return l > 0 ? (*(_bg + r) - *(_bg + l - 1)) : *(_bg + r);
  }
  const T &get_prefix(int i) { return *(_bg + i); }
  friend class Solution;

private:
  Iter _bg, _ed;
};
class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    // dp[i][j]= dp[i-1][k] + coins[i](0~j-k)
    const auto n = piles.size();
    vector dp(k + 1, 0);
    vector<PrefixView<vector<int>>> pres;
    pres.reserve(n);
    for (auto &pile : piles)
      pres.emplace_back(pile);
    for (const auto &p : pres) {
      for (int j = k; j > 0; --j) {
        int cur_k = 1;
        for (auto prefix_iter = p._bg; prefix_iter != p._ed && cur_k <= j;
             ++prefix_iter) {
          auto pre = *prefix_iter;
          dp[j] = max(dp[j], dp[j - cur_k] + pre);
          ++cur_k;
        }
      }
    }
    return dp[k];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
