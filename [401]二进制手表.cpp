// 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表
// 分钟（0-59）。每个 LED 代表一个 0 或 1，最低位在右侧。
//
//
//
//  例如，下面的二进制手表读取 "3:25" 。
//
//
//
//
//  （图源：WikiMedia - Binary clock samui moon.jpg
//  ，许可协议：Attribution-ShareAlike 3.0
// Unported (CC BY-SA 3.0) ）
//
//  给你一个整数 turnedOn ，表示当前亮着的 LED
//  的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
//
//  小时不会以零开头：
//
//
//  例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
//
//
//  分钟必须由两位数组成，可能会以零开头：
//
//
//  例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。
//
//
//
//
//  示例 1：
//
//
// 输入：turnedOn = 1
// 输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
//
//
//  示例 2：
//
//
// 输入：turnedOn = 9
// 输出：[]
//
//
//
//
//  提示：
//
//
//  0 <= turnedOn <= 10
//
//
//  Related Topics 位运算 回溯 👍 416 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
string fmt(int h, int m) {
  string ret;
  if (h / 10)
    ret += {static_cast<char>('0' + h / 10)};
  return ret + string{static_cast<char>('0' + h % 10), ':',
                static_cast<char>('0' + m / 10),
                static_cast<char>('0' + m % 10)};
}
class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    using u16 = uint16_t;
    u16 sn = 1 << 10;
    auto dcnt = [](u16 x) {
      int res = 0;
      while (x) {
        res++;
        x -= (x & -x);
      }
      return res;
    };
    vector<string> ans;
    for (u16 s = 0; s < sn; ++s)
      if (dcnt(s) == turnedOn) {
        auto h = s >> 6;
        auto m = s & ((1 << 6) - 1);
        if (h < 12 && m < 60)
          ans.emplace_back(fmt(h, m));
      }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
