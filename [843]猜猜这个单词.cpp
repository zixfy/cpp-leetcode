//给你一个由 不同 字符串组成的单词列表 words ，其中 words[i] 长度均为 6 。words 中的一个单词将被选作秘密单词 secret 。 
//
// 另给你一个辅助对象 Master ，你可以调用 Master.guess(word) 来猜单词，其中参数 word 长度为 6 且必须是 words 中的
//字符串。 
//
// Master.guess(word) 将会返回如下结果： 
//
// 
// 如果 word 不是 words 中的字符串，返回 -1 ，或者 
// 一个整数，表示你所猜测的单词 word 与 秘密单词 secret 的准确匹配（值和位置同时匹配）的数目。 
// 
//
// 每组测试用例都会包含一个参数 allowedGuesses ，其中 allowedGuesses 是你可以调用 Master.guess(word) 的最
//大次数。 
//
// 对于每组测试用例，在不超过允许猜测的次数的前提下，你应该调用 Master.guess 来猜出秘密单词。最终，你将会得到以下结果： 
//
// 
// 如果你调用 Master.guess 的次数大于 allowedGuesses 所限定的次数或者你没有用 Master.guess 猜到秘密单词，则得到 
//"Either you took too many guesses, or you did not find the secret word." 。 
// 如果你调用 Master.guess 猜到秘密单词，且调用 Master.guess 的次数小于或等于 allowedGuesses ，则得到 "You 
//guessed the secret word correctly." 。 
// 
//
// 生成的测试用例保证你可以利用某种合理的策略（而不是暴力）猜到秘密单词。 
//
// 示例 1： 
//
// 
//输入：secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], 
//allowedGuesses = 10
//输出：You guessed the secret word correctly.
//解释：
//master.guess("aaaaaa") 返回 -1 ，因为 "aaaaaa" 不在 words 中。
//master.guess("acckzz") 返回 6 ，因为 "acckzz" 是秘密单词 secret ，共有 6 个字母匹配。
//master.guess("ccbazz") 返回 3 ，因为 "ccbazz" 共有 3 个字母匹配。
//master.guess("eiowzz") 返回 2 ，因为 "eiowzz" 共有 2 个字母匹配。
//master.guess("abcczz") 返回 4 ，因为 "abcczz" 共有 4 个字母匹配。
//一共调用 5 次 master.guess ，其中一个为秘密单词，所以通过测试用例。
// 
//
// 示例 2： 
//
// 
//输入：secret = "hamada", words = ["hamada","khaled"], allowedGuesses = 10
//输出：You guessed the secret word correctly.
//解释：共有 2 个单词，且其中一个为秘密单词，可以通过测试用例。 
//
// 
//
// 提示： 
//
// 
// 1 <= words.length <= 100 
// words[i].length == 6 
// words[i] 仅由小写英文字母组成 
// words 中所有字符串 互不相同 
// secret 存在于 words 中 
// 10 <= allowedGuesses <= 30 
// 
//
// Related Topics 数组 数学 字符串 博弈 交互 👍 129 👎 0


#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




