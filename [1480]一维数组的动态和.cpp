// 给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] =
// sum(nums[0]…nums[i]) 。
//
//  请返回 nums 的动态和。
//
//
//
//  示例 1：
//
//  输入：nums = [1,2,3,4]
// 输出：[1,3,6,10]
// 解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
//
//  示例 2：
//
//  输入：nums = [1,1,1,1,1]
// 输出：[1,2,3,4,5]
// 解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
//
//  示例 3：
//
//  输入：nums = [3,1,2,10,1]
// 输出：[3,4,6,16,17]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 1000
//  -10^6 <= nums[i] <= 10^6
//
//
//  Related Topics 数组 前缀和 👍 438 👎 0

#include <algorithm>
#include <array>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
      *iter += *prev(iter);
    }
    return nums;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
