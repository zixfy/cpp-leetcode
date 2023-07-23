// 整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
//
//  示例1:
//
//
//  输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
//  输出：2
//
//
//  示例2:
//
//
//  输入：A = 1，B = 2
//  输出：2
//
//
//  提示:
//
//
//  A，B范围在[-2147483648, 2147483647]之间
//
//
//  Related Topics 位运算 👍 53 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int convertInteger(int A, int B) {
    using u32 = uint32_t;
     auto r = u32(A) ^ u32(B);
    int ans = 0;
    while (r)
      ++ans, r -= (r & -r);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
