// 给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
//
//  你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
//
//  请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue
//  。
//
//
//
//  示例 1：
//
//
// 输入：nums = [-3,2,-3,4,2]
// 输出：5
// 解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
//                 累加求和
//                 startValue = 4 | startValue = 5 | nums
//                   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
//                   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
//                   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
//                   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
//                   (4 +2 ) = 6  | (5 +2 ) = 7    |   2
//
//
//  示例 2：
//
//
// 输入：nums = [1,2]
// 输出：1
// 解释：最小的 startValue 需要是正数。
//
//
//  示例 3：
//
//
// 输入：nums = [1,-2,-3]
// 输出：5
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 100
//  -100 <= nums[i] <= 100
//
//
//  Related Topics 数组 前缀和 👍 108 👎 0

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

using namespace std;
template <typename Container> class PrefixView {
public:
  using Iter = typename Container::iterator;
  using T = typename std::iterator_traits<Iter>::value_type;
  PrefixView() = delete;
  explicit PrefixView(Iter begin, Iter end) {
    T sum{};
    for (auto it = begin; it != end; ++it)
      sum += *it, _prefix.emplace_back(sum);
  }
  PrefixView(Container vec) : PrefixView(vec.begin(), vec.end()) {}
  T get_range_sum(int l, int r) {
    return l > 0 ? (_prefix[r] - _prefix[l - 1]) : _prefix[r];
  }
  const T &get_prefix(int i) { return _prefix[i]; }
  friend class Solution;

private:
  std::vector<T> _prefix;
};
class Solution {
public:
  int minStartValue(vector<int> &nums) {
    auto pre = PrefixView(nums);
//    cout << "hi" << endl;
    auto p = min_element(pre._prefix.begin(), pre._prefix.end());
//    cout << (p == pre._prefix.end());
    return max(1 - (*min_element(pre._prefix.begin(), pre._prefix.end())), 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
