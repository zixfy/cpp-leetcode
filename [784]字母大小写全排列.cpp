// 给定一个字符串 s ，通过将字符串 s
// 中的每个字母转变大小写，我们可以获得一个新的字符串。
//
//  返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
//
//
//
//  示例 1：
//
//
// 输入：s = "a1b2"
// 输出：["a1b2", "a1B2", "A1b2", "A1B2"]
//
//
//  示例 2:
//
//
// 输入: s = "3z4"
// 输出: ["3z4","3Z4"]
//
//
//
//
//  提示:
//
//
//  1 <= s.length <= 12
//  s 由小写英文字母、大写英文字母和数字组成
//
//
//  Related Topics 位运算 字符串 回溯 👍 556 👎 0

#include <algorithm>
#include <array>
#include <memory>
#include <queue>
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
  vector<string> letterCasePermutation(string s) {
    vector<int> pivots;
    for (auto i = 0; i < s.length(); ++i)
      if (std::isalpha(s[i])) {
        s[i] = std::tolower(s[i]);
        pivots.emplace_back(i);
      }
    vector<string> ans;
    auto power = 1 << pivots.size();
    ans.reserve(power);
    for (auto state = 0; state < power; ++state) {
      auto s_copy = s;
      for (auto j = 0; j < pivots.size(); ++j)
        if (state & (1 << j))
          s_copy[pivots[j]] = std::toupper(s_copy[pivots[j]]);
      ans.emplace_back(std::move(s_copy));
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
