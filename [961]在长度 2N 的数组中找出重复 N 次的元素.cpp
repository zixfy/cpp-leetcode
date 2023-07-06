// 给你一个整数数组 nums ，该数组具有以下属性：
//
//
//
//
//  nums.length == 2 * n.
//  nums 包含 n + 1 个 不同的 元素
//  nums 中恰有一个元素重复 n 次
//
//
//
//
//  找出并返回重复了 n 次的那个元素。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,3,3]
// 输出：3
//
//
//  示例 2：
//
//
// 输入：nums = [2,1,2,5,3,2]
// 输出：2
//
//
//  示例 3：
//
//
// 输入：nums = [5,1,5,2,5,3,5,4]
// 输出：5
//
//
//
//
//
//  提示：
//
//
//  2 <= n <= 5000
//  nums.length == 2 * n
//  0 <= nums[i] <= 10⁴
//  nums 由 n + 1 个 不同的 元素组成，且其中一个元素恰好重复 n 次
//
//
//  Related Topics 数组 哈希表 👍 189 👎 0

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
  int repeatedNTimes(vector<int> &nums) {
    unordered_set<int> cnt;
    for (auto n : nums)
      if (cnt.count(n))
        return n;
      else
        cnt.insert(n);
    return -1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
