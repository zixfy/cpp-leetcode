// 给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中
// edges[i] = [fromi, toi] 表示一条从 点 fromi 到点 toi 的有向边。
//
//  找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。
//
//  你可以以任意顺序返回这些节点编号。
//
//
//
//  示例 1：
//
//
//
//  输入：n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
// 输出：[0,3]
// 解释：从单个节点出发无法到达所有节点。从 0 出发我们可以到达 [0,1,2,5] 。从 3
// 出发我们可以到达 [3,4,2,5] 。所以我们输出 [0,3 ] 。
//
//  示例 2：
//
//
//
//  输入：n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
// 输出：[0,2,3]
// 解释：注意到节点 0，3 和 2
// 无法从其他节点到达，所以我们必须将它们包含在结果点集中，这些点都能到达节点 1
// 和 4 。
//
//
//
//
//  提示：
//
//
//  2 <= n <= 10^5
//  1 <= edges.length <= min(10^5, n * (n - 1) / 2)
//  edges[i].length == 2
//  0 <= fromi, toi < n
//  所有点对 (fromi, toi) 互不相同。
//
//
//  Related Topics 图 👍 67 👎 0

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
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<int> in_deg(n, 0);
    vector<int> ans;
    for (const auto &e : edges)
      in_deg[e[1]]++;
    for (int i = 0; i < n; ++i)
      if (in_deg[i] == 0)
        ans.emplace_back(i);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
