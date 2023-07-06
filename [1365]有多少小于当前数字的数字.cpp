// 给你一个数组 nums，对于其中每个元素
// nums[i]，请你统计数组中比它小的所有数字的数目。
//
//  换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i
//  且 nums[j] < nums[i] 。
//
//  以数组形式返回答案。
//
//
//
//  示例 1：
//
//  输入：nums = [8,1,2,2,3]
// 输出：[4,0,1,1,3]
// 解释：
// 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
// 对于 nums[1]=1 不存在比它小的数字。
// 对于 nums[2]=2 存在一个比它小的数字：（1）。
// 对于 nums[3]=2 存在一个比它小的数字：（1）。
// 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
//
//
//  示例 2：
//
//  输入：nums = [6,5,4,8]
// 输出：[2,1,0,3]
//
//
//  示例 3：
//
//  输入：nums = [7,7,7,7]
// 输出：[0,0,0,0]
//
//
//
//
//  提示：
//
//
//  2 <= nums.length <= 500
//  0 <= nums[i] <= 100
//
//
//  Related Topics 数组 哈希表 计数 排序 👍 258 👎 0

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
template <typename T> auto right_lower_bound(const vector<T> &arr, const T &x) {
  // [l, r)
  int l = -1, r = arr.size();
  while (l + 1 < r) {
    auto m = (l + r) >> 1;
    const auto &mid_val = arr[m];
    if (mid_val > x)
      r = m;
    else
      l = m;
  }
  return l < 0 ? arr.end() : arr.begin() + l;
}

template <typename T> auto left_lower_bound(const vector<T> &arr, const T &x) {
  // [l, r)
  auto ret = right_lower_bound(arr, x);
  if (ret != arr.end())
    while (ret > arr.begin() && *ret == *(ret - 1))
      ret--;
  return ret;
}
class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    auto sorted_nums(nums);
    std::sort(sorted_nums.begin(), sorted_nums.end());
    vector<int> ans;
    ans.reserve(nums.size());
    for (auto n : nums)
      ans.emplace_back(left_lower_bound(sorted_nums, n) - sorted_nums.begin());
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
