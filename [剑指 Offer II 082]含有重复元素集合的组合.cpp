//给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
//。 
//
// candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// 
//
// 
// 注意：本题与主站 40 题相同： https://leetcode-cn.com/problems/combination-sum-ii/ 
//
// Related Topics 数组 回溯 👍 51 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/4/17.
//
#include <bits/stdc++.h>
using namespace std;
struct item {
  int val;
  int cnt;
  item(int v, int c): val(v), cnt(c){};
};
ostream& operator<<(ostream& o, const item& item) {
  o << "val:" << item.val << " cnt:" << item.cnt;
  return o;
}
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
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end(), greater<>());
    const size_t n = candidates.size();
    assert(n > 0);
    vector<item> items;
    vector<vector<int>> ans;
    items.reserve(n);

    int las{candidates.front()}, cnt{};
    for (const auto& c: candidates)
      if (las == c)
        ++cnt;
      else
        items.emplace_back(las, cnt), cnt = 1, las = c;
    items.emplace_back(las, cnt);
    //        cout << items;

    const size_t m = items.size();
    vector<pair<int, int>> stk;
    function<void(int, int)> dfs = [&] (int cur, int t) {
      if (t == 0) {
        ans.emplace_back();
        auto &a = ans.back();
        for (const auto& p: stk)
          for (int j = 0; j < p.second; ++j)
            a.emplace_back(p.first);
        return;
      }
      for (size_t i = cur; i < m; ++i) {
        const int& v{items[i].val}, &c{items[i].cnt};
        for (int j = 1, sum = v; j <= c && sum <= t; ++j, sum += v) {
          stk.emplace_back(v, j);
          dfs(i + 1, t - sum);
          stk.pop_back();
        }
      }
    };
    dfs(0, target);
    return std::move(ans);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
