// 房间中有 n 只已经打开的灯泡，编号从 1 到 n 。墙上挂着 4 个开关 。
//
//  这 4 个开关各自都具有不同的功能，其中：
//
//
//  开关 1 ：反转当前所有灯的状态（即开变为关，关变为开）
//  开关 2 ：反转编号为偶数的灯的状态（即 0, 2, 4, ...）
//  开关 3 ：反转编号为奇数的灯的状态（即 1, 3, ...）
//  开关 4 ：反转编号为 j = 3k + 1 的灯的状态，其中 k = 0, 1, 2, ...（即 1, 4,
//  7, 10, ...）
//
//
//  你必须 恰好 按压开关 presses 次。每次按压，你都需要从 4
//  个开关中选出一个来执行按压操作。
//
//  给你两个整数 n 和 presses ，执行完所有按压之后，返回 不同可能状态 的数量。
//
//
//
//  示例 1：
//
//
// 输入：n = 1, presses = 1
// 输出：2
// 解释：状态可以是：
//- 按压开关 1 ，[关]
//- 按压开关 2 ，[开]
//
//
//  示例 2：
//
//
// 输入：n = 2, presses = 1
// 输出：3
// 解释：状态可以是：
//- 按压开关 1 ，[关, 关]
//- 按压开关 2 ，[开, 关]
//- 按压开关 3 ，[关, 开]
//
//
//  示例 3：
//
//
// 输入：n = 3, presses = 1
// 输出：4
// 解释：状态可以是：
//- 按压开关 1 ，[关, 关, 关]
//- 按压开关 2 ，[关, 开, 关]
//- 按压开关 3 ，[开, 关, 开]
//- 按压开关 4 ，[关, 开, 开]
//
//
//
//
//  提示：
//
//
//  1 <= n <= 1000
//  0 <= presses <= 1000
//
//
//  Related Topics 位运算 深度优先搜索 广度优先搜索 数学 👍 237 👎 0

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
  int flipLights(int n, int presses) {
    // 0 , 1 , 2, 3, 4, 5, 6
    // 0,2,4,6
    //1,3,5,7
    // 1, 4, 7, 10
    presses = min(4, presses);

  }
};
// leetcode submit region end(Prohibit modification and deletion)
