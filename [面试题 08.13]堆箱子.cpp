// 堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高
// hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最
// 高的一堆箱子。箱堆的高度为每个箱子高度的总和。
//
//  输入使用数组[wi, di, hi]表示每个箱子。
//
//  示例1:
//
//   输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
//  输出：6
//
//
//  示例2:
//
//   输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
//  输出：10
//
//
//  提示:
//
//
//  箱子的数目不大于3000个。
//
//
//  Related Topics 数组 动态规划 排序 👍 83 👎 0

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

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  int pileBox(vector<vector<int>> &box) {
    auto cmp = [](const auto &a, const auto &b) {
      return a[0] > b[0] && a[1] > b[1] && a[2] > b[2];
    };
    auto cmp2 = [](const auto &a, const auto &b) {
      if (a[0] != b[0])
        return a[0] > b[0];
      if (a[1] != b[1])
        return a[1] > b[1];
      return a[2] > b[2];
    };
    sort(box.begin(), box.end(), cmp2);
    vector<int> dp;
    dp.reserve(box.size());
    transform(box.begin(), box.end(), back_inserter(dp),
              [](const auto &b) { return b[2]; });
    for (int i = 1; i < box.size(); ++i)
      for (int j = 0; j < i; ++j)
        if (cmp(box[j], box[i]))
          dp[i] = max(dp[i], dp[j] + box[i][2]);
    //    cout << box << endl << dp;
    return *max_element(dp.begin(), dp.end());
  }
};
// leetcode submit region end(Prohibit modification and deletion)
