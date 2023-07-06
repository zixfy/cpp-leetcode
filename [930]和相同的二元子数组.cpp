// 给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的
// 非空 子数组。
//
//  子数组 是数组的一段连续部分。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,0,1,0,1], goal = 2
// 输出：4
// 解释：
// 有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
//
//
//  示例 2：
//
//
// 输入：nums = [0,0,0,0,0], goal = 0
// 输出：15
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 3 * 10⁴
//  nums[i] 不是 0 就是 1
//  0 <= goal <= nums.length
//
//
//  Related Topics 数组 哈希表 前缀和 滑动窗口 👍 274 👎 0

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
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    map<int, int> cnt;
    cnt[0]++;
    int pre = 0;
    for (auto n : nums)
      cnt[pre += n]++;
    int ans = 0;
    //    cout << cnt;
    if (goal == 0)
      for (const auto &[k, v] : cnt) {
          ans += v * (v - 1) >> 1;
      }
    else
          for (const auto &[k, v] : cnt)
            if (auto j = k + goal; cnt.count(j))
              ans += v * cnt[j];
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
