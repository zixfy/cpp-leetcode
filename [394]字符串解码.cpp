// 给定一个经过编码的字符串，返回它解码后的字符串。
//
//  编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复
//  k 次。注意 k 保证为正整数。
//
//  你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//
//  此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k
//  ，例如不会出现像 3a 或 2[4] 的输入。
//
//
//
//  示例 1：
//
//
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
//
//
//  示例 2：
//
//
// 输入：s = "3[a2[c]]"
// 输出："accaccacc"
//
//
//  示例 3：
//
//
// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"
//
//
//  示例 4：
//
//
// 输入：s = "abc3[cd]xyz"
// 输出："abccdcdcdxyz"
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 30
//
//  s 由小写英文字母、数字和方括号
//  '[]' 组成
//  s 保证是一个 有效 的输入。
//  s 中所有整数的取值范围为
//  [1, 300]
//
//
//  Related Topics 栈 递归 字符串 👍 1498 👎 0

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
  string decodeString(string s) {
//    cout << s << endl;
    string ans;
    int num = -1;
    for (int i = 0, n = s.length(); i < n; ++i) {
      auto c = s[i];
      if (c == '[') {
        int old_i = i;
        int tmp = -1;
        while (tmp != 0) {
          ++i;
          if (s[i] == '[')
            --tmp;
          else if (s[i] == ']')
            ++tmp;
        }
        auto subs = decodeString(s.substr(old_i + 1, i - old_i - 1));
        for (int j = 0; j < num; ++j)
          ans += subs;
        num = -1;
      } else if (c >= '0' && c <= '9') {
        if (num == -1)
          num = 0;
        num = num * 10 + c - '0';
      } else
        ans += c;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
