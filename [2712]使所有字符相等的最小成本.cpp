// 给你一个下标从 0 开始、长度为 n 的二进制字符串 s ，你可以对其执行两种操作：
//
//
//  选中一个下标 i 并且反转从下标 0 到下标 i（包括下标 0 和下标 i
//  ）的所有字符，成本为 i + 1 。 选中一个下标 i 并且反转从下标 i 到下标 n -
//  1（包括下标 i 和下标 n - 1 ）的所有字符，成本为 n - i 。
//
//
//  返回使字符串内所有字符 相等 需要的 最小成本 。
//
//  反转 字符意味着：如果原来的值是 '0' ，则反转后值变为 '1' ，反之亦然。
//
//
//
//  示例 1：
//
//
// 输入：s = "0011"
// 输出：2
// 解释：执行第二种操作，选中下标 i = 2 ，可以得到 s = "0000" ，成本为 2
// 。可以证明 2 是使所有字符相等的最小成本。
//
//
//  示例 2：
//
//
// 输入：s = "010101"
// 输出：9
// 解释：执行第一种操作，选中下标 i = 2 ，可以得到 s = "101101" ，成本为 3 。
// 执行第一种操作，选中下标 i = 1 ，可以得到 s = "011101" ，成本为 2 。
// 执行第一种操作，选中下标 i = 0 ，可以得到 s = "111101" ，成本为 1 。
// 执行第二种操作，选中下标 i = 4 ，可以得到 s = "111110" ，成本为 2 。
// 执行第一种操作，选中下标 i = 5 ，可以得到 s = "111111" ，成本为 1 。
// 使所有字符相等的总成本等于 9 。可以证明 9 是使所有字符相等的最小成本。
//
//
//
//  提示：
//
//
//  1 <= s.length == n <= 10⁵
//  s[i] 为 '0' 或 '1'
//
//
//  Related Topics 贪心 字符串 动态规划 👍 18 👎 0

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
  long long minimumCost(string s) {
    auto dfs = [dfs_impl = [](auto &&self, TreeNode *cur) -> void {
      std::cout << cur->val << std::endl;
      self(self, cur->left), self(self, cur->right);
    }](TreeNode *cur) { return dfs_impl(dfs_impl, cur); };
  };
};
// leetcode submit region end(Prohibit modification and deletion)