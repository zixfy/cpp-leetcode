//给你两个数组 nums1 和 nums2 。 
//
// 请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。 
//
// 数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，[2,3,5] 是 [1,2,3,4
//,5] 的一个子序列而 [1,5,3] 不是。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [2,1,-2,5], nums2 = [3,0,-6]
//输出：18
//解释：从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
//它们的点积为 (2*3 + (-2)*(-6)) = 18 。 
//
// 示例 2： 
//
// 
//输入：nums1 = [3,-2], nums2 = [2,-6,7]
//输出：21
//解释：从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
//它们的点积为 (3*7) = 21 。 
//
// 示例 3： 
//
// 
//输入：nums1 = [-1,-1], nums2 = [1,1]
//输出：-1
//解释：从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
//它们的点积为 -1 。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums1.length, nums2.length <= 500 
// -1000 <= nums1[i], nums2[i] <= 100 
// 
//
// 
//
// 点积： 
//
// 
//定义 a = [a1, a2,…, an] 和 b = [b1, b2,…, bn] 的点积为：
//
//
//
//这里的 Σ 指示总和符号。
// 
//
// Related Topics 数组 动态规划 👍 78 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




