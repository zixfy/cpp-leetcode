// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n
// ，请你计算有多少个元组 (i, j, k, l) 能满足：
//
//
//  0 <= i, j, k, l < n
//  nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
//
//
//
//
//  示例 1：
//
//
// 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// 输出：2
// 解释：
// 两个元组如下：
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) +
// (-1)
//  + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) +
// (-1)
//  + 0 = 0
//
//
//  示例 2：
//
//
// 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// 输出：1
//
//
//
//
//  提示：
//
//
//  n == nums1.length
//  n == nums2.length
//  n == nums3.length
//  n == nums4.length
//  1 <= n <= 200
//  -2²⁸ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2²⁸
//
//
//  Related Topics 数组 哈希表 👍 814 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> pool1, pool2;
    for (auto a : nums1)
      for (auto b : nums2)
        pool1[a + b]++;
    for (auto a : nums3)
      for (auto b : nums4)
        pool2[-a - b]++;
//    cout << pool1 << endl << pool2 << endl;
    int ans = 0;
    for (auto [k, v] : pool1)
      if (pool2.count(k))
        ans += pool2[k] * v;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
