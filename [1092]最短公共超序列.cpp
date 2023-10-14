// 给你两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为 子序列
// 的最短字符串。如果答案不止一个，则可以返回满足条件的 任意一个 答 案。
//
//  如果从字符串 t 中删除一些字符（也可能不删除），可以得到字符串 s ，那么 s
//  就是 t 的一个子序列。
//
//
//
//  示例 1：
//
//
// 输入：str1 = "abac", str2 = "cab"
// 输出："cabac"
// 解释：
// str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个
// "c"得到 "abac"。 str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac"
// 末尾的 "ac" 得到 "cab"。 最终我们给出的答案是满足上述属性的最短字符串。
//
//
//  示例 2：
//
//
// 输入：str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// 输出："aaaaaaaa"
//
//
//
//
//  提示：
//
//
//  1 <= str1.length, str2.length <= 1000
//  str1 和 str2 都由小写英文字母组成。
//
//
//  Related Topics 字符串 动态规划 👍 236 👎 0

#include <algorithm>
#include <array>
#include <format>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>
using namespace std;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    // dp[i][j] = dp[i - 1][j - 1] + == |
    auto m = str1.size(), n = str2.size();
    enum class What : char { Same, MinusI, MinusJ };
    vector dp(m, vector(n, pair<int, What>{0, What::MinusJ}));
    dp[0][0] =
        (str1[0] == str2[0]) ? pair{1, What::Same} : pair{0, What::MinusJ};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i && j &&(str1[i] == str2[j]) &&
            dp[i - 1][j - 1].first + 1 > dp[i][j].first) {
          dp[i][j] = make_pair(dp[i - 1][j - 1].first + 1,What::Same);
        }
        if (i && dp[i - 1][j].first >= dp[i][j].first) {
          dp[i][j] = make_pair(dp[i - 1][j].first, What::MinusI);
        }
        if (j && dp[i][j - 1].first >= dp[i][j].first) {
          dp[i][j] = make_pair(dp[i][j - 1].first, What::MinusJ);
        }
      }
    }
    string ans{};
    int i = m - 1, j = n - 1;
    //    auto what = dp.back().back().second;
    while (i >= 0 && j >= 0) {
      auto what = dp[i][j].second;
      if (what == What::Same) {
        ans += str1[i];
        --i, --j;
      }
      else if (what == What::MinusJ)
        ans += str2[j--];
      //        --j;
      else
        //        --i;
        ans += str1[i--];
//      cout << i << ", " << j << ", " << ans << endl;
    }
//    cout << ans << endl;
//    cout << i << ", " << j << endl;
    while (i >= 0)
      ans += str1[i--];
    while (j >= 0)
      ans += str2[j--];
    std::reverse(ans.begin(), ans.end());
    return ans;
    //      return  ;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
