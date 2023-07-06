// 给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s
// 中不存在符合条件的子字符串，则返回空字符串 "" 。
//
//  如果 s 中存在多个符合条件的子字符串，返回任意一个。
//
//
//
//  注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t
//  中该字符数量。
//
//
//
//  示例 1：
//
//
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
//
//  示例 2：
//
//
// 输入：s = "a", t = "a"
// 输出："a"
//
//
//  示例 3：
//
//
// 输入：s = "a", t = "aa"
// 输出：""
// 解释：t 中两个字符 'a' 均应包含在 s
// 的子串中，因此没有符合条件的子字符串，返回空字符串。
//
//
//
//  提示：
//
//
//  1 <= s.length, t.length <= 10⁵
//  s 和 t 由英文字母组成
//
//
//
//
//  进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
//
//
//
//
//  注意：本题与主站 76
//  题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-
// substring/
//
//  Related Topics 哈希表 字符串 滑动窗口 👍 99 👎 0

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
  string minWindow(string s, string t) {
    if (s.length() < t.length())
      return "";
    string_view ans = "";
    unordered_map<char, int> tc, sc;
    for (auto c : t)
      tc[c]++;
    int under_okay = tc.size();
    int l = 0, r = 0;
    const auto n = s.size();
    for (; r < n; ++r) {
      auto c = s[r];
      if (!tc.count(c))
        continue;
      if (++sc[c] == tc[c])
        under_okay--;
      while (l <= r) {
        auto c = s[l++];
        if (!tc.count(c))
          continue;
        if (sc[c] <= tc[c]) {
          l--;
          break;
        }
        else --sc[c];
      }
      while (l <= r && !tc.count(s[l]))
        l++;
      if (under_okay == 0) {
        string_view tmp(s.c_str() + l, r - l + 1);
        if (ans == "" || ans.length() > tmp.length())
          ans = tmp;
      }
    }
    return string(ans);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
