// 给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff
// 数对，并返回不同的 k-diff 数对 的数目。
//
//  k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：
//
//
//  0 <= i, j < nums.length
//  i != j
//  nums[i] - nums[j] == k
//
//
//  注意，|val| 表示 val 的绝对值。
//
//
//
//  示例 1：
//
//
// 输入：nums = [3, 1, 4, 1, 5], k = 2
// 输出：2
// 解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
// 尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
//
//
//  示例 2：
//
//
// 输入：nums = [1, 2, 3, 4, 5], k = 1
// 输出：4
// 解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
//
//
//  示例 3：
//
//
// 输入：nums = [1, 3, 1, 5, 4], k = 0
// 输出：1
// 解释：数组中只有一个 0-diff 数对，(1, 1) 。
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁴
//  -10⁷ <= nums[i] <= 10⁷
//  0 <= k <= 10⁷
//
//
//  Related Topics 数组 哈希表 双指针 二分查找 排序 👍 264 👎 0

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
  int findPairs(vector<int> &nums, int k) {
    int ans = 0;
    if (k == 0) {
      unordered_map<int, int> cnt;
      for (auto n: nums)
        cnt[n]++;
      for (auto [key, val] : cnt)
        if (val > 1)
          ans++;
    } else {
      set<int> cnt(nums.begin(), nums.end());
      for (auto key : cnt)
        if (int kd = key + k; cnt.count(kd))
          ans++;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
