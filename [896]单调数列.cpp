// 如果数组是单调递增或单调递减的，那么它是 单调 的。
//
//  如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。
//  如果对于所有 i <= j，nums[i]> =
// nums[j]，那么数组 nums 是单调递减的。
//
//  当给定的数组 nums 是单调数组时返回 true，否则返回 false。
//
//
//
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,2,3]
// 输出：true
//
//
//  示例 2：
//
//
// 输入：nums = [6,5,4,4]
// 输出：true
//
//
//  示例 3：
//
//
// 输入：nums = [1,3,2]
// 输出：false
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  -10⁵ <= nums[i] <= 10⁵
//
//
//  Related Topics 数组 👍 189 👎 0

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
  bool isMonotonic(vector<int> &nums) {
    bool lis = (nums.front() <= nums.back());
    bool ans = true;
    auto las = nums.front();
    if (lis)
      for (auto n: nums)
        if (n < las) {
          ans= false;
          break ;
        }
        else las = n;
    else
      for (auto n: nums)
        if (n > las) {
          ans= false;
          break ;
        }
        else las = n;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
