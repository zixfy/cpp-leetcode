// 一个字符串的 美丽值
// 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。
//
//
//  比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
//
//
//  给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。
//
//
//
//  示例 1：
//
//
// 输入：s = "aabcb"
// 输出：5
// 解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"]
// ，每一个字符串的美丽值都为 1 。
//
//  示例 2：
//
//
// 输入：s = "aabcbaa"
// 输出：17
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 500
//  s 只包含小写英文字母。
//
//
//  Related Topics 哈希表 字符串 计数 👍 85 👎 0

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
  int beautySum(string s) {
    const int n = s.length();
    array<int, 26> cnt{};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      fill(cnt.begin(), cnt.end(), 0);
      for (int j = i; j < n; ++j) {
        cnt[s[j] - 'a']++, ans += (*max_element(cnt.begin(), cnt.end()));
        auto minn = numeric_limits<int>::max();
        for (auto c : cnt)
          if (c)
            minn = min(minn, c);
        ans -= minn;
//        cout << ans << endl;
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
