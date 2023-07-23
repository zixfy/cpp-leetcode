// 单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices
// 组成，且满足：
//
//
//  words.length == indices.length
//  助记字符串 s 以 '#' 字符结尾
//  对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#'
//  字符结束（但不包括 '#'）的 子字符串 恰好与
// words[i] 相等
//
//
//  给定一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度
//  。
//
//
//
//  示例 1：
//
//
// 输入：words = ["time", "me", "bell"]
// 输出：10
// 解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
// words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#'
// 结束的子字符串，如加粗部分所示 "time#bell#" words[1] = "me" ，s 开始于
// indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
// words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#'
// 结束的子字符串，如加粗部分所示 "time#bell#"
//
//
//  示例 2：
//
//
// 输入：words = ["t"]
// 输出：2
// 解释：一组有效编码为 s = "t#" 和 indices = [0] 。
//
//
//
//
//  提示：
//
//
//  1 <= words.length <= 2000
//  1 <= words[i].length <= 7
//  words[i] 仅由小写字母组成
//
//
//
//
//
//  注意：本题与主站 820 题相同：
//  https://leetcode-cn.com/problems/short-encoding-of-words/
//
//  Related Topics 字典树 数组 哈希表 字符串 👍 41 👎 0

#include "bits/stdc++.h"
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
class Trie {
public:
  Trie() : nodes{}, cnt(0) { _add_empty_node(); };
  void add(string_view);
  int count_leaves_lengths();

private:
  vector<array<int, 26>> nodes;
  int cnt;
  size_t inline _add_empty_node() {
    auto ret = nodes.size();
    nodes.emplace_back();
    nodes.back().fill(-1);
    return ret;
  }
  pair<int, int> _count_leaf(int);
};
void Trie::add(std::string_view s) {
  int cur = 0;
  for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
    auto c = (*iter - 'a');
    if (nodes[cur][c] == -1)
      nodes[cur][c] = _add_empty_node();
    cur = nodes[cur][c];
  }
}
int Trie::count_leaves_lengths() {
  auto r = _count_leaf(0);
  return r.first + r.second;
}
pair<int, int> Trie::_count_leaf(int cur) {
  int leaves_cnt = 0, path_sum = 0;
  for (auto child : nodes[cur])
    if (child != -1) {
      auto [lc, ps] = _count_leaf(child);
      leaves_cnt += lc;
      path_sum += lc + ps;
    }
  if (leaves_cnt == 0)
    leaves_cnt = 1;
  return {leaves_cnt, path_sum};
}
class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    Trie t;
    for (const auto &w : words)
      t.add(w);
    return t.count_leaves_lengths();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
