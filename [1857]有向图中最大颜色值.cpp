// 给你一个 有向图 ，它含有 n 个节点和 m 条边。节点编号从 0 到 n - 1 。
//
//  给你一个字符串 colors ，其中 colors[i] 是小写英文字母，表示图中第 i 个节点的
//  颜色 （下标从 0 开始）。同时给你一个二维数组
// edges ，其中 edges[j] = [aj, bj] 表示从节点 aj 到节点 bj 有一条 有向边 。
//
//  图中一条有效 路径 是一个点序列 x1 -> x2 -> x3 -> ... -> xk ，对于所有 1 <= i
//  < k ，从 xi 到 xi+1 在图
// 中有一条有向边。路径的 颜色值 是路径中 出现次数最多 颜色的节点数目。
//
//  请你返回给定图中有效路径里面的 最大颜色值 。如果图中含有环，请返回 -1 。
//
//
//
//  示例 1：
//
//
//
//  输入：colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// 输出：3
// 解释：路径 0 -> 2 -> 3 -> 4 含有 3 个颜色为 "a" 的节点（上图中的红色节点）。
//
//
//  示例 2：
//
//
//
//  输入：colors = "a", edges = [[0,0]]
// 输出：-1
// 解释：从 0 到 0 有一个环。
//
//
//
//
//  提示：
//
//
//  n == colors.length
//  m == edges.length
//  1 <= n <= 10⁵
//  0 <= m <= 10⁵
//  colors 只含有小写英文字母。
//  0 <= aj, bj < n
//
//
//  Related Topics 图 拓扑排序 记忆化搜索 哈希表 动态规划 计数 👍 42 👎 0

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
private:
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {

    const auto n = colors.size();
    vector adjs(n, vector<int>{});
    vector<int> orders;
    orders.reserve(n);
    for (const auto &e : edges)
      adjs[e[0]].emplace_back(e[1]);
    vector<int> in_deg(n, 0);
    for (const auto &tos : adjs)
      for (auto to : tos)
        in_deg[to]++;
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (in_deg[i] == 0)
        q.push(i);
    while (!q.empty()) {
      auto cur = q.front();
      orders.emplace_back(cur);
      for (auto to : adjs[cur])
        if (--in_deg[to] == 0)
          q.push(to);
      q.pop();
    }
    if (orders.size() != n)
      return -1;
    vector<int> dp(n);
    int ans = 0;
    cout << orders << endl;
    for (auto c = 'a'; c <= 'z'; ++c) {
      std::fill(dp.begin(), dp.end(),  0);
      for (auto cur : orders) {
        dp[cur] += (c == colors[cur]);
//        if (c == colors[cur])
//          cout << "c: " << c << ", cur:" << cur << ", dp:" << dp[cur] << endl;
        ans = max(ans, dp[cur]);
        for (auto to : adjs[cur])
          dp[to] = max(dp[to], dp[cur]);
      }
    }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
