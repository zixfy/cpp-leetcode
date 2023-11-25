// 给你一个整数 n 。
//
//  如果一个字符串 s 只包含小写英文字母，且 将 s 的字符重新排列后，新字符串包含
//  子字符串 "leet" ，那么我们称字符串 s 是一个 好 字符串。
//
//
//  比方说：
//
//
//  字符串 "lteer" 是好字符串，因为重新排列后可以得到 "leetr" 。
//  "letl" 不是好字符串，因为无法重新排列并得到子字符串 "leet" 。
//
//
//  请你返回长度为 n 的好字符串 总 数目。
//
//  由于答案可能很大，将答案对 10⁹ + 7 取余 后返回。
//
//  子字符串 是一个字符串中一段连续的字符序列。
//
//
//
//
//
//  示例 1：
//
//
// 输入：n = 4
// 输出：12
// 解释：总共有 12 个字符串重新排列后包含子字符串 "leet" ："eelt" ，"eetl"
// ，"elet" ，"elte" ，"etel" ， "etle" ，"leet" ，"lete" ，"ltee" ，"teel"
// ，"tele" 和 "tlee" 。
//
//
//  示例 2：
//
//
// 输入：n = 10
// 输出：83943898
// 解释：长度为 10 的字符串重新排列后包含子字符串 "leet" 的方案数为 526083947580
// 。所以答案为 526083947580 % (10⁹
//  + 7) = 83943898 。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 10⁵
//
//
//  Related Topics 数学 动态规划 组合数学 👍 4 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include "cstdint"
class Solution {
public:
  using u32 = std::uint32_t;
  using u64 = std::uint64_t;
  constexpr static u32 MOD = 1e9 + 7;

  int stringCount(int n) {
  }
};
// leetcode submit region end(Prohibit modification and deletion)
