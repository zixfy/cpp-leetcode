// 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//
//  给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0
//  表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则
// 的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：flowerbed = [1,0,0,0,1], n = 1
// 输出：true
//
//
//  示例 2：
//
//
// 输入：flowerbed = [1,0,0,0,1], n = 2
// 输出：false
//
//
//
//
//  提示：
//
//
//  1 <= flowerbed.length <= 2 * 10⁴
//  flowerbed[i] 为 0 或 1
//  flowerbed 中不存在相邻的两朵花
//  0 <= n <= flowerbed.length
//
//
//  Related Topics 贪心 数组 👍 565 👎 0

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
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int l = -2, r = 0;
    int cnt = 0;
    flowerbed.emplace_back(0);
    flowerbed.emplace_back(1);
    for (auto f : flowerbed) {
      if (f == 1) {
        auto len = r - l - 1;
        cnt += (len - 1) / 2;
        l = r;
      }
      ++r;
    }
    return cnt >= n;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
