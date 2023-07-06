// 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//
//
//
//  示例 1：
//
//
// 输入：nums = [3,2,3]
// 输出：[3]
//
//  示例 2：
//
//
// 输入：nums = [1]
// 输出：[1]
//
//
//  示例 3：
//
//
// 输入：nums = [1,2]
// 输出：[1,2]
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 5 * 10⁴
//  -10⁹ <= nums[i] <= 10⁹
//
//
//
//
//  进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
//
//  Related Topics 数组 哈希表 计数 排序 👍 675 👎 0

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
  vector<int> majorityElement(vector<int> &nums) {
    int cnt1 = 0, num1 = numeric_limits<int>::max();
    int cnt2 = 0, num2 = numeric_limits<int>::min();

    for (auto num : nums) {
      if (num == num1)
        cnt1 += 2;
      else
        cnt1--;
      if (cnt1 < 0)
        cnt1 = 2, num1 = num;

      if (num == num2)
        cnt2 += 2;
      else
        cnt2--;
      if (cnt2 < 0)
        cnt2 = 2, num2 = num;
    }
    vector<int> ans;
    if (cnt1 > 0 && num1 !=  numeric_limits<int>::max())
      ans.push_back(num1);
    if (cnt2 > 0 && num2 !=  numeric_limits<int>::min())
      ans.push_back(num2);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
