// 给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，arr2 中的每个元素都出现在
// arr1 中。
//
//  对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2
//  中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末
// 尾。
//
//
//
//  示例 1：
//
//
// 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// 输出：[2,2,2,1,4,3,3,9,6,7,19]
//
//
//  示例 2:
//
//
// 输入：arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// 输出：[22,28,8,6,17,44]
//
//
//
//
//  提示：
//
//
//  1 <= arr1.length, arr2.length <= 1000
//  0 <= arr1[i], arr2[i] <= 1000
//  arr2 中的元素 arr2[i] 各不相同
//  arr2 中的每个元素 arr2[i] 都出现在 arr1 中
//
//
//  Related Topics 数组 哈希表 计数排序 排序 👍 260 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}
class Solution {
public:
  auto relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> to_idxs;
    vector repeats(arr2.size(), 0);
    vector<int> ans;
    ans.reserve(arr1.size());
    transform(arr2.begin(), arr2.end(), inserter(to_idxs, to_idxs.end()),
              [&arr2](const int &v) {
                return make_pair(v, static_cast<int>(&v - &arr2[0]));
              });
    for (auto a : arr1)
      if (to_idxs.count(a))
        repeats[to_idxs[a]]++;
      else
        ans.emplace_back(a);
    sort(ans.begin(), ans.end(), greater<>());
    for (auto n = arr2.size(); n-- > 0;)
      ans.insert(ans.end(), repeats[n], arr2[n]);
    reverse(ans.begin(), ans.end());
//      cout << to_idxs;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
