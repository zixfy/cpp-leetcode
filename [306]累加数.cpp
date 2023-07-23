// 累加数 是一个字符串，组成它的数字可以形成累加序列。
//
//  一个有效的 累加序列 必须 至少 包含 3
//  个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。
//
//  给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数
//  。如果是，返回 true ；否则，返回 false 。
//
//  说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03
//  或者 1, 02, 3 的情况。
//
//
//
//  示例 1：
//
//
// 输入："112358"
// 输出：true
// 解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 =
// 8
//
//
//  示例 2：
//
//
// 输入："199100199"
// 输出：true
// 解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
//
//
//
//  提示：
//
//
//  1 <= num.length <= 35
//  num 仅由数字（0 - 9）组成
//
//
//
//
//  进阶：你计划如何处理由过大的整数输入导致的溢出?
//
//  Related Topics 字符串 回溯 👍 413 👎 0

#include <bits/stdc++.h>
using namespace std;

auto recursive_lambda = [](auto &&lam) {
  return [lam_impl = lam](auto &&...args) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};

// leetcode submit region begin(Prohibit modification and deletion)

class Solution {
  using pt = pair<int, int>;
  bool _is_add(const vector<int> &v, pt n1, pt n2) {
    const auto n = v.size();
    while (n2.second < n) {
      vector u(make_reverse_iterator(v.begin() + n2.second),
               make_reverse_iterator(v.begin() + n2.first));
      for (int i = 0, j = n1.second - 1; j >= n1.first; i++, j--)
        u[i] += v[j];
      for (int i = 0; i + 1 < u.size(); ++i)
        if (u[i] > 9)
          u[i + 1] += u[i] / 10, u[i] %= 10;
      if (!u.empty() && u.back() > 9) {
        auto b = u.back() / 10;
        u.back() %= 10;
        u.push_back(b);
      }
      pt n3 = make_pair(n2.second, n2.second + u.size());
      if (n3.second > n ||
          !std::equal(v.begin() + n3.first, v.begin() + n3.second, u.rbegin()))
        return false;

      n1 = n2;
      n2 = n3;
    }
    return n2.second == n;
  }

public:
  bool isAdditiveNumber(string num) {
    const auto n = num.size();
    vector<int> v;
    v.reserve(num.length());
    std::transform(num.begin(), num.end(), back_inserter(v),
                   [](char c) { return c - '0'; });
    for (int j = 1; j < n; ++j)
      for (int k = j + 1; k <= n; ++k) {
        if (j == 1 && v[0] != 0 || k == j + 1 && v[j] != 0)
          continue;
        if (n - k < max(k - j, j))
          continue;
        if (_is_add(v, make_pair(0, j), make_pair(j, k)))
          return true;
      }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
