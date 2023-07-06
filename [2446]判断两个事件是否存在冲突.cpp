// 给你两个字符串数组 event1 和 event2
// ，表示发生在同一天的两个闭区间时间段事件，其中：
//
//
//  event1 = [startTime1, endTime1] 且
//  event2 = [startTime2, endTime2]
//
//
//  事件的时间为有效的 24 小时制且按 HH:MM 格式给出。
//
//  当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），则认为出现
//  冲突 。
//
//  如果两个事件之间存在冲突，返回 true ；否则，返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
// 输出：true
// 解释：两个事件在 2:00 出现交集。
//
//
//  示例 2：
//
//
// 输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
// 输出：true
// 解释：两个事件的交集从 01:20 开始，到 02:00 结束。
//
//
//  示例 3：
//
//
// 输入：event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
// 输出：false
// 解释：两个事件不存在交集。
//
//
//
//
//  提示：
//
//
//  evnet1.length == event2.length == 2.
//  event1[i].length == event2[i].length == 5
//  startTime1 <= endTime1
//  startTime2 <= endTime2
//  所有事件的时间都按照 HH:MM 格式给出
//
//
//  Related Topics 数组 字符串 👍 37 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
int _cmp(const string_view& t1, const string_view& t2) {
  return t1 == t2 ? 0 : (t1  < t2 ? -1 : 1);
}
int cmp(const string& t1, const string& t2) {
  auto h1 = string_view(t1.c_str(), 2), m1 = string_view(t1.c_str() + 3, 2);
  auto h2 = string_view(t2.c_str(), 2), m2 = string_view(t2.c_str() + 3, 2);
  int r = _cmp(h1, h2);
  if (r == 0)
    return _cmp(m1, m2);
  return r;
}
class Solution {
public:
  bool haveConflict(vector<string> &event1, vector<string> &event2) {
    if (cmp(event1[1], event2[0]) < 0 || cmp(event1[0], event2[1]) > 0)
      return false;
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
