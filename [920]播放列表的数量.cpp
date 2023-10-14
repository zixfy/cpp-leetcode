//你的音乐播放器里有 n 首不同的歌，在旅途中，你计划听 goal 首歌（不一定不同，即，允许歌曲重复）。你将会按如下规则创建播放列表： 
//
// 
// 每首歌 至少播放一次 。 
// 一首歌只有在其他 k 首歌播放完之后才能再次播放。 
// 
//
// 给你 n、goal 和 k ，返回可以满足要求的播放列表的数量。由于答案可能非常大，请返回对 10⁹ + 7 取余 的结果。 
//
// 示例 1： 
//
// 
//输入：n = 3, goal = 3, k = 1
//输出：6
//解释：有 6 种可能的播放列表。[1, 2, 3]，[1, 3, 2]，[2, 1, 3]，[2, 3, 1]，[3, 1, 2]，[3, 2, 1] 。
// 
//
// 示例 2： 
//
// 
//输入：n = 2, goal = 3, k = 0
//输出：6
//解释：有 6 种可能的播放列表。[1, 1, 2]，[1, 2, 1]，[2, 1, 1]，[2, 2, 1]，[2, 1, 2]，[1, 2, 2] 。
// 
//
// 示例 3： 
//
// 
//输入：n = 2, goal = 3, k = 1
//输出：2
//解释：有 2 种可能的播放列表。[1, 2, 1]，[2, 1, 2] 。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= k < n <= goal <= 100 
// 
//
// Related Topics 数学 动态规划 组合数学 👍 119 👎 0


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
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




