// 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i
// 个信封的宽度和高度。
//
//  当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
//
//  请计算 最多能有多少个
//  信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
//
//  注意：不允许旋转信封。
//
//  示例 1：
//
//
// 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
// 输出：3
// 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
//
//  示例 2：
//
//
// 输入：envelopes = [[1,1],[1,1],[1,1]]
// 输出：1
//
//
//
//
//  提示：
//
//
//  1 <= envelopes.length <= 10⁵
//  envelopes[i].length == 2
//  1 <= wi, hi <= 10⁵
//
//
//  Related Topics 数组 二分查找 动态规划 排序 👍 901 👎 0

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
template <typename T, typename Comp>
auto right_lower_bound(
    const vector<T> &arr, const T &x, int r,
    Comp cmp = [](const auto &a, const auto &b) { return a <= b; }) {
  // [l, r)
  int l = -1;
  while (l + 1 < r) {
    auto m = (l + r) >> 1;
    const auto &mid_val = arr[m];
    if (cmp(mid_val, x))
      l = m;
    else
      r = m;
  }
  return l < 0 ? arr.end() : arr.begin() + l;
}

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    std::sort(envelopes.begin(), envelopes.end(),
              [](const auto &a, const auto &b) {
                if (a[0] != b[0])
                  return a[0] < b[0];
                return a[1] < b[1];
              });
    vector dp(envelopes.size(), 0);
    cout << envelopes << endl;
    for (int i = 0, n = envelopes.size(); i < n; ++i) {
      auto iter = right_lower_bound(envelopes, envelopes[i], i,
                                    [](const auto &a, const auto &b) {
                                      return a[0] < b[0] && a[1] < b[1];
                                    });

      if (iter == envelopes.end())
        dp[i] = 1, cout << "nullptr" << endl;
      else
        cout << iter - envelopes.begin() << endl, dp[i] = 1 + dp[iter - envelopes.begin()];
    }
    cout << dp << endl;
    return *max_element(dp.begin(), dp.end());
  }
};
// leetcode submit region end(Prohibit modification and deletion)
