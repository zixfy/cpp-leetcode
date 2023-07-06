// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中
// 至少有两个元素 。你可以按 任意顺序 返回答案。
//
//  数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
//
//
//
//  示例 1：
//
//
// 输入：nums = [4,6,7,7]
// 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//
//
//  示例 2：
//
//
// 输入：nums = [4,4,3,2,1]
// 输出：[[4,4]]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 15
//  -100 <= nums[i] <= 100
//
//
//  Related Topics 位运算 数组 哈希表 回溯 👍 657 👎 0

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

inline int low_bit(int x) { return x & -x; }
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    const int n = nums.size();
    vector<int> stk;
    stk.reserve(n + 1);
    stk.emplace_back(numeric_limits<int>::min());
    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int idx) {
      if (idx == n) {
        if (stk.size() > 2)
          ans.emplace_back(stk.begin() + 1, stk.end());
        return;
      }
      unordered_set<int> vis;
      for (; idx < n; ++idx) {
        auto v = nums[idx];
        if (v >= stk.back() && !vis.count(v)) {
          vis.emplace(v);
          stk.emplace_back(v);
          dfs(idx + 1);
          stk.pop_back();
        }
      }
      dfs(n);
    };
    dfs(0);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
