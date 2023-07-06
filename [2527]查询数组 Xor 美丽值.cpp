//给你一个下标从 0 开始的整数数组 nums 。 
//
// 三个下标 i ，j 和 k 的 有效值 定义为 ((nums[i] | nums[j]) & nums[k]) 。 
//
// 一个数组的 xor 美丽值 是数组中所有满足 0 <= i, j, k < n 的三元组 (i, j, k) 的 有效值 的异或结果。 
//
// 请你返回 nums 的 xor 美丽值。 
//
// 注意： 
//
// 
// val1 | val2 是 val1 和 val2 的按位或。 
// val1 & val2 是 val1 和 val2 的按位与。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,4]
//输出：5
//解释：
//三元组和它们对应的有效值如下：
//- (0,0,0) 有效值为 ((1 | 1) & 1) = 1
//- (0,0,1) 有效值为 ((1 | 1) & 4) = 0
//- (0,1,0) 有效值为 ((1 | 4) & 1) = 1
//- (0,1,1) 有效值为 ((1 | 4) & 4) = 4
//- (1,0,0) 有效值为 ((4 | 1) & 1) = 1
//- (1,0,1) 有效值为 ((4 | 1) & 4) = 4
//- (1,1,0) 有效值为 ((4 | 4) & 1) = 0
//- (1,1,1) 有效值为 ((4 | 4) & 4) = 4 
//数组的 xor 美丽值为所有有效值的按位异或 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5 。 
//
// 示例 2： 
//
// 
//输入：nums = [15,45,20,2,34,35,5,44,32,30]
//输出：34
//解释：数组的 xor 美丽值为 34 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁹ 
// 
//
// Related Topics 位运算 数组 数学 👍 18 👎 0


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
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (auto n: nums)
          ans ^= n;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




