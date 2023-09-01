// 给你一个数组 seats 表示一排座位，其中 seats[i] = 1 代表有人坐在第 i
// 个座位上，seats[i] = 0 代表座位 i 上是空的（下标 从 0 开始）。
//
//  至少有一个空座位，且至少有一人已经坐在座位上。
//
//  亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
//
//  返回他到离他最近的人的最大距离。
//
//
//
//  示例 1：
//
//
// 输入：seats = [1,0,0,0,1,0,1]
// 输出：2
// 解释：
// 如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
// 如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
// 因此，他到离他最近的人的最大距离是 2 。
//
//
//  示例 2：
//
//
// 输入：seats = [1,0,0,0]
// 输出：3
// 解释：
// 如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
// 这是可能的最大距离，所以答案是 3 。
//
//
//  示例 3：
//
//
// 输入：seats = [0,1]
// 输出：1
//
//
//
//
//  提示：
//
//
//  2 <= seats.length <= 2 * 10⁴
//  seats[i] 为 0 或 1
//  至少有一个 空座位
//  至少有一个 座位上有人
//
//
//  Related Topics 数组 👍 236 👎 0

#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using std::vector;

class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    vector<int> occurred;
    for (auto iter = seats.begin(); iter != seats.end(); ++iter)
      if (*iter == 1)
        occurred.emplace_back(std::distance(seats.begin(), iter));
    auto ans =
        std::max(occurred.front(), int(seats.size()) - 1 - occurred.back());
    if (seats.size() > 1) {
      auto max_gap = std::accumulate(
          occurred.begin() + 1, occurred.end(), 0,
          [&, las = occurred.front()](auto acc, const auto cur) mutable {
            auto ret = std::max(acc, cur - las);
            las = cur;
            return ret;
          });
      ans = std::max(ans, max_gap / 2);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
