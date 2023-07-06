// 给你一个下标从 0 开始的二维整数数组 tires ，其中 tires[i] = [fi, ri] 表示第 i
// 种轮胎如果连续使用，第 x 圈需要耗时 fi * ri⁽ˣ⁻¹⁾ 秒。
//
//
//  比方说，如果 fi = 3 且 ri = 2
//  ，且一直使用这种类型的同一条轮胎，那么该轮胎完成第 1 圈赛道耗时 3 秒，完成第
//  2 圈耗时 3 * 2
//= 6 秒，完成第 3 圈耗时 3 * 2² = 12 秒，依次类推。
//
//
//  同时给你一个整数 changeTime 和一个整数 numLaps 。
//
//  比赛总共包含 numLaps 圈，你可以选择 任意 一种轮胎开始比赛。每一种轮胎都有
//  无数条 。每一圈后，你可以选择耗费 changeTime 秒 换成
// 任意一种轮胎（也可以换成当前种类的新轮胎）。
//
//  请你返回完成比赛需要耗费的 最少 时间。
//
//
//
//  示例 1：
//
//  输入：tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
// 输出：21
// 解释：
// 第 1 圈：使用轮胎 0 ，耗时 2 秒。
// 第 2 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
// 第 3 圈：耗费 5 秒换一条新的轮胎 0 ，然后耗时 2 秒完成这一圈。
// 第 4 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
// 总耗时 = 2 + 6 + 5 + 2 + 6 = 21 秒。
// 完成比赛的最少时间为 21 秒。
//
//
//  示例 2：
//
//  输入：tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
// 输出：25
// 解释：
// 第 1 圈：使用轮胎 1 ，耗时 2 秒。
// 第 2 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
// 第 3 圈：耗时 6 秒换一条新的轮胎 1 ，然后耗时 2 秒完成这一圈。
// 第 4 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
// 第 5 圈：耗时 6 秒换成轮胎 0 ，然后耗时 1 秒完成这一圈。
// 总耗时 = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 秒。
// 完成比赛的最少时间为 25 秒。
//
//
//
//
//  提示：
//
//
//  1 <= tires.length <= 10⁵
//  tires[i].length == 2
//  1 <= fi, changeTime <= 10⁵
//  2 <= ri <= 10⁵
//  1 <= numLaps <= 1000
//
//
//  Related Topics 数组 动态规划 👍 67 👎 0

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

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  int minimumFinishTime(vector<vector<int>> &tires, int changeTime,
                        int numLaps) {
    vector dp(numLaps + 1, numeric_limits<int>::max());
    for (const auto &tire : tires) {
      long long base = tire[0], coef = tire[1], tot = base;
      int idx = 1;
      while (idx <= numLaps && tot < numeric_limits<int>::max()) {
        dp[idx] = min(dp[idx], static_cast<int>(tot));
        base *= coef;
        tot += base;
        ++idx;
      }
    }
//    cout << dp << endl;
    for (int i = 2; i <= numLaps; ++i)
      for (int j = 1; j < i; ++j)
        dp[i] = min(dp[i], changeTime + dp[j] + dp[i - j]);
//    cout << dp << endl;
    return dp[numLaps];
    // dp[lap] = dp[las_lap] + cT + cost(lap - las_lap)
  }
};
// leetcode submit region end(Prohibit modification and deletion)
