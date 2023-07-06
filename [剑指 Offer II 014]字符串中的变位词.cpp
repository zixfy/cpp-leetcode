// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。
//
//  换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
//
//
//
//  示例 1：
//
//
// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").
//
//
//  示例 2：
//
//
// 输入: s1= "ab" s2 = "eidboaoo"
// 输出: False
//
//
//
//
//  提示：
//
//
//  1 <= s1.length, s2.length <= 10⁴
//  s1 和 s2 仅包含小写字母
//
//
//
//
//
//  注意：本题与主站 567 题相同：
//  https://leetcode-cn.com/problems/permutation-in-string/
//
//  Related Topics 哈希表 双指针 字符串 滑动窗口 👍 93 👎 0

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
using namespace std;
auto string_cnt_chars(const string_view &s) {
  unordered_map<char, int> ans;
  for (auto c : s)
    ans[c]++;
  return ans;
}
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s2.length() < s1.length())
      return false;
    auto dict2 = string_cnt_chars(s1);
    auto dict1 = string_cnt_chars("");
    int idx = 0, jdx = 0;
    int okay_cnt = 0;
    for (auto c : s2) {
      if (dict2.count(c)) {
        if (++dict1[c] == dict2[c])
          okay_cnt++;
        else if (dict1[c] == dict2[c] + 1)
          okay_cnt--;
      }
      if (idx >= s1.length()) {
        auto d = s2[jdx];
        if (dict2.count(d)) {
          if (--dict1[d] == dict2[d])
            okay_cnt++;
          else if (dict1[d] == dict2[d] - 1)
            okay_cnt--;
        }
//        cout << idx << ", " << jdx << ", " << okay_cnt <<  endl;
        ++jdx;
      }
      if (okay_cnt == dict2.size())
        return true;
      ++idx;
    }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
