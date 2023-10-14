//给你一个整数数组 nums 和一个整数 k 。 
//
// 将数组拆分成一些非空子数组。拆分的 代价 是每个子数组中的 重要性 之和。 
//
// 令 trimmed(subarray) 作为子数组的一个特征，其中所有仅出现一次的数字将会被移除。 
//
// 
// 例如，trimmed([3,1,2,4,3,4]) = [3,4,3,4] 。 
// 
//
// 子数组的 重要性 定义为 k + trimmed(subarray).length 。 
//
// 
// 例如，如果一个子数组是 [1,2,3,3,3,4,4] ，trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4] 。这个子数组的重要
//性就是 k + 5 。 
// 
//
// 找出并返回拆分 nums 的所有可行方案中的最小代价。 
//
// 子数组 是数组的一个连续 非空 元素序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,1,2,1,3,3], k = 2
//输出：8
//解释：将 nums 拆分成两个子数组：[1,2], [1,2,1,3,3]
//[1,2] 的重要性是 2 + (0) = 2 。
//[1,2,1,3,3] 的重要性是 2 + (2 + 2) = 6 。
//拆分的代价是 2 + 6 = 8 ，可以证明这是所有可行的拆分方案中的最小代价。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,1,2,1], k = 2
//输出：6
//解释：将 nums 拆分成两个子数组：[1,2], [1,2,1] 。
//[1,2] 的重要性是 2 + (0) = 2 。
//[1,2,1] 的重要性是 2 + (2) = 4 。
//拆分的代价是 2 + 4 = 6 ，可以证明这是所有可行的拆分方案中的最小代价。
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,2,1,2,1], k = 5
//输出：10
//解释：将 nums 拆分成一个子数组：[1,2,1,2,1].
//[1,2,1,2,1] 的重要性是 5 + (3 + 2) = 10 。
//拆分的代价是 10 ，可以证明这是所有可行的拆分方案中的最小代价。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] < nums.length 
// 1 <= k <= 10⁹ 
// 
//
// 
//
// Related Topics 数组 哈希表 动态规划 计数 👍 25 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <iterator>

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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




