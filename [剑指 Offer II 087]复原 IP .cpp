//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。 
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 
//输入：s = "10203040"
//输出：["10.20.30.40","102.0.30.40","10.203.0.40"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
//
// 
//
// 
// 注意：本题与主站 93 题相同：https://leetcode-cn.com/problems/restore-ip-addresses/ 
//
// Related Topics 字符串 回溯 👍 52 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/4/16.
//
#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream& operator<<(ostream &o, const vector<T> &v){
  o << "[" ;
  for(auto i = v.begin(); i != v.end(); ++i){
    if (i != v.begin())
      o <<", ";
    o << (*i);
  }
  o << "]";
  return o;
}
class Solution {
private:
  inline static bool check(const string& s) {
    if (s.empty())
      return false;
    int _ = stoi(s);
    if (s[0] == '0')
      return s.length() == 1;
    return _ < 256;
  }
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> addr_bytes;
    vector<string> ans;
    const int n = s.length();
    if (n < 4 || n > 12)
      return {};
    function<void(int, int)> dfs = [&] (int cur, int dep) {
      if (dep == 3) {
        addr_bytes.emplace_back(s.begin() + cur, s.end());
        if (check(addr_bytes.back())) {
          string tmp;
          for (int i = 0; i < 3; ++i)
            tmp.append(addr_bytes[i] + ".");
          tmp.append(addr_bytes[3]);
          ans.emplace_back(std::move(tmp));
        }
        //cout << addr_bytes << endl;
        addr_bytes.pop_back();
      }
      for (int i = max(cur, n + 3 * dep - 10); i < cur + 3 && i <= n + dep - 4; ++i) {
        // rem = n - i - 1,  (3 - dep)  <= n - i - 1 <= 3 * (3 - dep)
        // i <= n + dep - 4
        // i >= n + 3 * dep - 10
        addr_bytes.emplace_back(s.begin() + cur, s.begin() + i + 1);
        if (check(addr_bytes.back()))
          dfs(i + 1, dep + 1);
        addr_bytes.pop_back();
      }
    };
    dfs(0, 0);
    return std::move(ans);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
