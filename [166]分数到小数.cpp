// 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以
// 字符串形式返回小数 。
//
//  如果小数部分为循环小数，则将循环的部分括在括号内。
//
//  如果存在多个答案，只需返回 任意一个 。
//
//  对于所有给定的输入，保证 答案字符串的长度小于 10⁴ 。
//
//
//
//  示例 1：
//
//
// 输入：numerator = 1, denominator = 2
// 输出："0.5"
//
//
//  示例 2：
//
//
// 输入：numerator = 2, denominator = 1
// 输出："2"
//
//
//  示例 3：
//
//
// 输入：numerator = 4, denominator = 333
// 输出："0.(012)"
//
//
//
//
//  提示：
//
//
//  -2³¹ <= numerator, denominator <= 2³¹ - 1
//  denominator != 0
//
//
//  Related Topics 哈希表 数学 字符串 👍 475 👎 0

#include <algorithm>
#include <array>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    using i64 = std::int64_t;
    map<i64, int> digit_by_index;
    string ans;
    bool neg = (numerator < 0) ^ (denominator < 0);
    i64 num = numerator;
    num = abs(num);
    denominator = abs(denominator);
    auto quo = num / denominator;
    auto rem = num % denominator;
    if (neg)
      ans += '-';
    ans += to_string(quo);
    if (rem == 0)
      return ans;
    ans.push_back('.');
      num = rem * 10;
    while (true) {
      if (digit_by_index.contains(num)) {
        ans.insert(ans.begin() + digit_by_index[num], '(');
        ans.push_back(')');
        break;
      }
      digit_by_index[num] = ans.size();
      ans += char(num / denominator + '0');
      num = num % denominator * 10;
    }
    if (ans.substr(ans.size() - 3, 3) == "(0)")
      ans.resize(ans.size() - 3);

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
