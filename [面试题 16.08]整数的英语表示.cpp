//给定一个整数，打印该整数的英文描述。 
//
// 示例 1: 
//
// 
//输入: 123
//输出: "One Hundred Twenty Three"
// 
//
// 示例 2: 
//
// 
//输入: 12345
//输出: "Twelve Thousand Three Hundred Forty Five" 
//
// 示例 3: 
//
// 
//输入: 1234567
//输出: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven" 
//
// 示例 4: 
//
// 
//输入: 1234567891
//输出: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven 
//Thousand Eight Hundred Ninety One" 
//
// 注意：本题与 273 题相同：https://leetcode-cn.com/problems/integer-to-english-words/ 
//
// Related Topics 递归 数学 字符串 👍 24 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <sstream>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
constexpr int THOUSAND = 1000, HUNDRED = 100, TEN = 10;
constexpr int MILLION = THOUSAND * THOUSAND;
constexpr int BILLION = MILLION * THOUSAND;
constexpr std::array<string_view, TEN> digits{
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
};
constexpr std::array<std::string_view, TEN> tens = {
        "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
constexpr std::array<std::string_view, TEN> ten_add = {
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return {"Zero"};
        std::stringstream ss;

        auto b = num / BILLION;
        auto m = (num % BILLION) / MILLION;
        auto t = (num % MILLION) / THOUSAND;
        auto d = num % THOUSAND;
        auto f = [&](int x) {
            auto h = x / 100;
            if (h)
                ss << digits[h] << " Hundred ";
            auto t = (x % 100) / 10;
            auto d = x % 10;
            if (t == 1) {
                ss << ten_add[d] << " ";
            } else {
                if (t != 0) {
                    ss << tens[t] << " ";
                }
                if (d != 0) {
                    ss << digits[d] << " ";
                }
            }

        };
        if (b)
            f(b), ss << "Billion ";
        if (m)
            f(m), ss << "Million ";
        if (t)
            f(t), ss << "Thousand ";
        f(d);
        auto ans = ss.str();
        ans.pop_back();
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




