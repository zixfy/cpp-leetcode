//给你一个 n 个节点的 无向带权连通 图，节点编号为 0 到 n - 1 ，再给你一个整数数组 edges ，其中 edges[i] = [ai, bi, 
//wi] 表示节点 ai 和 bi 之间有一条边权为 wi 的边。 
//
// 部分边的边权为 -1（wi = -1），其他边的边权都为 正 数（wi > 0）。 
//
// 你需要将所有边权为 -1 的边都修改为范围 [1, 2 * 10⁹] 中的 正整数 ，使得从节点 source 到节点 destination 的 最短距
//离 为整数 target 。如果有 多种 修改方案可以使 source 和 destination 之间的最短距离等于 target ，你可以返回任意一种方案。
// 
//
// 如果存在使 source 到 destination 最短距离为 target 的方案，请你按任意顺序返回包含所有边的数组（包括未修改边权的边）。如果不存
//在这样的方案，请你返回一个 空数组 。 
//
// 注意：你不能修改一开始边权为正数的边。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, 
//destination = 1, target = 5
//输出：[[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
//解释：上图展示了一个满足题意的修改方案，从 0 到 1 的最短距离为 5 。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
//输出：[]
//解释：上图是一开始的图。没有办法通过修改边权为 -1 的边，使得 0 到 2 的最短距离等于 6 ，所以返回一个空数组。
// 
//
// 示例 3： 
//
// 
//
// 
//输入：n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination 
//= 2, target = 6
//输出：[[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
//解释：上图展示了一个满足题意的修改方案，从 0 到 2 的最短距离为 6 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 100 
// 1 <= edges.length <= n * (n - 1) / 2 
// edges[i].length == 3 
// 0 <= ai, bi < n 
// wi = -1 或者 1 <= wi <= 107 
// ai != bi 
// 0 <= source, destination < n 
// source != destination 
// 1 <= target <= 10⁹ 
// 输入的图是连通图，且没有自环和重边。 
// 
//
// Related Topics 图 最短路 堆（优先队列） 👍 37 👎 0


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
  o << "[";
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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




