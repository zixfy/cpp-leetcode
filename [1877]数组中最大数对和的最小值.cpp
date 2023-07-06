// 一个数对 (a,b) 的 数对和 等于 a + b 。最大数对和 是一个数对数组中最大的
// 数对和 。
//
//
//  比方说，如果我们有数对 (1,5) ，(2,3) 和 (4,4)，最大数对和 为 max(1+5, 2+3,
//  4+4) = max(6, 5, 8) =
// 8 。
//
//
//  给你一个长度为 偶数 n 的数组 nums ，请你将 nums 中的元素分成 n / 2
//  个数对，使得：
//
//
//  nums 中每个元素 恰好 在 一个 数对中，且
//  最大数对和 的值 最小 。
//
//
//  请你在最优数对划分的方案下，返回最小的 最大数对和 。
//
//
//
//  示例 1：
//
//  输入：nums = [3,5,2,3]
// 输出：7
// 解释：数组中的元素可以分为数对 (3,3) 和 (5,2) 。
// 最大数对和为 max(3+3, 5+2) = max(6, 7) = 7 。
//
//
//  示例 2：
//
//  输入：nums = [3,5,4,2,4,6]
// 输出：8
// 解释：数组中的元素可以分为数对 (3,5)，(4,4) 和 (6,2) 。
// 最大数对和为 max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8 。
//
//
//
//
//  提示：
//
//
//  n == nums.length
//  2 <= n <= 10⁵
//  n 是 偶数 。
//  1 <= nums[i] <= 10⁵
//
//
//  Related Topics 贪心 数组 双指针 排序 👍 105 👎 0

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
  int minPairSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    size_t p1 = 0, p2 = nums.size() - 1;
    int ans = 0;
    while (p1 < p2)
      ans = max(ans, nums[p1++] + nums[p2--]);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
