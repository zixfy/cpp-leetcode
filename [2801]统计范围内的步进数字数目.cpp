//给你两个正整数 low 和 high ，都用字符串表示，请你统计闭区间 [low, high] 内的 步进数字 数目。 
//
// 如果一个整数相邻数位之间差的绝对值都 恰好 是 1 ，那么这个数字被称为 步进数字 。 
//
// 请你返回一个整数，表示闭区间 [low, high] 之间步进数字的数目。 
//
// 由于答案可能很大，请你将它对 10⁹ + 7 取余 后返回。 
//
// 注意：步进数字不能有前导 0 。 
//
// 
//
// 示例 1： 
//
// 输入：low = "1", high = "11"
//输出：10
//解释：区间 [1,11] 内的步进数字为 1 ，2 ，3 ，4 ，5 ，6 ，7 ，8 ，9 和 10 。总共有 10 个步进数字。所以输出为 10 。 
//
// 示例 2： 
//
// 输入：low = "90", high = "101"
//输出：2
//解释：区间 [90,101] 内的步进数字为 98 和 101 。总共有 2 个步进数字。所以输出为 2 。 
//
// 
//
// 提示： 
//
// 
// 1 <= int(low) <= int(high) < 10¹⁰⁰ 
// 1 <= low.length, high.length <= 100 
// low 和 high 只包含数字。 
// low 和 high 都不含前导 0 。 
// 
//
// Related Topics 字符串 动态规划 👍 16 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
struct D {
    int limited{0}, unlimited{0};
};

constexpr int MOD = 1e9 + 7;

int f(const string &s) {
    auto const n = s.size();
    std::vector dp(n, std::vector<D>(10));
    auto ans = 0;
    for (int i = 0; i < 10; ++i) {
        dp[0][i].unlimited = 1;
        dp[0][i].limited = (s.back() - '0' >= i);

        ans += (n == 1) ? dp[0][i].limited : dp[0][i].unlimited;
    }
    for (int l = 1; l < n; ++l)
        for (int i = 0; i < 10; ++i) {
            if (i == 0)
                dp[l][i].unlimited = dp[l - 1][i + 1].unlimited;
            else if (i == 9)
                dp[l][i].unlimited = dp[l - 1][i - 1].unlimited;
            else
                dp[l][i].unlimited = (dp[l - 1][i + 1].unlimited + dp[l - 1][i - 1].unlimited) % MOD;

            if (i == (s[n - 1 - l] - '0'))
                dp[l][i].limited =
                        ((i > 0 ? dp[l - 1][i - 1].limited : 0) + (i < 9 ? dp[l - 1][i + 1].limited : 0)) % MOD;
            else if (i < (s[n - 1 - l] - '0'))
                dp[l][i].limited = dp[l][i].unlimited;
            else
                ;
//            vector v{ans, l, i, dp[l][i].limited};
//            for (auto i: v)
//                cout << i << " ";
//            cout << endl;
            if (i > 0)
                ans = (ans + ((l == n - 1) ? dp[l][i].limited : dp[l][i].unlimited)) % MOD;
        }
    return ans;
}

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
//        cout << f(high) << "@" << endl;
        auto ans = (MOD + f(high) - f(low)) % MOD;
        auto b = false;
        for (int i = 1; i < low.size(); ++i)
            if (std::abs(low[i] - low[i - 1]) != 1) {
                b = true;
                break;
            }
        if (!b)
            ans = (ans + 1) % MOD;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




