// 一个下标从 0 开始的数组的 交替和 定义为 偶数 下标处元素之 和 减去 奇数
// 下标处元素之 和 。
//
//
//  比方说，数组 [4,2,5,3] 的交替和为 (4 + 5) - (2 + 3) = 4 。
//
//
//  给你一个数组 nums ，请你返回 nums 中任意子序列的 最大交替和 （子序列的下标
//  重新 从 0 开始编号）。
//
//
//
//
//  一个数组的 子序列
//  是从原数组中删除一些元素后（也可能一个也不删除）剩余元素不改变顺序组成的数组。比方说，[2,7,4]
//  是 [4,2,3,7,2,1,4
//] 的一个子序列（加粗元素），但是 [2,4,2] 不是。
//
//
//
//  示例 1：
//
//  输入：nums = [4,2,5,3]
// 输出：7
// 解释：最优子序列为 [4,2,5] ，交替和为 (4 + 5) - 2 = 7 。
//
//
//  示例 2：
//
//  输入：nums = [5,6,7,8]
// 输出：8
// 解释：最优子序列为 [8] ，交替和为 8 。
//
//
//  示例 3：
//
//  输入：nums = [6,2,1,2,4,5]
// 输出：10
// 解释：最优子序列为 [6,1,5] ，交替和为 (6 + 5) - 1 = 10 。
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  1 <= nums[i] <= 10⁵
//
//
//  Related Topics 数组 动态规划 👍 154 👎 0

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
  long long maxAlternatingSum(vector<int> &nums) {
    vector<int> stk;
    for (auto num : nums) {
      auto len = stk.size();
//      std::copy(stk.begin(), stk.end(), ostream_iterator<int>(cout, ", "));
//      cout << endl;
      if (len == 0) {
        stk.emplace_back(num);
        continue;
      }
      if (len & 1) {
        if (num < stk.back())
          stk.emplace_back(num);
        else if (num > stk.back())
          stk.back() = num;
      } else {
        if (num < stk.back())
          stk.back() = num;
        else if (num > stk.back())
          stk.emplace_back(num);
      }
    }
    long long ans = 0;
    int i = 0;
    if (!(stk.size() & 1))
      stk.pop_back();
    for (auto num : stk) {
//      cout << num << endl;
      if (i & 1)
        ans -= num;
      else ans += num;
      i++;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
