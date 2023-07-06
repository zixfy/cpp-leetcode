// 给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0
// 。你需要执行以下操作直到矩阵变为空：
//
//
//  矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
//  在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
//
//
//  请你返回最后的 分数 。
//
//
//
//  示例 1：
//
//
// 输入：nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
// 输出：15
// 解释：第一步操作中，我们删除 7 ，6 ，6 和 3 ，将分数增加 7
// 。下一步操作中，删除 2 ，4 ，5 和 2 ，将分数增加 5 。最后删除 1 ，2
//  ，3 和 1 ，将分数增加 3 。所以总得分为 7 + 5 + 3 = 15 。
//
//
//  示例 2：
//
//
// 输入：nums = [[1]]
// 输出：1
// 解释：我们删除 1 并将分数增加 1 ，所以返回 1 。
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 300
//  1 <= nums[i].length <= 500
//  0 <= nums[i][j] <= 10³
//
//
//  Related Topics 数组 矩阵 排序 模拟 堆（优先队列） 👍 6 👎 0

#include <bits/stdc++.h>
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
  int matrixSum(vector<vector<int>> &nums) {
    auto ans = 0;
    for (auto &num : nums)
      std::sort(num.begin(), num.end());
    const auto m = nums.size(), n = nums[0].size();
    for (int j = 0; j < n; ++j) {
      auto maxx = nums[0][j];
      for (int i = 1; i < m; ++i)
        maxx = max(maxx, nums[i][j]);
      ans += maxx;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
