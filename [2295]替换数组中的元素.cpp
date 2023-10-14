//给你一个下标从 0 开始的数组 nums ，它包含 n 个 互不相同 的正整数。请你对这个数组执行 m 个操作，在第 i 个操作中，你需要将数字 
//operations[i][0] 替换成 operations[i][1] 。 
//
// 题目保证在第 i 个操作中： 
//
// 
// operations[i][0] 在 nums 中存在。 
// operations[i][1] 在 nums 中不存在。 
// 
//
// 请你返回执行完所有操作后的数组。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
//输出：[3,2,7,1]
//解释：我们对 nums 执行以下操作：
//- 将数字 1 替换为 3 。nums 变为 [3,2,4,6] 。
//- 将数字 4 替换为 7 。nums 变为 [3,2,7,6] 。
//- 将数字 6 替换为 1 。nums 变为 [3,2,7,1] 。
//返回最终数组 [3,2,7,1] 。
// 
//
// 示例 2： 
//
// 输入：nums = [1,2], operations = [[1,3],[2,1],[3,2]]
//输出：[2,1]
//解释：我们对 nums 执行以下操作：
//- 将数字 1 替换为 3 。nums 变为 [3,2] 。
//- 将数字 2 替换为 1 。nums 变为 [3,1] 。
//- 将数字 3 替换为 2 。nums 变为 [2,1] 。
//返回最终数组 [2,1] 。
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// m == operations.length 
// 1 <= n, m <= 10⁵ 
// nums 中所有数字 互不相同 。 
// operations[i].length == 2 
// 1 <= nums[i], operations[i][0], operations[i][1] <= 10⁶ 
// 在执行第 i 个操作时，operations[i][0] 在 nums 中存在。 
// 在执行第 i 个操作时，operations[i][1] 在 nums 中不存在。 
// 
//
// Related Topics 数组 哈希表 模拟 👍 22 👎 0


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
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




