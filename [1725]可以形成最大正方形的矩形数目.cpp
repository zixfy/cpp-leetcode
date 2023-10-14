//给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。 
//
// 如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。例如，矩形 [4,6] 可以切成边长最大为 
//4 的正方形。 
//
// 设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。 
//
// 请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。 
//
// 
//
// 示例 1： 
//
// 
//输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
//输出：3
//解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
//最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
// 
//
// 示例 2： 
//
// 
//输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= rectangles.length <= 1000 
// rectangles[i].length == 2 
// 1 <= li, wi <= 10⁹ 
// li != wi 
// 
//
// Related Topics 数组 👍 65 👎 0


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
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        auto maxi = 0;
        auto ans  =0;
        for (auto & rect : rectangles) {
            auto mini = std::min(rect[0], rect[1]);
            if (mini > maxi)
                (maxi = mini), (ans = 1);
            else if (mini == maxi)
                ++ans;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




