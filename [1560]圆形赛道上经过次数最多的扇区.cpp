// 给你一个整数 n 和一个整数数组 rounds 。有一条圆形赛道由 n
// 个扇区组成，扇区编号从 1 到 n
// 。现将在这条赛道上举办一场马拉松比赛，该马拉松全 程由 m 个阶段组成。其中，第
// i 个阶段将会从扇区 rounds[i - 1] 开始，到扇区 rounds[i] 结束。举例来说，第 1
// 阶段从 rounds[0] 开始，到 rounds[1] 结束。
//
//  请你以数组形式返回经过次数最多的那几个扇区，按扇区编号 升序 排列。
//
//  注意，赛道按扇区编号升序逆时针形成一个圆（请参见第一个示例）。
//
//
//
//  示例 1：
//
//
//
//  输入：n = 4, rounds = [1,3,1,2]
// 输出：[1,2]
// 解释：本场马拉松比赛从扇区 1 开始。经过各个扇区的次序如下所示：
// 1 --> 2 --> 3（阶段 1 结束）--> 4 --> 1（阶段 2 结束）--> 2（阶段 3
// 结束，即本场马拉松结束） 其中，扇区 1 和 2
// 都经过了两次，它们是经过次数最多的两个扇区。扇区 3 和 4 都只经过了一次。
//
//  示例 2：
//
//  输入：n = 2, rounds = [2,1,2,1,2,1,2,1,2]
// 输出：[2]
//
//
//  示例 3：
//
//  输入：n = 7, rounds = [1,3,5,7]
// 输出：[1,2,3,4,5,6,7]
//
//
//
//
//  提示：
//
//
//  2 <= n <= 100
//  1 <= m <= 100
//  rounds.length == m + 1
//  1 <= rounds[i] <= n
//  rounds[i] != rounds[i + 1] ，其中 0 <= i < m
//
//
//  Related Topics 数组 模拟 👍 39 👎 0

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
  vector<int> mostVisited(int n, vector<int> &rounds) {
    auto start = rounds.front(), end = rounds.back();

    vector<int> ans;
    if (start <= end)
      for (int i = start; i <= end; ++i)
        ans.emplace_back(i > n ? i - n : i);
    else {
      for (int i = 1; i <= end; ++i)
        ans.emplace_back(i);
      for (int i = start; i <= n; ++i)
        ans.emplace_back(i);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
