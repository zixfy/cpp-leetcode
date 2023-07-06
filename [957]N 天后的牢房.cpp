// 监狱中 8 间牢房排成一排，每间牢房可能被占用或空置。
//
//  每天，无论牢房是被占用或空置，都会根据以下规则进行变更：
//
//
//  如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。
//  否则，它就会被空置。
//
//
//  注意：由于监狱中的牢房排成一行，所以行中的第一个和最后一个牢房不存在两个相邻的房间。
//
//  给你一个整数数组 cells ，用于表示牢房的初始状态：如果第 i 间牢房被占用，则
//  cell[i]==1，否则 cell[i]==0 。另给你一个整数
// n 。
//
//  请你返回 n 天后监狱的状况（即，按上文描述进行 n 次变更）。
//
//
//
//  示例 1：
//
//
// 输入：cells = [0,1,0,1,1,0,0,1], n = 7
// 输出：[0,0,1,1,0,0,0,0]
// 解释：下表总结了监狱每天的状况：
// Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
// Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
// Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
// Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
// Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
// Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
// Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
// Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
//
//
//  示例 2：
//
//
// 输入：cells = [1,0,0,1,0,0,1,0], n = 1000000000
// 输出：[0,0,1,1,1,1,1,0]
//
//
//
//
//  提示：
//
//
//  cells.length == 8
//  cells[i] 为 0 或 1
//  1 <= n <= 10⁹
//
//
//  Related Topics 位运算 数组 哈希表 数学 👍 143 👎 0

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
  vector<int> prisonAfterNDays(vector<int> &cells, int n) {
    int stat = 0;
    vector<int> loops;
    unordered_set<int> vis;
    const auto m = cells.size();
    for (int i = 0; i < m; i++) {
      stat |= cells[i] << i;
    }
    while (true) {
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
