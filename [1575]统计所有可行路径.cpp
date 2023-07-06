// 给你一个 互不相同 的整数数组，其中 locations[i] 表示第 i
// 个城市的位置。同时给你 start，finish 和 fuel 分别表示出发城市
// 、目的地城市和你初始拥有的汽油总量
//
//  每一步中，如果你在城市 i ，你可以选择任意一个城市 j ，满足 j != i 且 0 <= j
//  < locations.length ，并移动到城市
// j 。从城市 i 移动到 j 消耗的汽油量为 |locations[i] - locations[j]|，|x| 表示
// x 的绝对值。
//
//  请注意， fuel 任何时刻都 不能 为负，且你 可以 经过任意城市超过一次（包括
//  start 和 finish ）。
//
//  请你返回从 start 到 finish 所有可能路径的数目。
//
//  由于答案可能很大， 请将它对 10^9 + 7 取余后返回。
//
//
//
//  示例 1：
//
//
// 输入：locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
// 输出：4
// 解释：以下为所有可能路径，每一条都用了 5 单位的汽油：
// 1 -> 3
// 1 -> 2 -> 3
// 1 -> 4 -> 3
// 1 -> 4 -> 2 -> 3
//
//
//  示例 2：
//
//
// 输入：locations = [4,3,1], start = 1, finish = 0, fuel = 6
// 输出：5
// 解释：以下为所有可能的路径：
// 1 -> 0，使用汽油量为 fuel = 1
// 1 -> 2 -> 0，使用汽油量为 fuel = 5
// 1 -> 2 -> 1 -> 0，使用汽油量为 fuel = 5
// 1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 3
// 1 -> 0 -> 1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 5
//
//
//  示例 3：
//
//
// 输入：locations = [5,2,1], start = 0, finish = 2, fuel = 3
// 输出：0
// 解释：没有办法只用 3 单位的汽油从 0 到达 2 。因为最短路径需要 4 单位的汽油。
//
//
//
//  提示：
//
//
//  2 <= locations.length <= 100
//  1 <= locations[i] <= 10⁹
//  所有 locations 中的整数 互不相同 。
//  0 <= start, finish < locations.length
//  1 <= fuel <= 200
//
//
//  Related Topics 记忆化搜索 数组 动态规划 👍 97 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>);
template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);

template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)
constexpr int MOD = 1e9 + 7;
class Solution {
public:
  int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
    // dp[loc][fuel] += dp[loc'][fuel + cost(loc - loc')]
    const auto n = locations.size();
    vector dp(n, vector(fuel + 1, 0));
    dp[start][fuel] = 1;
    for (int f = fuel; f >= 0; --f)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          if (i == j)
            continue;
          auto pi = locations[i], pj = locations[j];
          auto cost = abs(pi - pj);
          if (auto nf = cost + f; nf <= fuel)
            dp[j][f] = (dp[j][f] + dp[i][nf]) % MOD;
        }
    int ans = 0;
    for (int i = 0; i <= fuel; ++i)
      ans = (ans + dp[finish][i]) % MOD;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
