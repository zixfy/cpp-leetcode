//给定一个字符串 s ，请将 s 分割成一些子串，使每个子串都是 回文串 ，返回 s 所有可能的分割方案。 
//
// 
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "google"
//输出：[["g","o","o","g","l","e"],["g","oo","g","l","e"],["goog","l","e"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出：[["a"]] 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// 
//
// 
// 注意：本题与主站 131 题相同： https://leetcode-cn.com/problems/palindrome-partitioning/ 
//
// Related Topics 深度优先搜索 广度优先搜索 图 哈希表 👍 56 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)
