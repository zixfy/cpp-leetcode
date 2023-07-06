// 给你 n 笔订单，每笔订单都需要快递服务。
//
//  请你统计所有有效的 收件/配送 序列的数目，确保第 i 个物品的配送服务
//  delivery(i) 总是在其收件服务 pickup(i) 之后。
//
//  由于答案可能很大，请返回答案对 10^9 + 7 取余的结果。
//
//
//
//  示例 1：
//
//  输入：n = 1
// 输出：1
// 解释：只有一种序列 (P1, D1)，物品 1 的配送服务（D1）在物品 1
// 的收件服务（P1）后。
//
//
//  示例 2：
//
//  输入：n = 2
// 输出：6
// 解释：所有可能的序列包括：
//(P1,P2,D1,D2)，(P1,P2,D2,D1)，(P1,D1,P2,D2)，(P2,P1,D1,D2)，(P2,P1,D2,D1) 和
//(P2,D2 ,P1,D1)。 (P1,D2,P2,D1) 是一个无效的序列，因为物品 2
// 的收件服务（P2）不应在物品 2 的配送服务（D2）之后。
//
//
//  示例 3：
//
//  输入：n = 3
// 输出：90
//
//
//
//
//  提示：
//
//
//  1 <= n <= 500
//
//
//  Related Topics 数学 动态规划 组合数学 👍 56 👎 0

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
  int countOrders(int n) {
    // (2n)!/2^n
    long long ans = 1;
    int frac_n = n;
    int cur = 2;
    int n2 = n * 2;
    while (frac_n > 0 || cur <= n2) {
      if (frac_n > 0 && !(ans & 1))
        ans >>= 1, frac_n--;
      else ans = (ans * (cur++)) % int(1e9 + 7);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
