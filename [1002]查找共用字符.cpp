// 给你一个字符串数组 words ，请你找出所有在 words
// 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按
// 任意顺序 返回答 案。
//
//
//
//  示例 1：
//
//
// 输入：words = ["bella","label","roller"]
// 输出：["e","l","l"]
//
//
//  示例 2：
//
//
// 输入：words = ["cool","lock","cook"]
// 输出：["c","o"]
//
//
//
//
//  提示：
//
//
//  1 <= words.length <= 100
//  1 <= words[i].length <= 100
//  words[i] 由小写英文字母组成
//
//
//  Related Topics 数组 哈希表 字符串 👍 333 👎 0

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

auto string_cnt_chars(const string_view &s) {
  unordered_map<char, int> ans;
  for (auto c : s)
    ans[c]++;
  return ans;
}
class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    auto cu = string_cnt_chars(words.front());
    for (auto iter = words.begin() + 1; iter < words.end(); ++iter) {
      auto c_ = string_cnt_chars(*iter);
      for (auto iter2 = cu.begin(); iter2 != cu.end();) {
        auto &[k, v] = *iter2;
        v = min(v, c_[k]);
        if (v == 0)
          iter2 = cu.erase(iter2);
        else
          iter2++;
      }
    }
    vector<string> ans;
    for (const auto [c, v] : cu)
      for (int i = 0; i < v; ++i)
        ans.emplace_back(1, c);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
