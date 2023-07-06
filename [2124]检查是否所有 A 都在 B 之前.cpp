// 给你一个 仅 由字符 'a' 和 'b' 组成的字符串 s 。如果字符串中 每个 'a' 都出现在
// 每个 'b' 之前，返回 true ；否则，返回 false 。
//
//
//
//  示例 1：
//
//  输入：s = "aaabbb"
// 输出：true
// 解释：
//'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
// 因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//
//
//  示例 2：
//
//  输入：s = "abab"
// 输出：false
// 解释：
// 存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
// 因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
//
//
//  示例 3：
//
//  输入：s = "bbb"
// 输出：true
// 解释：
// 不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 100
//  s[i] 为 'a' 或 'b'
//
//
//  Related Topics 字符串 👍 10 👎 0

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
  bool checkString(string s) {
    int idx = 0, jdx = s.length() - 1;
    while (idx < s.length() && s[idx] == 'a')
      ++idx;
    while (jdx >= 0 && s[jdx] == 'b')
      --jdx;
    // [0 , idx)
    // (jdx, sz- 1]
    return idx == jdx + 1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
