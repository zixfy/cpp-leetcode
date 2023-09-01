// 给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti,
// endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。同时给你一个下标从
// 0 开始大小为 n 的整数数组 persons ，persons[i] 是第 i 个人来看花的时间。
//
//  请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i
//  个人到达时在花期内花的 数目 。
//
//
//
//  示例 1：
//
//
//
//  输入：flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
// 输出：[1,2,2,2]
// 解释：上图展示了每朵花的花期时间，和每个人的到达时间。
// 对每个人，我们返回他们到达时在花期内花的数目。
//
//
//  示例 2：
//
//
//
//  输入：flowers = [[1,10],[3,3]], persons = [3,3,2]
// 输出：[2,2,1]
// 解释：上图展示了每朵花的花期时间，和每个人的到达时间。
// 对每个人，我们返回他们到达时在花期内花的数目。
//
//
//
//
//  提示：
//
//
//  1 <= flowers.length <= 5 * 10⁴
//  flowers[i].length == 2
//  1 <= starti <= endi <= 10⁹
//  1 <= persons.length <= 5 * 10⁴
//  1 <= persons[i] <= 10⁹
//
//
//  Related Topics 数组 哈希表 二分查找 有序集合 前缀和 排序 👍 49 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    auto const n = flowers.size(), m = people.size();
    vector<int> ls, rs;
    ls.reserve(n), rs.reserve(n);
    std::transform(flowers.begin(), flowers.end(), back_inserter(ls),
                   [](auto const &a) { return a[0]; });
    std::transform(flowers.begin(), flowers.end(), back_inserter(rs),
                   [](auto const &a) { return a[1]; });
    std::sort(ls.begin(), ls.end());
    std::sort(rs.begin(), rs.end());
    vector<int> ans;
    ans.reserve(m);
    for (auto p: people) {
      auto bloomed = std::distance(ls.begin(), std::upper_bound(ls.begin(), ls.end(), p));
      auto dead = std::distance(rs.begin(), std::lower_bound(rs.begin(), rs.end(), p));
      ans.emplace_back(bloomed - dead);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
