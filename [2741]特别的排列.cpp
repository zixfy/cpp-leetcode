// 给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果
// nums 的一个排列满足以下条件，我们称它是一个特别的排列：
//
//
//  对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i+1] == 0 ，要么
//  nums[i+1] % nums[i]
//== 0 。
//
//
//  请你返回特别排列的总数目，由于答案可能很大，请将它对 109 + 7 取余 后返回。
//
//
//
//  示例 1：
//
//  输入：nums = [2,3,6]
// 输出：2
// 解释：[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。
//
//
//  示例 2：
//
//  输入：nums = [1,4,3]
// 输出：2
// 解释：[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。
//
//
//
//
//  提示：
//
//
//  2 <= nums.length <= 14
//  1 <= nums[i] <= 10⁹
//
//
//  Related Topics 位运算 数组 动态规划 状态压缩 👍 25 👎 0

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
  o << "[";
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
  int specialPerm(vector<int> &nums) {
    constexpr int MOD = 1e9 + 7;
    const auto n = nums.size();
    const auto exp_n = 1 << n;
    vector dp(exp_n, vector(n, 0));
    for (int i = 0; i < n; ++i)
      dp[1 << i][i] = 1;
    for (int s = 1; s < exp_n - 1; ++s) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          if ((s & (1 << i)) && !(s & (1 << j)) &&
              (max(nums[i], nums[j]) % min(nums[i], nums[j]) == 0)) {
            dp[s | (1 << j)][j] = (dp[s | (1 << j)][j] + dp[s][i]) % MOD;
          }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = (ans + dp[exp_n - 1][i]) % MOD;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
