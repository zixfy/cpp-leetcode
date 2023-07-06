// 给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为
// 1。
//
//
//
//  上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6
//  个单位的水（蓝色部分表示水）。 感谢
// Marcos 贡献此图。
//
//  示例:
//
//  输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6
//
//  Related Topics 栈 数组 双指针 动态规划 单调栈 👍 283 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  auto trap(vector<int> &height) {
    stack<pair<int, int>> stk;
    // hei, index
    int ans{}, idx{};
    for (const auto &h : height) {
      while (!stk.empty() && h >= stk.top().first) {
        int bot{stk.top().first};
        stk.pop();
        if (stk.empty())
          break ;
        ans += (idx - stk.top().second - 1) * (min(h, stk.top().first) - bot);
      }
      stk.emplace(h, idx);
      ++idx;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
