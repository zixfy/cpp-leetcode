// 给你一个 正 整数数组 nums 。
//
//  将 nums 分成两个数组：nums1 和 nums2 ，并满足下述条件：
//
//
//  数组 nums 中的每个元素都属于数组 nums1 或数组 nums2 。
//  两个数组都 非空 。
//  分区值 最小 。
//
//
//  分区值的计算方法是 |max(nums1) - min(nums2)| 。
//
//  其中，max(nums1) 表示数组 nums1 中的最大元素，min(nums2) 表示数组 nums2
//  中的最小元素。
//
//  返回表示分区值的整数。
//
//
//
//  示例 1：
//
//  输入：nums = [1,3,2,4]
// 输出：1
// 解释：可以将数组 nums 分成 nums1 = [1,2] 和 nums2 = [3,4] 。
//- 数组 nums1 的最大值等于 2 。
//- 数组 nums2 的最小值等于 3 。
// 分区值等于 |2 - 3| = 1 。
// 可以证明 1 是所有分区方案的最小值。
//
//
//  示例 2：
//
//  输入：nums = [100,1,10]
// 输出：9
// 解释：可以将数组 nums 分成 nums1 = [10] 和 nums2 = [100,1] 。
//- 数组 nums1 的最大值等于 10 。
//- 数组 nums2 的最小值等于 1 。
// 分区值等于 |10 - 1| = 9 。
// 可以证明 9 是所有分区方案的最小值。
//
//
//
//
//  提示：
//
//
//  2 <= nums.length <= 10⁵
//  1 <= nums[i] <= 10⁹
//
//
//  Related Topics 数组 排序 👍 3 👎 0

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
  int findValueOfPartition(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    using u32 = unsigned long;
    auto ans = nums[1] - nums[0];
    for (u32 i = 2l, n = nums.size(); i < n; ++i)
      ans = min(ans, nums[i] - nums[i - 1]);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
