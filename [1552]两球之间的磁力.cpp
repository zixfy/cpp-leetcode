// 在代号为 C-137 的地球上，Rick
// 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有
// n 个空的篮子，第 i 个篮子 的位置在 position[i] ，Morty 想把 m
// 个球放到这些篮子里，使得任意两球间 最小磁力 最大。
//
//  已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。
//
//  给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。
//
//
//
//  示例 1：
//
//
//
//  输入：position = [1,2,3,4,7], m = 3
// 输出：3
// 解释：将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3,
// 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 。
//
//
//  示例 2：
//
//  输入：position = [5,4,3,2,1,1000000000], m = 2
// 输出：999999999
// 解释：我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
//
//
//
//
//  提示：
//
//
//  n == position.length
//  2 <= n <= 10^5
//  1 <= position[i] <= 10^9
//  所有 position 中的整数 互不相同 。
//  2 <= m <= position.length
//
//
//  Related Topics 数组 二分查找 排序 👍 155 👎 0

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
  int maxDistance(vector<int> &position, int m) {
    std::sort(position.begin(), position.end());
    int l = 1, r = position.back() - position.front() + 1;

    // [l, r)
    while (l + 1 < r) {
      auto mid = (l + r) >> 1;
      int cnt = 1;
      int las = position.front();
      for (auto p: position)
        if (p - las >= mid) {
          las = p;
          if (++cnt == m)
            break ;
        }
//      cout << mid << ", " << cnt << endl;
      if (cnt == m)
        l = mid;
      else r = mid;
    }

    return l;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
