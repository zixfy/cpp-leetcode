// 给你一个正整数数组 values，其中 values[i] 表示第 i
// 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
//
//  一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j
//  ，也就是景点的评分之和 减去 它们两者之间的距离
// 。
//
//  返回一对观光景点能取得的最高分。
//
//
//
//  示例 1：
//
//
// 输入：values = [8,1,5,2,6]
// 输出：11
// 解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
//
//
//  示例 2：
//
//
// 输入：values = [1,2]
// 输出：2
//
//
//
//
//  提示：
//
//
//  2 <= values.length <= 5 * 10⁴
//  1 <= values[i] <= 1000
//
//
//  Related Topics 数组 动态规划 👍 382 👎 0

#include <algorithm>
#include <array>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;

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
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    // dp[i] is max (dp[i] + dp[k] + k - i) for k < i
    //    vector dp(values.size(), 0);
    //    dp[0] = numeric_limits<int>::min();
    //    dp[1] =
    auto ans = values[0] + values[1] - 1;
    auto cur = ans;
    using u16 = uint16_t;
    for (u16 i = 2; i < values.size(); ++i) {
      cur = max(cur +  values[i] - values[i - 1] - 1, values[i] + values[i - 1] - 1) ;
//      cout << ans << ", " << cur << endl;
      ans = max(ans, cur);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
