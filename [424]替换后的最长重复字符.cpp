//给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。 
//
// 在执行上述操作后，返回包含相同字母的最长子字符串的长度。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ABAB", k = 2
//输出：4
//解释：用两个'A'替换为两个'B',反之亦然。
// 
//
// 示例 2： 
//
// 
//输入：s = "AABABBA", k = 1
//输出：4
//解释：
//将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
//子串 "BBBB" 有最长重复字母, 答案为 4。
//可能存在其他的方法来得到同样的结果。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁵ 
// s 仅由大写英文字母组成 
// 0 <= k <= s.length 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 796 👎 0


#include <bits/stdc++.h>
using namespace std;

auto recursive_lambda = [](auto &&lam) {
      return [lam_impl = lam](auto &&...args) {
        return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
      };
    };

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int characterReplacement(string s, int k) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




