// 给你一个整数 n 。如果两个整数 x 和 y 满足下述条件，则认为二者形成一个质数对：
//
//
//  1 <= x <= y <= n
//  x + y == n
//  x 和 y 都是质数
//
//
//  请你以二维有序列表的形式返回符合题目要求的所有 [xi, yi] ，列表需要按 xi 的
//  非递减顺序 排序。如果不存在符合要求的质数对，则返回一个空数组。
//
//
//  注意：质数是大于 1 的自然数，并且只有两个因子，即它本身和 1 。
//
//
//
//  示例 1：
//
//  输入：n = 10
// 输出：[[3,7],[5,5]]
// 解释：在这个例子中，存在满足条件的两个质数对。
// 这两个质数对分别是 [3,7] 和 [5,5]，按照题面描述中的方式排序后返回。
//
//
//  示例 2：
//
//  输入：n = 2
// 输出：[]
// 解释：可以证明不存在和为 2 的质数对，所以返回一个空数组。
//
//
//
//
//  提示：
//
//
//  1 <= n <= 10⁶
//
//
//  Related Topics 数组 数学 枚举 数论 👍 4 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

auto euler(int n) {
  vector<int> vis(n + 1, 0);
  set<int> pris;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i])
      pris.insert(i);
    for (auto pri : pris) {
      if (auto nxt = 1ll * i * pri; nxt > n)
        break;
      else
        vis[nxt] = 1;
      if (i % pri == 0)
        break;
    }
  }
  return pris;
}
auto tmp = euler(1e6);
unordered_set<int> primes{tmp.begin(), tmp.end()};
class Solution {
public:
  vector<vector<int>> findPrimePairs(int n) {
    vector<vector<int>> ans;
    if (primes.count(n - 2))
      ans.emplace_back(vector{2, n - 2});
    for (int x = 3, y = n - 3; x <= y; x += 2, y -= 2)
      if (primes.count(x) && primes.count(y))
        ans.emplace_back(initializer_list<int>{x, y});
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
