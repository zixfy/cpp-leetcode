//
// Created by wwww on 2023/4/21.
//
#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
ostream &operator<<(std::ostream &o, const array<T, N> &v)

{
  o << "span [";
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << *it << ", ";
  }
  return o << "]";
}
constexpr size_t ALPHA_N{'z' - 'a' + 1};
class Solution {
public:
  int longestSubstring(string s, int k) {
    auto n{s.length()};
    if (k > n)
      return 0;
    if (k == 1)
      return n;
    size_t ans{};
    for (size_t i = 1; i <= ALPHA_N; ++i) {
      size_t okay{}, cls{};
      size_t l{}, r{};
      array<int, ALPHA_N> cnt{};
      for (; r < n; ++r) {
        if (++cnt[s[r] - 'a'] == 1)
          ++cls;
        else if (cnt[s[r] - 'a'] == k)
          ++okay;
        while (cls > i) {
          if (--cnt[s[l] - 'a'] == k - 1)
            --okay;
          if (cnt[s[l] - 'a'] == 0)
            --cls;
          ++l;
        }
        if (okay == cls)
          ans = max(ans, r - l + 1);
      }
    }
    return ans;
  }
};