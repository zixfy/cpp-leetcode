// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列
// 是一个按下述规格形成的序列
//  beginWord -> s1 -> s2 -> ... -> sk：
//
//
//  每一对相邻的单词只差一个字母。
//
//  对于 1 <= i <= k 时，每个
//  si 都在
//  wordList 中。注意， beginWord 不需要在
//  wordList 中。
//
//  sk == endWord
//
//
//  给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到
//  endWord 的 最短转换序列
// 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
//
//  示例 1：
//
//
// 输入：beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot", "log","cog"] 输出：5 解释：一个最短转换序列是 "hit"
// -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
//
//
//  示例 2：
//
//
// 输入：beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot", "log"] 输出：0 解释：endWord "cog"
// 不在字典中，所以无法进行转换。
//
//
//
//  提示：
//
//
//  1 <= beginWord.length <= 10
//  endWord.length == beginWord.length
//  1 <= wordList.length <= 5000
//  wordList[i].length == beginWord.length
//  beginWord、endWord 和 wordList[i] 由小写英文字母组成
//  beginWord != endWord
//  wordList 中的所有字符串 互不相同
//
//
//  Related Topics 广度优先搜索 哈希表 字符串 👍 1241 👎 0
#include "bits/stdc++.h"
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    wordList.emplace_back(beginWord);
    int s = wordList.size() - 1;
    const auto n = wordList.size();
    queue<int> q;
    q.emplace(s);
    int ans = 1;
    int layer_cnt = 1;
    unordered_set<int> vis{s};
    while (!q.empty()) {
      int new_layer_cnt = 0;
      for (int i = 0; i < layer_cnt; ++i) {
        int cur = q.front();
        if (endWord == wordList[cur])
          return ans;
        q.pop();
        for (int to = 0; to < n; ++to)
          if (!vis.count(to)) {
            int dif = 0;
            const string &s1 = wordList[cur];
            const string &s2 = wordList[to];
            for (int k = 0; k < s1.length(); ++k)
              if ((dif += s1[k] != s2[k]) > 1)
                break;
            if (dif == 1)
              ++new_layer_cnt, vis.insert(to), q.push(to);
          }
      }
      layer_cnt = new_layer_cnt;
      ans++;
    }
    return 0;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
