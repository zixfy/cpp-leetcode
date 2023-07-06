// 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y
// 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
//
//
//  例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts"
//  也是相似的，但是 "star" 不与
//"tars"，"rats"，或 "arts" 相似。
//
//  总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和
//  {"star"}。注意，"tars" 和 "arts" 是在同
// 一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
//
//  给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个
//  字母异位词 。请问 strs 中有多少个相似字符串组？
//
//  字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。
//
//
//
//  示例 1：
//
//
// 输入：strs = ["tars","rats","arts","star"]
// 输出：2
//
//
//  示例 2：
//
//
// 输入：strs = ["omv","ovm"]
// 输出：1
//
//
//
//
//  提示：
//
//
//  1 <= strs.length <= 300
//  1 <= strs[i].length <= 300
//  strs[i] 只包含小写字母。
//  strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。
//
//
//
//
//
//  注意：本题与主站 839
//  题相同：https://leetcode-cn.com/problems/similar-string-groups/
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 数组 字符串 👍 26 👎 0

#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)

class Solution {
private:
  inline bool judge(const string &a, const string &b) {
    if (a.length() != b.length())
      return false;
    const auto &n{a.length()};
    array<size_t, 2> false_idx;
    int false_cnt{};
    for (size_t i{}; i < n; ++i) {
      if (a[i] != b[i]) {
        if (false_cnt > 1)
          return false;
        false_idx[false_cnt++] = i;
      }
    }
    return (false_cnt == 0 || false_cnt == 2 &&
                                  a[false_idx[0]] == b[false_idx[1]] &&
                                  a[false_idx[1]] == b[false_idx[0]]);
  }

public:
  int numSimilarGroups(vector<string> &strs);
};

int Solution::numSimilarGroups(vector<std::string> &strs) {
  const auto &n{strs.size()};
  vector<int> pars(n);
  int ans{static_cast<int>(n)};
  generate(pars.begin(), pars.end(), [n = 0]() mutable { return n++; });
  function<int(int)> find_par = [&] (int cur) {
    if (cur != pars[cur])
      pars[cur] = find_par(pars[cur]);
    return pars[cur];
  };
  for (size_t i{}; i < n; ++i)
    for (size_t j{i + 1}; j < n; ++j) {
      if (judge(strs[i], strs[j]) && find_par(i) != find_par(j)) {
        --ans;
        pars[find_par(j)] = find_par(i);
      }
    }
  return ans;
}
// leetcode submit region end(Prohibit modification and deletion)
