//给你一个只包含小写英文字母的字符串 s 。 
//
// 每一次 操作 ，你可以选择 s 中两个 相邻 的字符，并将它们交换。 
//
// 请你返回将 s 变成回文串的 最少操作次数 。 
//
// 注意 ，输入数据会确保 s 一定能变成一个回文串。 
//
// 
//
// 示例 1： 
//
// 输入：s = "aabb"
//输出：2
//解释：
//我们可以将 s 变成 2 个回文串，"abba" 和 "baab" 。
//- 我们可以通过 2 次操作得到 "abba" ："aabb" -> "abab" -> "abba" 。
//- 我们可以通过 2 次操作得到 "baab" ："aabb" -> "abab" -> "baab" 。
//因此，得到回文串的最少总操作次数为 2 。
// 
//
// 示例 2： 
//
// 输入：s = "letelt"
//输出：2
//解释：
//通过 2 次操作从 s 能得到回文串 "lettel" 。
//其中一种方法是："letelt" -> "letetl" -> "lettel" 。
//其他回文串比方说 "tleelt" 也可以通过 2 次操作得到。
//可以证明少于 2 次操作，无法得到回文串。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2000 
// s 只包含小写英文字母。 
// s 可以通过有限次操作得到一个回文串。 
// 
//
// Related Topics 贪心 树状数组 双指针 字符串 👍 39 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




