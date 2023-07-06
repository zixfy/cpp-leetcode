// 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
//
//  所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
//
//
//
//  示例 1：
//
//  输入：address = "1.1.1.1"
// 输出："1[.]1[.]1[.]1"
//
//
//  示例 2：
//
//  输入：address = "255.100.50.0"
// 输出："255[.]100[.]50[.]0"
//
//
//
//
//  提示：
//
//
//  给出的 address 是一个有效的 IPv4 地址
//
//
//  Related Topics 字符串 👍 128 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
std::vector<std::string> split(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  std::istringstream iss(str);
  std::string token;
  while (std::getline(iss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
class Solution {
public:
  string defangIPaddr(string address) {
    string ans;
    ans.reserve(address.length());
    auto sp = split(address, '.');
    for (auto i = sp.begin(); i < sp.end() - 1; ++i)
      ans += std::move(*i) + "[.]";
    ans += std::move(*(sp.end() - 1));
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
