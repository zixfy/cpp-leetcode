// 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
//
//  连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| +
//  |yi - yj| ，其中 |val| 表示
// val 的绝对值。
//
//  请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有
//  一条简单路径时，才认为所有点都已连接。
//
//
//
//  示例 1：
//
//
//
//
// 输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// 输出：20
// 解释：
//
// 我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
// 注意到任意两个点之间只有唯一一条路径互相到达。
//
//
//  示例 2：
//
//
// 输入：points = [[3,12],[-2,5],[-4,1]]
// 输出：18
//
//
//  示例 3：
//
//
// 输入：points = [[0,0],[1,1],[1,0],[-1,1]]
// 输出：4
//
//
//  示例 4：
//
//
// 输入：points = [[-1000000,-1000000],[1000000,1000000]]
// 输出：4000000
//
//
//  示例 5：
//
//
// 输入：points = [[0,0]]
// 输出：0
//
//
//
//
//  提示：
//
//
//  1 <= points.length <= 1000
//  -10⁶ <= xi, yi <= 10⁶
//  所有点 (xi, yi) 两两不同。
//
//
//  Related Topics 并查集 图 数组 最小生成树 👍 279 👎 0

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
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    const auto n = points.size();
    unordered_set<int> to_vis;
    for (int i = 0; i < n; ++i)
      to_vis.emplace(i);
    using xy = pair<int, int>;
    auto cmp = [](const xy &a, const xy &b) { return a.second > b.second; };
    priority_queue<xy, vector<xy>, function<bool(const xy &, const xy &)>> q(
        cmp);
    q.emplace(0, 0);
    int ans = 0;
    while (!q.empty()) {
      auto [cur, dist] = q.top();
      q.pop();
      if (!to_vis.count(cur))
        continue;
      to_vis.erase(cur);
      ans += dist;
      for (auto to : to_vis)
        q.emplace(to, abs(points[cur][0] - points[to][0]) +
                          abs(points[cur][1] - points[to][1]));

    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
