// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s
// 所有可能的分割方案。
//
//  回文串 是正着读和反着读都一样的字符串。
//
//
//
//  示例 1：
//
//
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
//
//
//  示例 2：
//
//
// 输入：s = "a"
// 输出：[["a"]]
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 16
//  s 仅由小写英文字母组成
//
//
//  Related Topics 字符串 动态规划 回溯 👍 1496 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  auto partition(string s) {
    vector<vector<string>> ans;
    auto n = s.length();
    vector<vector<int>> rdxs(n);
    for (int i = 0; i < n; ++i)
      for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; --l, ++r)
        rdxs[l].push_back(r);
    for (int i = 0; i < n - 1; ++i)
      for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r)
        rdxs[l].push_back(r);
    vector<string> stk;
    function<void(int)> dfs = [&](int i) {
      if (i == n) {
        ans.emplace_back(stk);
        return;
      }
     for (auto r: rdxs[i]) {
        stk.emplace_back(s.begin() + i, s.begin() + r + 1);
        dfs(r + 1);
        stk.pop_back();
     }
    };
    dfs(0);
//    cout << rdxs << endl;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
