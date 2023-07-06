//给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。 
//
// 注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// 示例 2: 
//
// 
//输入: strs = [""]
//输出: [[""]]
// 
//
// 示例 3: 
//
// 
//输入: strs = ["a"]
//输出: [["a"]] 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] 仅包含小写字母 
// 
//
// 
//
// 
// 注意：本题与主站 49 题相同： https://leetcode-cn.com/problems/group-anagrams/ 
//
// Related Topics 数组 哈希表 字符串 排序 👍 53 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/2/26.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> str2idx;
    vector<int> ans_idx(strs.size());
    int cnt = 0;
    int idx = 0;
    for (const string& s : strs) {
      vector<char> cs(s.begin(), s.end());
      sort(cs.begin(), cs.end());
      string stds(cs.begin(), cs.end());
      cout << stds << endl;
      if (!str2idx.count(stds)) {
        str2idx[stds] = cnt++;
      }
      ans_idx[idx++] = str2idx[stds];
    }
    vector<vector<string>> ans(cnt);
    for (size_t i = 0; i < strs.size(); i++)
      ans[ans_idx[i]].push_back(strs[i]);
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
