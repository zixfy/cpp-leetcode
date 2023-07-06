// 给你一个下标从 0 开始的字符串 word ，字符串只包含小写英文字母。你需要选择
// 一个 下标并 删除 下标处的字符，使得 word 中剩余每个字母出现 频 率 相同。
//
//  如果删除一个字母后，word 中剩余所有字母的出现频率都相同，那么返回 true
//  ，否则返回 false 。
//
//  注意：
//
//
//  字母 x 的 频率 是这个字母在字符串中出现的次数。
//  你 必须 恰好删除一个字母，不能一个字母都不删除。
//
//
//
//
//  示例 1：
//
//  输入：word = "abcc"
// 输出：true
// 解释：选择下标 3 并删除该字母，word 变成 "abc" 且每个字母出现频率都为 1 。
//
//
//  示例 2：
//
//  输入：word = "aazz"
// 输出：false
// 解释：我们必须删除一个字母，所以要么 "a" 的频率变为 1 且 "z" 的频率为 2
// ，要么两个字母频率反过来。所以不可能让剩余所有字母出现频率相同。
//
//
//
//
//  提示：
//
//
//  2 <= word.length <= 100
//  word 只包含小写英文字母。
//
//
//  Related Topics 哈希表 字符串 计数 👍 54 👎 0
#include <bits/stdc++.h>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  if (!v.empty())
    std::copy(v.begin(), v.end(), ostream_iterator<T, char>(o, ", "));
  return o << "]";
}

class Solution {
public:
  bool equalFrequency(string word) {
    unordered_map<char, int> cnt;
    for (auto c : word)
      cnt[c]++;
    vector<int> cnt_ls;
    cnt_ls.reserve(cnt.size());
    for (const auto &p : cnt)
      cnt_ls.emplace_back(p.second);
    sort(cnt_ls.begin(), cnt_ls.end());
//    cout << cnt_ls << endl;
    if (cnt_ls.size() == 1 || cnt_ls.size() > 1 && cnt_ls[0] == 1 &&
                                  cnt_ls[1] == cnt_ls[cnt_ls.size() - 1])
      return true;
    if ((word.length() - 1) % cnt.size())
      return false;
    int base = (word.length() - 1) / cnt.size();
    return cnt_ls[0] == base && cnt_ls[cnt_ls.size() - 1] == base + 1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
