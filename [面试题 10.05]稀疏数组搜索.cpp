// 稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
//
//  示例1:
//
//   输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "",
//   ""],
//  s = "ta"
//  输出：-1
//  说明: 不存在返回-1。
//
//
//  示例2:
//
//   输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "",
//   ""],
// s = "ball"
//  输出：4
//
//
//  提示:
//
//
//  words的长度在[1, 1000000]之间
//
//
//  Related Topics 数组 字符串 二分查找 👍 84 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  int findString(vector<string> &words, string s) {
    auto const n = words.size();
    int l = -1, r = n + 1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
