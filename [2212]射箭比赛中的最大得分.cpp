// Alice 和 Bob 是一场射箭比赛中的对手。比赛规则如下：
//
//
//  Alice 先射 numArrows 支箭，然后 Bob 也射 numArrows 支箭。
//  分数按下述规则计算：
//
//  箭靶有若干整数计分区域，范围从 0 到 11 （含 0 和 11）。
//  箭靶上每个区域都对应一个得分 k（范围是 0 到 11），Alice 和 Bob 分别在得分 k
//  区域射中 ak 和 bk 支箭。如果 ak >= bk
// ，那么 Alice 得 k 分。如果 ak < bk ，则 Bob 得 k 分
//  如果 ak == bk == 0 ，那么无人得到 k 分。
//
//
//
//
//  例如，Alice 和 Bob 都向计分为 11 的区域射 2 支箭，那么 Alice 得 11 分。如果
//  Alice 向计分为 11 的区域射 0 支箭，
// 但 Bob 向同一个区域射 2 支箭，那么 Bob 得 11 分。
//
//
//  给你整数 numArrows 和一个长度为 12 的整数数组 aliceArrows ，该数组表示 Alice
//  射中 0 到 11 每个计分区域的箭数量。
// 现在，Bob 想要尽可能 最大化 他所能获得的总分。
//
//  返回数组 bobArrows ，该数组表示 Bob 射中 0 到 11 每个 计分区域的箭数量。且
//  bobArrows 的总和应当等于
// numArrows 。
//
//  如果存在多种方法都可以使 Bob 获得最大总分，返回其中 任意一种 即可。
//
//
//
//  示例 1：
//
//
//
//
// 输入：numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
// 输出：[0,0,0,0,1,1,0,0,1,2,3,1]
// 解释：上表显示了比赛得分情况。
// Bob 获得总分 4 + 5 + 8 + 9 + 10 + 11 = 47 。
// 可以证明 Bob 无法获得比 47 更高的分数。
//
//
//  示例 2：
//
//
//
//
// 输入：numArrows = 3, aliceArrows = [0,0,1,0,0,0,0,0,0,0,0,2]
// 输出：[0,0,0,0,0,0,0,0,1,1,1,0]
// 解释：上表显示了比赛得分情况。
// Bob 获得总分 8 + 9 + 10 = 27 。
// 可以证明 Bob 无法获得比 27 更高的分数。
//
//
//
//
//  提示：
//
//
//  1 <= numArrows <= 10⁵
//  aliceArrows.length == bobArrows.length == 12
//  0 <= aliceArrows[i], bobArrows[i] <= numArrows
//  sum(aliceArrows[i]) == numArrows
//
//
//  Related Topics 位运算 递归 数组 枚举 👍 44 👎 0

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
class Solution {
private:
  inline static int low_bit(int x) { return x & -x; }

public:
  vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
    vector<int> costs;
    for (int i = 0; i < 12; ++i)
      costs.push_back(aliceArrows[i] + 1);
    vector ans(12, 0);
    int maxm = 0;
    for (int s = 0; s < (1 << 11); ++s) {
      int st = s << 1;
      int cost = 0, gain = 0;
      for (int i = 1; i < 12; ++i)
        if (st & (1 << i))
          cost += costs[i], gain += i;
      if (cost <= numArrows && gain > maxm) {
        maxm = gain;
        std::fill(ans.begin(), ans.end(), 0);
        for (int i = 1; i < 12; ++i)
          if (st & (1 << i))
            ans[i] = costs[i];
        ans[0] = numArrows - cost;
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
