// 给你两个 非递增 的整数数组 nums1 和 nums2 ，数组下标均 从 0 开始 计数。
//
//  下标对 (i, j) 中 0 <= i < nums1.length 且 0 <= j < nums2.length
//  。如果该下标对同时满足 i <=
// j 且 nums1[i] <= nums2[j] ，则称之为 有效 下标对，该下标对的 距离 为 j - i 。
//
//  返回所有 有效 下标对 (i, j) 中的 最大距离 。如果不存在有效下标对，返回 0 。
//
//  一个数组 arr ，如果每个 1 <= i < arr.length 均有 arr[i-1] >= arr[i]
//  成立，那么该数组是一个 非递增 数组。
//
//
//
//
//  示例 1：
//
//
// 输入：nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
// 输出：2
// 解释：有效下标对是 (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) 和 (4,4) 。
// 最大距离是 2 ，对应下标对 (2,4) 。
//
//
//  示例 2：
//
//
// 输入：nums1 = [2,2,2], nums2 = [10,10,1]
// 输出：1
// 解释：有效下标对是 (0,0), (0,1) 和 (1,1) 。
// 最大距离是 1 ，对应下标对 (0,1) 。
//
//  示例 3：
//
//
// 输入：nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
// 输出：2
// 解释：有效下标对是 (2,2), (2,3), (2,4), (3,3) 和 (3,4) 。
// 最大距离是 2 ，对应下标对 (2,4) 。
//
//
//
//
//  提示：
//
//
//  1 <= nums1.length <= 10⁵
//  1 <= nums2.length <= 10⁵
//  1 <= nums1[i], nums2[j] <= 10⁵
//  nums1 和 nums2 都是 非递增 数组
//
//
//  Related Topics 贪心 数组 双指针 二分查找 👍 71 👎 0

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
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int i = nums1.size() - 1, j = nums2.size() - 1;
    int ans = 0;
    while (i >= 0 && j >= 0) {
      if (i > j)
        i = j;
      if (nums1[i] <= nums2[j]) {
        while (i >= 0 && nums1[i] <= nums2[j])
          --i;
        ans = max(ans, j - i - 1);
      }
      --j;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
