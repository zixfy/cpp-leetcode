//请你设计一个迭代器类 CombinationIterator ，包括以下内容： 
//
// 
// CombinationIterator(string characters, int combinationLength) 一个构造函数，输入参数包括：用
//一个 有序且字符唯一 的字符串 characters（该字符串只包含小写英文字母）和一个数字 combinationLength 。 
// 函数 next() ，按 字典序 返回长度为 combinationLength 的下一个字母组合。 
// 函数 hasNext() ，只有存在长度为 combinationLength 的下一个字母组合时，才返回 true 
// 
//
// 
//
// 示例 1： 
//
// 
//输入:
//["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", 
//"hasNext"]
//[["abc", 2], [], [], [], [], [], []]
//输出：
//[null, "ab", true, "ac", true, "bc", false]
//解释：
//CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 
//iterator
//iterator.next(); // 返回 "ab"
//iterator.hasNext(); // 返回 true
//iterator.next(); // 返回 "ac"
//iterator.hasNext(); // 返回 true
//iterator.next(); // 返回 "bc"
//iterator.hasNext(); // 返回 false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= combinationLength <= characters.length <= 15 
// characters 中每个字符都 不同 
// 每组测试数据最多对 next 和 hasNext 调用 10⁴次 
// 题目保证每次调用函数 next 时都存在下一个字母组合。 
// 
//
// Related Topics 设计 字符串 回溯 迭代器 👍 67 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {

    }
    
    string next() {

    }
    
    bool hasNext() {

    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//leetcode submit region end(Prohibit modification and deletion)




