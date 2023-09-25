//给你两个字符串 s1 和 s2 ，两个字符串长度都为 n ，且只包含 小写 英文字母。 
//
// 你可以对两个字符串中的 任意一个 执行以下操作 任意 次： 
//
// 
// 选择两个下标 i 和 j ，满足 i < j 且 j - i 是 偶数，然后 交换 这个字符串中两个下标对应的字符。 
// 
//
// 
//
// 如果你可以让字符串 s1 和 s2 相等，那么返回 true ，否则返回 false 。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s1 = "abcdba", s2 = "cabdab"
//输出：true
//解释：我们可以对 s1 执行以下操作：
//- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbadba" 。
//- 选择下标 i = 2 ，j = 4 ，得到字符串 s1 = "cbbdaa" 。
//- 选择下标 i = 1 ，j = 5 ，得到字符串 s1 = "cabdab" = s2 。
// 
//
// 示例 2： 
//
// 
//输入：s1 = "abe", s2 = "bea"
//输出：false
//解释：无法让两个字符串相等。
// 
//
// 
//
// 提示： 
//
// 
// n == s1.length == s2.length 
// 1 <= n <= 10⁵ 
// s1 和 s2 只包含小写英文字母。 
// 
//
// Related Topics 哈希表 字符串 排序 👍 2 👎 0


#include <string>
#include <algorithm>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string l1, l2, r1, r2;
        const auto n = s1.length();
        auto half = (n + 1) / 2;
        l1.reserve(half);
        l2.reserve(half);
        r1.reserve(half);
        r2.reserve(half);
        for (auto i = 0; i < n; ++i) {
            if (i & 1) {

                r1.push_back(s1[i]);
                r2.push_back(s2[i]);
            } else {
                l1.push_back(s1[i]);
                l2.push_back(s2[i]);
            }
        }
        std::sort(l1.begin(), l1.end());
        std::sort(l2.begin(), l2.end());
        if (l1 != l2)
            return false;
        std::sort(r1.begin(), r1.end());
        std::sort(r2.begin(), r2.end());
        return r1 == r2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




