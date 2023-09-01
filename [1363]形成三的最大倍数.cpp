// 给你一个整数数组 digits，你可以通过按 任意顺序 连接其中某些数字来形成 3
// 的倍数，请你返回所能得到的最大的 3 的倍数。
//
//  由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。如果无法得到答案，请返回一个空字符串。返回的结果不应包含不必要的前导零。
//
//
//
//  示例 1：
//
//
// 输入：digits = [8,1,9]
// 输出："981"
//
//
//  示例 2：
//
//
// 输入：digits = [8,6,7,1,0]
// 输出："8760"
//
//
//  示例 3：
//
//
// 输入：digits = [1]
// 输出：""
//
//
//  示例 4：
//
//
// 输入：digits = [0,0,0,0,0,0]
// 输出："0"
//
//
//
//
//  提示：
//
//
//  1 <= digits.length <= 10^4
//  0 <= digits[i] <= 9
//
//
//  Related Topics 贪心 数组 动态规划 👍 81 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  string largestMultipleOfThree(vector<int> &digits) {
    std::sort(digits.begin(), digits.end(), greater<>());

  }
};
// leetcode submit region end(Prohibit modification and deletion)
