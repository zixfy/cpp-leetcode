// 给你一个整数数组 nums 。nums 中，子数组的 范围
// 是子数组中最大元素和最小元素的差值。
//
//  返回 nums 中 所有 子数组范围的 和 。
//
//  子数组是数组中一个连续 非空 的元素序列。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,3]
// 输出：4
// 解释：nums 的 6 个子数组如下所示：
//[1]，范围 = 最大 - 最小 = 1 - 1 = 0
//[2]，范围 = 2 - 2 = 0
//[3]，范围 = 3 - 3 = 0
//[1,2]，范围 = 2 - 1 = 1
//[2,3]，范围 = 3 - 2 = 1
//[1,2,3]，范围 = 3 - 1 = 2
// 所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
//
//  示例 2：
//
//
// 输入：nums = [1,3,3]
// 输出：4
// 解释：nums 的 6 个子数组如下所示：
//[1]，范围 = 最大 - 最小 = 1 - 1 = 0
//[3]，范围 = 3 - 3 = 0
//[3]，范围 = 3 - 3 = 0
//[1,3]，范围 = 3 - 1 = 2
//[3,3]，范围 = 3 - 3 = 0
//[1,3,3]，范围 = 3 - 1 = 2
// 所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
//
//
//  示例 3：
//
//
// 输入：nums = [4,-2,-3,4,1]
// 输出：59
// 解释：nums 中所有子数组范围的和是 59
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 1000
//  -10⁹ <= nums[i] <= 10⁹
//
//
//
//
//  进阶：你可以设计一种时间复杂度为 O(n) 的解决方案吗？
//
//  Related Topics 栈 数组 单调栈 👍 261 👎 0

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

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  long long subArrayRanges(vector<int> &nums) {
    auto ans = 0ll;
    vector<pair<int, int>> stk;
    const auto n = nums.size();
    vector<long long> dp(n);
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && stk.back().first >= nums[i])
        stk.pop_back();
      dp[i] = i - (stk.empty() ? -1 : stk.back().second);
      stk.emplace_back(nums[i], i);
    }
//    cout << dp << endl;
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && stk.back().first > nums[i])
        stk.pop_back();
      ans -= dp[i] * ((stk.empty() ? n : stk.back().second) - i)  * nums[i];
//      cout << ans << endl;
      stk.emplace_back(nums[i], i);
    }
    stk.clear();
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && stk.back().first <= nums[i])
        stk.pop_back();
      dp[i] = i - (stk.empty() ? -1 : stk.back().second);
      stk.emplace_back(nums[i], i);
    }
//    cout << dp << endl;
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && stk.back().first < nums[i])
        stk.pop_back();
      ans += dp[i] * ((stk.empty() ? n : stk.back().second) - i)  * nums[i];
      stk.emplace_back(nums[i], i);
    }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
