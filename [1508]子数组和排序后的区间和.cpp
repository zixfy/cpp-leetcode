// 给你一个数组 nums ，它包含 n
// 个正整数。你需要计算所有非空连续子数组的和，并将它们按升序排序，得到一个新的包含
// n * (n + 1) / 2 个数 字的数组。
//
//  请你返回在新数组中下标为 left 到 right （下标从 1
//  开始）的所有数字和（包括左右端点）。由于答案可能很大，请你将它对 10^9 + 7
//  取模
// 后返回。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,3,4], n = 4, left = 1, right = 5
// 输出：13
// 解释：所有的子数组和为 1, 3, 6, 10, 2, 5, 9, 3, 7, 4
// 。将它们升序排序后，我们得到新的数组 [1, 2, 3, 3, 4, 5 , 6, 7, 9, 10]
// 。下标从 le = 1 到 ri = 5 的和为 1 + 2 + 3 + 3 + 4 = 13 。
//
//
//  示例 2：
//
//
// 输入：nums = [1,2,3,4], n = 4, left = 3, right = 4
// 输出：6
// 解释：给定数组与示例 1 一样，所以新数组为 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]
// 。下标从 le = 3 到 ri = 4 的和 为 3 + 3 = 6 。
//
//
//  示例 3：
//
//
// 输入：nums = [1,2,3,4], n = 4, left = 1, right = 10
// 输出：50
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10^3
//  nums.length == n
//  1 <= nums[i] <= 100
//  1 <= left <= right <= n * (n + 1) / 2
//
//
//  Related Topics 数组 双指针 二分查找 排序 👍 73 👎 0

#include <algorithm>
#include <array>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> ans;
    ans.reserve(n * (n + 1) / 2);
    auto sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        ans.emplace_back(sum);
      }
      sum = 0;
    }
    std::sort(ans.begin(), ans.end());
//    std::copy(ans.begin(), ans.end(), ostream_iterator<int>(cout , ", "));
    return std::accumulate(
        ans.begin() + left - 1, ans.begin() + right, 0,
        [](int acc, int cur) { return (acc + cur) % int(1e9 + 7); });
  }
};
// leetcode submit region end(Prohibit modification and deletion)
