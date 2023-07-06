// 给你一个 严格递增 的整数数组 rungs ，用于表示梯子上每一台阶的 高度
// 。当前你正站在高度为 0 的地板上，并打算爬到最后一个台阶。
//
//  另给你一个整数 dist
//  。每次移动中，你可以到达下一个距离你当前位置（地板或台阶）不超过 dist
//  高度的台阶。当然，你也可以在任何正 整数 高度处插入
// 尚不存在的新台阶。
//
//  返回爬到最后一阶时必须添加到梯子上的 最少 台阶数。
//
//
//
//  示例 1：
//
//
// 输入：rungs = [1,3,5,10], dist = 2
// 输出：2
// 解释：
// 现在无法到达最后一阶。
// 在高度为 7 和 8 的位置增设新的台阶，以爬上梯子。
// 梯子在高度为 [1,3,5,7,8,10] 的位置上有台阶。
//
//
//  示例 2：
//
//
// 输入：rungs = [3,6,8,10], dist = 3
// 输出：0
// 解释：
// 这个梯子无需增设新台阶也可以爬上去。
//
//
//  示例 3：
//
//
// 输入：rungs = [3,4,6,7], dist = 2
// 输出：1
// 解释：
// 现在无法从地板到达梯子的第一阶。
// 在高度为 1 的位置增设新的台阶，以爬上梯子。
// 梯子在高度为 [1,3,4,6,7] 的位置上有台阶。
//
//
//  示例 4：
//
//
// 输入：rungs = [5], dist = 10
// 输出：0
// 解释：这个梯子无需增设新台阶也可以爬上去。
//
//
//
//
//  提示：
//
//
//  1 <= rungs.length <= 10⁵
//  1 <= rungs[i] <= 10⁹
//  1 <= dist <= 10⁹
//  rungs 严格递增
//
//
//  Related Topics 贪心 数组 👍 13 👎 0

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
  int addRungs(vector<int> &rungs, int dist) {
    int ans = 0, cur = 0;
    for (auto r : rungs) {
      ans += (r - cur - 1) / dist;
      cur = r;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
