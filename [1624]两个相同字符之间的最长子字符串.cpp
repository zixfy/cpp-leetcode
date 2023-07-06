// 给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度
// ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。
//
//  子字符串 是字符串中的一个连续字符序列。
//
//
//
//  示例 1：
//
//  输入：s = "aa"
// 输出：0
// 解释：最优的子字符串是两个 'a' 之间的空子字符串。
//
//  示例 2：
//
//  输入：s = "abca"
// 输出：2
// 解释：最优的子字符串是 "bc" 。
//
//
//  示例 3：
//
//  输入：s = "cbzxy"
// 输出：-1
// 解释：s 中不存在出现出现两次的字符，所以返回 -1 。
//
//
//  示例 4：
//
//  输入：s = "cabbac"
// 输出：4
// 解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 300
//  s 只含小写英文字母
//
//
//  Related Topics 哈希表 字符串 👍 76 👎 0

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
  int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, int> las_idx;
    int i = 0;
    int ans = numeric_limits<int>::min();
    for (auto c : s) {
      if (las_idx.count(c))
        ans = max(ans, i - las_idx[c] - 1);
      else las_idx[c] = i;
      ++i;
    }
    return ans < 0 ? -1 : ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
