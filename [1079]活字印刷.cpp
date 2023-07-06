// 你有一套活字字模 tiles，其中每个字模上都刻有一个字母
// tiles[i]。返回你可以印出的非空字母序列的数目。
//
//  注意：本题中，每个活字字模只能使用一次。
//
//
//
//  示例 1：
//
//
// 输入："AAB"
// 输出：8
// 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
//
//
//  示例 2：
//
//
// 输入："AAABBC"
// 输出：188
//
//
//  示例 3：
//
//
// 输入："V"
// 输出：1
//
//
//
//  提示：
//
//
//  1 <= tiles.length <= 7
//  tiles 由大写英文字母组成
//
//
//  Related Topics 哈希表 字符串 回溯 计数 👍 196 👎 0

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
  int numTilePossibilities(string tiles) {
    auto cnt = string_cnt_chars(tiles);
    int ans = 0;
//    string tmp;
    int tmp_len = 0;
    function<void(char)> f = [&](char las) {
      if (tmp_len > 0)
        ans++;
      for (auto &[k, v] : cnt)
        if (k != las && v > 0)
          for (int j = 1; j <= v; ++j) {
//            auto sz = tmp.size();
//            tmp += string(j, k);
            tmp_len += j;
            v -= j;
            f(k);
//            tmp.resize(sz);
            v += j;
            tmp_len -= j;
          }
    };
    f('#');
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
