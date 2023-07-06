// 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k
// 。每一次操作中，你可以选择一个数并将它乘 2 。
//
//  你最多可以进行 k 次操作，请你返回 nums[0] | nums[1] | ... | nums[n - 1]
//  的最大值。
//
//  a | b 表示两个整数 a 和 b 的 按位或 运算。
//
//
//
//  示例 1：
//
//
// 输入：nums = [12,9], k = 1
// 输出：30
// 解释：如果我们对下标为 1 的元素进行操作，新的数组为 [12,18]
// 。此时得到最优答案为 12 和 18 的按位或运算的结果，也就是 30 。
//
//
//  示例 2：
//
//
// 输入：nums = [8,1,2], k = 2
// 输出：35
// 解释：如果我们对下标 0 处的元素进行操作，得到新数组 [32,1,2]
// 。此时得到最优答案为 32|1|2 = 35 。
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  1 <= nums[i] <= 10⁹
//  1 <= k <= 15
//
//
//  Related Topics 贪心 位运算 数组 前缀和 👍 15 👎 0

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
  long long maximumOr(vector<int> &nums, int k) {
    using u64 = ::uint64_t;
    auto low_bit = [](u64 x) {
      for (auto lower_bit = x & (x - 1); lower_bit != 0;) {
        x = lower_bit;
        lower_bit = x & (x - 1);
      }
      return x;
    };
    std::sort(nums.begin(), nums.end(), [&low_bit](const int &a, const int &b) {
      if (low_bit(a) == low_bit(b))
        return a < b;
      return a > b;
    });
    //    cout << "hi " << endl;
    u64 ans = 0;
    u64 las_base = numeric_limits<u64>::max();
    for (u64 num : nums) {
      auto old_num = num;
      num = low_bit(num);
      while (k && num < las_base)
        old_num <<= 1, num <<= 1, --k;
      las_base = num >> 1;
      //      cout << old_num << endl;
      ans |= old_num;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
