// 可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
//
//
//  'A'：Absent，缺勤
//  'L'：Late，迟到
//  'P'：Present，到场
//
//
//  如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
//
//
//  按 总出勤 计，学生缺勤（'A'）严格 少于两天。
//  学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
//
//
//  给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n
//  时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 10⁹ + 7
// 取余 的结果。
//
//
//
//  示例 1：
//
//
// 输入：n = 2
// 输出：8
// 解释：
// 有 8 种长度为 2 的记录将被视为可奖励：
//"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// 只有"AA"不会被视为可奖励，因为缺勤次数为 2 次（需要少于 2 次）。
//
//
//  示例 2：
//
//
// 输入：n = 1
// 输出：3
//
//
//  示例 3：
//
//
// 输入：n = 10101
// 输出：183236316
//
//
//
//
//  提示：
//
//
//  1 <= n <= 10⁵
//
//
//  Related Topics 动态规划 👍 294 👎 0

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
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int checkRecord(int n) {
    // dp[
    vector<array<int, 4>> l_dp(n + 1);
    l_dp[0] = {0, 0, 0, 0};
    for (int i = 1; i <= n; ++i) {
      l_dp[i][0] = l_dp[i - 1][3];
      l_dp[i][1] = l_dp[i - 1][0];
      l_dp[i][2] = l_dp[i - 1][1];
      l_dp[i][3] = ((l_dp[i][0] + l_dp[i][1]) % MOD + l_dp[i][2]) % MOD;
    }
    long long ans = l_dp[n][3];
    int p2, p1;
    for (p1 = 0, p2 = n - 1; p1 < p2; ++p1, --p2)
      ans = (ans + ((((long long)l_dp[p1][3] *  l_dp[p2][3]) % MOD) << 1) % MOD) % MOD;
    if (p1 == p2)
      ans = (ans + ((long long)l_dp[p1][3]*l_dp[p1][3]) % MOD) %MOD;

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
