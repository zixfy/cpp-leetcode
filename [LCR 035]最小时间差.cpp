//给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：timePoints = ["23:59","00:00"]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：timePoints = ["00:00","23:59","00:00"]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 2 <= timePoints <= 2 * 10⁴ 
// timePoints[i] 格式为 "HH:MM" 
// 
//
// 
//
// 
// 注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/ 
//
// Related Topics 数组 数学 字符串 排序 👍 49 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        auto const n = timePoints.size();
        vector<int> minutes;
        minutes.reserve(n + 1);
        for (auto &time: timePoints) {
            auto hour = (time[0] - '0') * 10 + time[1] - '0';
            auto minu = (time[3] - '0') * 10 + time[4] - '0';
            minutes.emplace_back(hour * 60 + minu);
        }
        std::sort(minutes.begin(), minutes.end());
        minutes.emplace_back(24 * 60 + minutes.front());
        for (int i = minutes.size() - 1; i >  0; --i)
            minutes[i] -= minutes[i - 1];
        return *std::min_element(minutes.begin() + 1, minutes.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)




