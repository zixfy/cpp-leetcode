// 给你两个字符串 start 和 target ，长度均为 n 。每个字符串 仅 由字符 'L'、'R'
// 和 '_' 组成，其中：
//
//
//  字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位
//  时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位
// 时才能向 右 移动。
//  字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。
//
//
//  如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true
//  ；否则，返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：start = "_L__R__R_", target = "L______RR"
// 输出：true
// 解释：可以从字符串 start 获得 target ，需要进行下面的移动：
//- 将第一个片段向左移动一步，字符串现在变为 "L___R__R_" 。
//- 将最后一个片段向右移动一步，字符串现在变为 "L___R___R" 。
//- 将第二个片段向右移动三步，字符串现在变为 "L______RR" 。
// 可以从字符串 start 得到 target ，所以返回 true 。
//
//
//  示例 2：
//
//
// 输入：start = "R_L_", target = "__LR"
// 输出：false
// 解释：字符串 start 中的 'R' 片段可以向右移动一步得到 "_RL_" 。
// 但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target
// 。
//
//
//  示例 3：
//
//
// 输入：start = "_R", target = "R_"
// 输出：false
// 解释：字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target
// 。
//
//
//
//  提示：
//
//
//  n == start.length == target.length
//  1 <= n <= 10⁵
//  start 和 target 由字符 'L'、'R' 和 '_' 组成
//
//
//  Related Topics 双指针 字符串 👍 88 👎 0

#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using std::string;
class Solution {
public:
  bool canChange(string start, string target) {
    auto const n = start.size();
    int r_cnt = 0, l_cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (start[i] == 'R')
        ++r_cnt;
      if (target[i] == 'R') {
        if (--r_cnt < 0)
          return false;
      }
      if (target[i] == 'L' || start[i] == 'L') {
        if (r_cnt)
          return false;
      }
    }
    if (r_cnt)
      return false;
    for (int i = n - 1; i >= 0; --i) {
      if (start[i] == 'L')
        ++l_cnt;
      if (target[i] == 'L') {
        if (--l_cnt < 0)
          return false;
      }
      if (target[i] == 'R' || start[i] == 'R') {
        if (l_cnt)
          return false;
      }
    }
    if (l_cnt)
      return false;

    //std::cout << r_cnt << '\n' << l_cnt;

    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
