//给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "owoztneoer"
//输出："012"
// 
//
// 示例 2： 
//
// 
//输入：s = "fviefuro"
//输出："45"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁵ 
// s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一 
// s 保证是一个符合题目要求的字符串 
// 
//
// Related Topics 哈希表 数学 字符串 👍 198 👎 0


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
    string originalDigits(string s) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




