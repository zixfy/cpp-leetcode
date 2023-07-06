//给定一个可包含重复数字的整数集合 nums ，按任意顺序 返回它所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// 
//
// 
// 注意：本题与主站 47 题相同： https://leetcode-cn.com/problems/permutations-ii/ 
//
// Related Topics 数组 回溯 👍 48 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/3/14.
//
#include <bits/stdc++.h>
using namespace std;
template<typename T>
using matrix = vector<vector<T>>;
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    const int n = nums.size();
    vector<int> stk;
    vector<char> vis(n, false);
    vector<vector<int>> ans;
    int _{1};
    for (int i = 2; i <= n; ++i)
      _ *= i;
    ans.reserve(_);
    sort(nums.begin(), nums.end());

    function<void(int)> dfs = [&] (int dep) {
      if (dep == n)
        ans.emplace_back(stk);
      int las = 42;
      for (int i = 0; i < n; ++i) {
        if (vis[i] || las == nums[i])
          continue;
        vis[i] = true;
        stk.emplace_back(nums[i]);
        dfs(dep + 1);
        stk.pop_back();
        vis[i] = false;
        las = nums[i];
      }
    };
    dfs(0);
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
