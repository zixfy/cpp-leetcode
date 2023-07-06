// 下标从 0 开始、长度为 n 的数组 derived 是由同样长度为 n 的原始 二进制数组
// original 通过计算相邻值的 按位异或（⊕）派生而来。
//
//
//  特别地，对于范围 [0, n - 1] 内的每个下标 i ：
//
//
//  如果 i = n - 1 ，那么 derived[i] = original[i] ⊕ original[0]
//  否则 derived[i] = original[i] ⊕ original[i + 1]
//
//
//  给你一个数组 derived ，请判断是否存在一个能够派生得到 derived 的
//  有效原始二进制数组 original 。
//
//  如果存在满足要求的原始二进制数组，返回 true ；否则，返回 false 。
//
//
//  二进制数组是仅由 0 和 1 组成的数组。
//
//
//
//
//  示例 1：
//
//  输入：derived = [1,1,0]
// 输出：true
// 解释：能够派生得到 [1,1,0] 的有效原始二进制数组是 [0,1,0] ：
// derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1
// derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
// derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
//
//
//  示例 2：
//
//  输入：derived = [1,1]
// 输出：true
// 解释：能够派生得到 [1,1] 的有效原始二进制数组是 [0,1] ：
// derived[0] = original[0] ⊕ original[1] = 1
// derived[1] = original[1] ⊕ original[0] = 1
//
//
//  示例 3：
//
//  输入：derived = [1,0]
// 输出：false
// 解释：不存在能够派生得到 [1,0] 的有效原始二进制数组。
//
//
//
//
//  提示：
//
//
//  n == derived.length
//  1 <= n <= 10⁵
//  derived 中的值不是 0 就是 1 。
//
//
//  Related Topics 位运算 数组 👍 8 👎 0

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
  bool doesValidArrayExist(vector<int> &derived) {
    const auto n = derived.size();
    int cur = 0, xory = 0;
    for (int i = 0; i < n; ++i) {
      auto tmp = derived[i];
      derived[i] = cur = xory ^ cur;
      xory = tmp;
    }
    return xory == derived.back();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
