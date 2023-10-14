// 给定一个长度为 n 的字符串 s ，其中 s[i] 是:
//
//
//  “D” 意味着减少，或者
//  “I” 意味着增加
//
//
//  有效排列 是对有 n + 1 个在 [0, n] 范围内的整数的一个排列 perm ，使得对所有的
//  i：
//
//
//  如果 s[i] == 'D'，那么 perm[i] > perm[i+1]，以及；
//  如果 s[i] == 'I'，那么 perm[i] < perm[i+1]。
//
//
//  返回 有效排列 perm的数量 。因为答案可能很大，所以请返回你的答案对 10⁹ + 7
//  取余。
//
//
//
//  示例 1：
//
//
// 输入：s = "DID"
// 输出：5
// 解释：
//(0, 1, 2, 3) 的五个有效排列是：
//(1, 0, 3, 2)
//(2, 0, 3, 1)
//(2, 1, 3, 0)
//(3, 0, 2, 1)
//(3, 1, 2, 0)
//
//
//  示例 2:
//
//
// 输入: s = "D"
// 输出: 1
//
//
//
//
//  提示:
//
//
//  n == s.length
//  1 <= n <= 200
//  s[i] 不是 'I' 就是 'D'
//
//
//  Related Topics 字符串 动态规划 前缀和 👍 133 👎 0

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
  int numPermsDISequence(string s) {
    static int Mod = 1e9 + 7;
    // dp[D] =
    auto n = s.size() + 1;
    vector dp(n, vector(n, 0));
    dp[0][0] = 1;
    for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
      auto c = *iter;
      auto len = iter - s.rbegin() + 1;
      if (c == 'I') {
        for (int i = 0; i <= len; ++i)
          for (int j = i + 1; j <= len; ++j)
            dp[len][i] = (dp[len][i] + dp[len - 1][j - 1]) % Mod;
      } else {
        for (int i = 0; i <= len; ++i)
          for (int j = i - 1; j >= 0; --j)
            dp[len][i] = (dp[len][i] + dp[len - 1][j]) % Mod;
      }
//      std::copy(dp[len].begin(), dp[len].begin() + len, )
    }
    int ans = 0;
    for (auto v: dp.back())
      ans = (ans + v)%Mod;
    return ans;
    // dp[i] = dp[i][j] total i + 1, jth
  }
};
// leetcode submit region end(Prohibit modification and deletion)
