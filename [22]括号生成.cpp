// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
// 有效的 括号组合。
//
//
//
//  示例 1：
//
//
// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
//
//
//  示例 2：
//
//
// 输入：n = 1
// 输出：["()"]
//
//
//
//
//  提示：
//
//
//  1 <= n <= 8
//
//
//  Related Topics 字符串 动态规划 回溯 👍 3208 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector ans(n + 1, vector<string>());
    ans[0].emplace_back("");
    //    cout << ans<< endl;
    function<vector<string> &(int)> dfs = [&](int cur) -> vector<string> & {
      auto &r = ans[cur];
      if (!r.empty())
        return r;
      unordered_set<string> tmp;
      for (const auto &s : dfs(cur - 1))
        tmp.emplace("(" + s + ")");
      for (int i = 1; i < cur; ++i) {
        for (const auto &s1 : dfs(i))
          for (const auto &s2 : dfs(cur - i))
            tmp.emplace(s1 + s2);
      }
      r = vector<string>(
          std::vector<std::string>(std::make_move_iterator(tmp.begin()),
                                   std::make_move_iterator(tmp.end())));
      //      cout << r<< endl;
      return r;
    };
    return dfs(n);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
