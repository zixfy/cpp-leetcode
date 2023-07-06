//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2: 
//
// 
//输入: n = 1, k = 1
//输出: [[1]] 
//
// 
//
// 提示: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// 
//
// 
// 注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/ 
//
// Related Topics 数组 回溯 👍 46 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/3/17.
//

#include <bits/stdc++.h>
using namespace std;
template<typename T>
using matrix = vector<vector<T>>;
template<typename T>
ostream& operator<<(ostream &o, const vector<T> &v){
  o << "[" ;
  for(auto i = v.begin(); i != v.end(); ++i){
    if (i != v.begin())
      o <<", ";
    o << (*i);
  }
  o << "]";
  return o;
}
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    matrix<int> ans;
    vector<int> tmp;
    function<void(int, int)> dfs = [&](int cur, int rem_k) {
      if (!rem_k)
        ans.emplace_back(tmp);
      else for (int i = cur; i <= n - rem_k + 1; ++i) {
          tmp.emplace_back(i);
          dfs(i + 1, rem_k - 1);
          tmp.pop_back();
        }
    };
    dfs(1, k);
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
