// 在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
//
//  请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。
//  你可以返回任何满足该要求的答案，此题保证存在答案。
//
//
//
//  示例 1：
//
//
// 输入：barcodes = [1,1,1,2,2,2]
// 输出：[2,1,2,1,2,1]
//
//
//  示例 2：
//
//
// 输入：barcodes = [1,1,1,1,2,2,3,3]
// 输出：[1,3,1,3,2,1,2,1]
//
//
//
//  提示：
//
//
//  1 <= barcodes.length <= 10000
//  1 <= barcodes[i] <= 10000
//
//
//  Related Topics 贪心 数组 哈希表 计数 排序 堆（优先队列） 👍 141 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    unordered_map<int, int> cnt;
    for (auto b : barcodes)
      cnt[b]++;
    auto vec = vector<pair<int, int>>(cnt.begin(), cnt.end());
    sort(vec.begin(), vec.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second > b.second;
         });
    vector<int> ans(barcodes.size());
    int idx = 0;
    for (auto [k, v] : vec)
      for (int i = 0; i < v; ++i) {
        ans[idx] = k;
        idx += 2;
        if (idx >= barcodes.size())
          idx = 1;
      }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
