// 给你两个长度为 n 下标从 0 开始的整数数组 cost 和 time ，分别表示给 n
// 堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：
//
//
//  一位需要 付费 的油漆匠，刷第 i 堵墙需要花费 time[i] 单位的时间，开销为
//  cost[i] 单位的钱。 一位 免费 的油漆匠，刷 任意 一堵墙的时间为 1 单位，开销为
//  0 。但是必须在付费油漆匠 工作 时，免费油漆匠才会工作。
//
//
//  请你返回刷完 n 堵墙最少开销为多少。
//
//
//
//  示例 1：
//
//  输入：cost = [1,2,3,2], time = [1,2,3,2]
// 输出：3
// 解释：下标为 0 和 1 的墙由付费油漆匠来刷，需要 3
// 单位时间。同时，免费油漆匠刷下标为 2 和 3 的墙，需要 2 单位时间，开销为 0
// 。总开销为 1 + 2 = 3 。
//
//
//  示例 2：
//
//  输入：cost = [2,3,4,2], time = [1,1,1,1]
// 输出：4
// 解释：下标为 0 和 3 的墙由付费油漆匠来刷，需要 2
// 单位时间。同时，免费油漆匠刷下标为 1 和 2 的墙，需要 2 单位时间，开销为 0
// 。总开销为 2 + 2 = 4 。
//
//
//
//
//  提示：
//
//
//  1 <= cost.length <= 500
//  cost.length == time.length
//  1 <= cost[i] <= 10⁶
//  1 <= time[i] <= 500
//
//
//  Related Topics 数组 动态规划 👍 20 👎 0

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
  int paintWalls(vector<int> &cost, vector<int> &time) {
    const auto n = cost.size();
    // dp[i][j]
    std::remove_reference

  }
};
// leetcode submit region end(Prohibit modification and deletion)
