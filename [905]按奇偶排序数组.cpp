// 给你一个整数数组 nums，将 nums
// 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。
//
//  返回满足此条件的 任一数组 作为答案。
//
//
//
//  示例 1：
//
//
// 输入：nums = [3,1,2,4]
// 输出：[2,4,3,1]
// 解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
//
//
//  示例 2：
//
//
// 输入：nums = [0]
// 输出：[0]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 5000
//  0 <= nums[i] <= 5000
//
//
//  Related Topics 数组 双指针 排序 👍 371 👎 0

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
  vector<int> sortArrayByParity(vector<int> &nums) {

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
      if ((a ^ b) & 1)
        return (a & 1) == 0;
      return a < b;
    });
    return nums;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
