// 最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：
//
//
//  Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
//  Paste（粘贴）：粘贴 上一次 复制的字符。
//
//
//  给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A'
//  。返回能够打印出 n 个 'A' 的最少操作次数。
//
//
//
//  示例 1：
//
//
// 输入：3
// 输出：3
// 解释：
// 最初, 只有一个字符 'A'。
// 第 1 步, 使用 Copy All 操作。
// 第 2 步, 使用 Paste 操作来获得 'AA'。
// 第 3 步, 使用 Paste 操作来获得 'AAA'。
//
//
//  示例 2：
//
//
// 输入：n = 1
// 输出：0
//
//
//
//
//  提示：
//
//
//  1 <= n <= 1000
//
//
//  Related Topics 数学 动态规划 👍 507 👎 0

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
  int minSteps(int n) {
    if (n == 1)
      return 0;
    int ans = 0;
    for (int i = 2; i * i <= n; ++i) {
      while (n % i == 0)
        n /= i, ans += i;
    }
    if (n != 1)
      ans += n;
    return ans;
    // a * b >= a + b
    // dp[i][j] = dp[i-j][j] + 1 or dp[i][1~j-1] + 1
  }
};
// leetcode submit region end(Prohibit modification and deletion)
