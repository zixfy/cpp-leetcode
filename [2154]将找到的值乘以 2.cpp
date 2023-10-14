//给你一个整数数组 nums ，另给你一个整数 original ，这是需要在 nums 中搜索的第一个数字。 
//
// 接下来，你需要按下述步骤操作： 
//
// 
// 如果在 nums 中找到 original ，将 original 乘以 2 ，得到新 original（即，令 original = 2 * 
//original）。 
// 否则，停止这一过程。 
// 只要能在数组中找到新 original ，就对新 original 继续 重复 这一过程。 
// 
//
// 返回 original 的 最终 值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,3,6,1,12], original = 3
//输出：24
//解释： 
//- 3 能在 nums 中找到。3 * 2 = 6 。
//- 6 能在 nums 中找到。6 * 2 = 12 。
//- 12 能在 nums 中找到。12 * 2 = 24 。
//- 24 不能在 nums 中找到。因此，返回 24 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,7,9], original = 4
//输出：4
//解释：
//- 4 不能在 nums 中找到。因此，返回 4 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 1 <= nums[i], original <= 1000 
// 
//
// Related Topics 数组 哈希表 排序 模拟 👍 20 👎 0


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
using namespace  std;;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        std::sort(nums.begin(), nums.end());
        while (true) {
            auto iter = std::lower_bound(nums.begin(), nums.end(), original);
            if (iter != nums.end() && (*iter == original))
                original *= 2;
            else break;
        }
        return original;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




