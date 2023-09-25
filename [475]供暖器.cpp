//冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。 
//
// 在加热器的加热半径范围内的每个房屋都可以获得供暖。 
//
// 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。 
//
// 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。 
//
// 
//
// 示例 1: 
//
// 
//输入: houses = [1,2,3], heaters = [2]
//输出: 1
//解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
// 
//
// 示例 2: 
//
// 
//输入: houses = [1,2,3,4], heaters = [1,4]
//输出: 1
//解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
// 
//
// 示例 3： 
//
// 
//输入：houses = [1,5], heaters = [2]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= houses.length, heaters.length <= 3 * 10⁴ 
// 1 <= houses[i], heaters[i] <= 10⁹ 
// 
//
// Related Topics 数组 双指针 二分查找 排序 👍 461 👎 0


#include <string>
#include <vector>
#include <algorithm>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;

using std::vector;
//leetcode submit region begin(Prohibit modification and deletion)
using i64 = std::int64_t;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        std::sort(heaters.begin(), heaters.end());
        auto ans = 0;
        auto left_heater = heaters.front(), right_heater = heaters.back();

        for (auto house: houses) {
            if (house <= left_heater)
                ans = std::max(ans, left_heater - house);
            else if (house >= right_heater)
                ans = std::max(ans, house - right_heater);
            else {
                int l = 0, r = heaters.size() - 1;
                // [l , r]
                while (l + 1 < r) {
                    auto m = (l + r) >> 1;
                    if (heaters[m] >= house)
                        r = m;
                    else l = m;

                }
                ans = std::max(ans, std::min(house - heaters[l], heaters[r] - house));

            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




