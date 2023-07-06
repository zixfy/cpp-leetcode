// 给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
//
//
//  每个节点都有 0 个或是 2 个子节点。
//  数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。
//  每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
//
//
//  在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个
//  32 位整数。
//
//  如果一个节点有 0 个子节点，那么该节点为叶节点。
//
//
//
//  示例 1：
//
//
// 输入：arr = [6,2,4]
// 输出：32
// 解释：有两种可能的树，第一种的非叶节点的总和为 36 ，第二种非叶节点的总和为 32
// 。
//
//
//  示例 2：
//
//
// 输入：arr = [4,11]
// 输出：44
//
//
//
//
//  提示：
//
//
//  2 <= arr.length <= 40
//  1 <= arr[i] <= 15
//  答案保证是一个 32 位带符号整数，即小于 2³¹ 。
//
//
//  Related Topics 栈 贪心 数组 动态规划 单调栈 👍 262 👎 0
#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
struct PairHash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &p) const {
    // Combine the hashes of the pair's elements
    return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
  }
};
class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    using xy = pair<int, int>;
    unordered_map<xy, xy, PairHash> mem;
    function<xy(const xy &)> f = [&](const xy &lr) -> xy {
      auto [l, r] = lr;
      if (!mem.count(lr))
        if (l == r)
          mem[lr] = {0, arr[l]};
        else if (l + 1 == r)
          mem[lr] = {arr[l] * arr[r], max(arr[l], arr[r])};
        else {
          int dp_min = numeric_limits<int>::max();
          int v_min = 0;
          for (int k = l; k < r; ++k) {
            auto [dp1, max1] = f({l, k});
            auto [dp2, max2] = f({k + 1, r});
            if (auto tmp = dp1 + dp2 + max1 * max2; dp_min > tmp)
              dp_min = tmp, v_min = max(max1, max2);
          }
          mem[lr] = {dp_min, v_min};
        }
      return mem[lr];
    };
    return f({0, arr.size() - 1}).first;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
