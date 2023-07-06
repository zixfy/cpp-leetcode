// 给你一个整数数组
// arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。
//
//  返回 至少 能删除数组中的一半整数的整数集合的最小大小。
//
//
//
//  示例 1：
//
//
// 输入：arr = [3,3,3,3,5,5,5,2,2,7]
// 输出：2
// 解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
// 大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
// 选择 {2,7} 是不可行的，它的结果数组为
// [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
//
//
//  示例 2：
//
//
// 输入：arr = [7,7,7,7,7,7]
// 输出：1
// 解释：我们只能选择集合 {7}，结果数组为空。
//
//
//
//
//  提示：
//
//
//  1 <= arr.length <= 10⁵
//  arr.length 为偶数
//  1 <= arr[i] <= 10⁵
//
//
//  Related Topics 贪心 数组 哈希表 排序 堆（优先队列） 👍 44 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <unordered_set>
#include <vector>
// #include <ranges>
using namespace std;
class Solution {
public:
  int minSetSize(vector<int> &arr) {
    const auto n{arr.size()};
    const auto half_n{n / 2};
    unordered_map<int, int> cnt;
    for (const auto a : arr)
      ++cnt[a];
    arr.clear();
    for (const auto &p : cnt)
      arr.emplace_back(p.second);
    sort(arr.begin(), arr.end(), greater<>());
    remove_const<decltype(n)>::type cur{}, ans{};
    for (const auto a : arr)
      if (++ans && (cur += a) >= half_n)
        break;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
