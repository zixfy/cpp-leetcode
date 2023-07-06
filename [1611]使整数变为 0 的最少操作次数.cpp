// 给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ：
//
//
//  翻转 n 的二进制表示中最右侧位（第 0 位）。
//  如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n
//  的二进制表示中的第 i 位。
//
//
//  返回将 n 转换为 0 的最小操作次数。
//
//
//
//  示例 1：
//
//
// 输入：n = 3
// 输出：2
// 解释：3 的二进制表示为 "11"
//"11" -> "01" ，执行的是第 2 种操作，因为第 0 位为 1 。
//"01" -> "00" ，执行的是第 1 种操作。
//
//
//  示例 2：
//
//
// 输入：n = 6
// 输出：4
// 解释：6 的二进制表示为 "110".
//"110" -> "010" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
//"010" -> "011" ，执行的是第 1 种操作。
//"011" -> "001" ，执行的是第 2 种操作，因为第 0 位为 1 。
//"001" -> "000" ，执行的是第 1 种操作。
//
//
//
//
//  提示：
//
//
//  0 <= n <= 10⁹
//
//
//  Related Topics 位运算 记忆化搜索 动态规划 👍 52 👎 0

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

inline ::uint32_t low_bit(int x) { return x & -x; }
class Solution {
public:
  int minimumOneBitOperations(int n) {
    if (n == 0)
      return 0;
    vector<int> digits;
    while (n)
      digits.emplace_back(n & 1), n >>= 1;
    const auto digit_n = digits.size();
    vector<pair<int, int>> dp(digit_n);
    // dp[i][0] ,all zeros
    // dp[i][1] , 10000000...
    dp[0].first = (digits[0] == 1);
    dp[0].second = 1 - dp[0].first;
    for (int i = 1; i < digit_n; ++i) {
      if (digits[i]) {
        dp[i].second = dp[i - 1].first;
        dp[i].first = dp[i - 1].second + (1 << i);
      } else {
        dp[i].first = dp[i - 1].first;
        dp[i].second = dp[i - 1].second + (1 << i);
      }
    }
    // 9 = b1001
//    for (int i =0; i < digit_n; ++i)
//      cout << "dp[" << i <<"] = (" << dp[i].first << ", " << dp[i].second << ")\n";
    // 1 ~ 1 2
    // 10 ~ 3 4
    // 100 ~ 7 101 111 110 010 011 001 000 8
    // 1000 1001 100
    return dp[digit_n - 1].first;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
