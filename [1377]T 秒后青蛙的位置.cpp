// 给你一棵由 n 个顶点组成的无向树，顶点编号从 1 到 n。青蛙从 顶点 1
// 开始起跳。规则如下：
//
//
//  在一秒内，青蛙从它所在的当前顶点跳到另一个 未访问
//  过的顶点（如果它们直接相连）。 青蛙无法跳回已经访问过的顶点。
//  如果青蛙可以跳到多个不同顶点，那么它跳到其中任意一个顶点上的机率都相同。
//  如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。
//
//
//  无向树的边用数组 edges 描述，其中 edges[i] = [ai, bi] 意味着存在一条直接连通
//  ai 和 bi 两个顶点的边。
//
//  返回青蛙在 t 秒后位于目标顶点 target 上的概率。与实际答案相差不超过 10⁻⁵
//  的结果将被视为正确答案。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
// 输出：0.16666666666666666
// 解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，第 1 秒 有 1/3
// 的概率跳到顶点 2 ，然后第 2 秒 有 1/2 的概率跳到顶点 4，因此青蛙 在 2
// 秒后位于顶点 4 的概率是 1/3 * 1/2 = 1/6 = 0.16666666666666666 。
//
//
//  示例 2：
//
//
//
//
// 输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
// 输出：0.3333333333333333
// 解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，有 1/3 =
// 0.3333333333333333 的概率能够 1 秒 后跳到顶点 7 。
//
//
//
//
//
//
//  提示：
//
//
//  1 <= n <= 100
//  edges.length == n - 1
//  edges[i].length == 2
//  1 <= ai, bi <= n
//  1 <= t <= 50
//  1 <= target <= n
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 图 👍 88 👎 0

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
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    unordered_set<int> visited;
    vector adjs(n + 1, vector<int>{});
    for (const auto &e : edges)
      adjs[e[0]].emplace_back(e[1]), adjs[e[1]].emplace_back(e[0]);
    vector ans(n + 1, 0.);
    ans[1] = 1.;
    queue<int> q;
    visited.emplace(1), q.push(1);
    int tim = 0;
    while (!q.empty() && tim < t) {
      auto cur_sz = q.size();
      for (int i = 0; i < cur_sz; ++i) {
        auto cur = q.front();
        auto out_deg = 0;
//        cout << cur << ", " << ans[cur] << endl;
        for (auto to : adjs[cur])
          if (!visited.count(to))
            out_deg++;
        if (out_deg > 0) {
          for (auto to : adjs[cur])
            if (!visited.count(to))
              visited.emplace(to), ans[to] = ans[cur] / out_deg, q.push(to);
          ans[cur] = 0.;
        }
        q.pop();
      }
      ++tim;
    }
    return ans[target];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
