// 给你一个整数 finalSum 。请你将它拆分成若干个 互不相同
// 的正偶数之和，且拆分出来的正偶数数目 最多 。
//
//
//  比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求
//  的（互不相同的正偶数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8)
//  。它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 +
//  4 + 4) ，因为拆分
// 出来的整数必须互不相同。
//
//
//  请你返回一个整数数组，表示将整数拆分成 最多 数目的正偶数数组。如果没有办法将
//  finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返
// 回这些整数。
//
//
//
//  示例 1：
//
//
// 输入：finalSum = 12
// 输出：[2,4,6]
// 解释：以下是一些符合要求的拆分：(2 + 10)，(2 + 4 + 6) 和 (4 + 8) 。
//(2 + 4 + 6) 为最多数目的整数，数目为 3 ，所以我们返回 [2,4,6] 。
//[2,6,4] ，[6,2,4] 等等也都是可行的解。
//
//
//  示例 2：
//
//
// 输入：finalSum = 7
// 输出：[]
// 解释：没有办法将 finalSum 进行拆分。
// 所以返回空数组。
//
//
//  示例 3：
//
//
// 输入：finalSum = 28
// 输出：[6,8,2,12]
// 解释：以下是一些符合要求的拆分：(2 + 26)，(6 + 8 + 2 + 12) 和 (4 + 24) 。
//(6 + 8 + 2 + 12) 有最多数目的整数，数目为 4 ，所以我们返回 [6,8,2,12] 。
//[10,2,4,12] ，[6,2,4,16] 等等也都是可行的解。
//
//
//
//
//  提示：
//
//
//  1 <= finalSum <= 10¹⁰
//
//
//  Related Topics 贪心 数学 回溯 👍 21 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum & 1)
      return {};
    if (finalSum == 2)
      return {2};
    vector<long long> ans;
    for (long long i = 2; finalSum > 0; i += 2) {
      if (i > finalSum)
        ans.back() += finalSum;
      else ans.emplace_back(i);
      finalSum -= i;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
