//给你一个长度为 n 下标从 0 开始的整数数组 receiver 和一个整数 k 。 
//
// 总共有 n 名玩家，玩家 编号 互不相同，且为 [0, n - 1] 中的整数。这些玩家玩一个传球游戏，receiver[i] 表示编号为 i 的玩家会传
//球给编号为 receiver[i] 的玩家。玩家可以传球给自己，也就是说 receiver[i] 可能等于 i 。 
//
// 你需要从 n 名玩家中选择一名玩家作为游戏开始时唯一手中有球的玩家，球会被传 恰好 k 次。 
//
// 如果选择编号为 x 的玩家作为开始玩家，定义函数 f(x) 表示从编号为 x 的玩家开始，k 次传球内所有接触过球玩家的编号之 和 ，如果有玩家多次触球，
//则 累加多次 。换句话说， f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver⁽ᵏ⁾
//[x] 。 
//
// 你的任务时选择开始玩家 x ，目的是 最大化 f(x) 。 
//
// 请你返回函数的 最大值 。 
//
// 注意：receiver 可能含有重复元素。 
//
// 
//
// 示例 1： 
//
// 
// 
// 
// 传递次数 
// 传球者编号 
// 接球者编号 
// x + 所有接球者编号 
// 
// 
// 
// 
// 
// 2 
// 
// 
// 1 
// 2 
// 1 
// 3 
// 
// 
// 2 
// 1 
// 0 
// 3 
// 
// 
// 3 
// 0 
// 2 
// 5 
// 
// 
// 4 
// 2 
// 1 
// 6 
// 
// 
// 
//
// 
//
// 
//输入：receiver = [2,0,1], k = 4
//输出：6
//解释：上表展示了从编号为 x = 2 开始的游戏过程。
//从表中可知，f(2) 等于 6 。
//6 是能得到最大的函数值。
//所以输出为 6 。
// 
//
// 示例 2： 
//
// 
// 
// 
// 传递次数 
// 传球者编号 
// 接球者编号 
// x + 所有接球者编号 
// 
// 
// 
// 
// 
// 4 
// 
// 
// 1 
// 4 
// 3 
// 7 
// 
// 
// 2 
// 3 
// 2 
// 9 
// 
// 
// 3 
// 2 
// 1 
// 10 
// 
// 
// 
//
// 
//
// 
//输入：receiver = [1,1,1,2,3], k = 3
//输出：10
//解释：上表展示了从编号为 x = 4 开始的游戏过程。
//从表中可知，f(4) 等于 10 。
//10 是能得到最大的函数值。
//所以输出为 10 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= receiver.length == n <= 10⁵ 
// 0 <= receiver[i] <= n - 1 
// 1 <= k <= 10¹⁰ 
// 
//
// Related Topics 位运算 数组 动态规划 👍 27 👎 0


#include <string>
#include <vector>
#include <algorithm>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
using i64 = std::int64_t;

class Solution {
public:
    long long getMaxFunctionValue(vector<int> &receiver, long long k) {
        const auto n = receiver.size();
        vector<vector<i64>> st(n), nxt(n);
        int log_k = 0;
        {
            auto k_copy = k;
            --k_copy;
            while (k_copy > 0) {
                log_k++;
                k_copy >>= 1;
            }
        }
//        cout << log_k << endl;
        for (auto i = 0; i < n; ++i) {

            auto &table = st[i], &to = nxt[i];
            table.resize(log_k + 1);
            to.resize(log_k + 1);
            table.front() = receiver[i];
            to.front() = receiver[i];
        }
        for (auto i = 1; i <= log_k; ++i) {
            for (auto j = 0; j < n; ++j) {
                st[j][i] = st[j][i - 1] + st[nxt[j][i - 1]][i - 1];
                nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
            }
        }
        i64 ans = 0;
        vector<int> k_as_logs{};
        for (int l = log_k; l >= 0; --l)
            if (auto power = (i64{1} << l); power & k) {
                k_as_logs.emplace_back(l);
                k ^= power;
            }

        for (int i = 0; i < n; ++i) {
            i64 cur_s = i;
            int cur_p = i;
            for (auto l : k_as_logs) {
                cur_s += st[cur_p][l];
                cur_p = nxt[cur_p][l];
            }
            ans = max(ans, cur_s);

        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




