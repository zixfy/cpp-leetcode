// 有 n 个项目，每个项目或者不属于任何小组，或者属于 m 个小组之一。group[i]
// 表示第 i 个项目所属的小组，如果第 i 个项目不属于任何小组，则 group[i] 等于
// -1。项目和小组都是从零开始编号的。可能存在小组不负责任何项目，即没有任何项目属于这个小组。
//
//  请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
//
//
//  同一小组的项目，排序后在列表中彼此相邻。
//  项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中
//  beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个
// 项目左侧）应该完成的所有项目。
//
//
//  如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个
//  空列表 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
// [[],[6],[5],[6],[ 3,6],[],[],[]] 输出：[6,3,4,1,5,2,0,7]
//
//
//  示例 2：
//
//
// 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
// [[],[6],[5],[6],[ 3],[],[4],[]] 输出：[] 解释：与示例 1
// 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
//
//
//
//
//  提示：
//
//
//  1 <= m <= n <= 3 * 10⁴
//  group.length == beforeItems.length == n
//  -1 <= group[i] <= m - 1
//  0 <= beforeItems[i].length <= n - 1
//  0 <= beforeItems[i][j] <= n - 1
//  i != beforeItems[i][j]
//  beforeItems[i] 不含重复元素
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 217 👎 0

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
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

vector<int> topical_sort(const vector<vector<int>> &adjs) {
  const auto n = adjs.size();
  vector<int> in_deg(n, 0);
  for (const auto &tos : adjs)
    for (auto to : tos)
      in_deg[to]++;
  queue<int> q;
  for (int i = 0; i < n; ++i)
    if (in_deg[i] == 0)
      q.push(i);
  vector<int> ans;
  ans.reserve(n);
  while (!q.empty()) {
    auto cur = q.front();
    ans.push_back(cur);
    for (auto to : adjs[cur])
      if (--in_deg[to] == 0)
        q.push(to);
    q.pop();
  }
  return ans;
}
class Solution {
public:
  vector<int> sortItems(int n, int m, vector<int> &group,
                        vector<vector<int>> &beforeItems) {
    vector adjs(n, vector<int>{});
    int i = 0;
    for (const auto &pre : beforeItems) {
      for (auto from : pre)
        adjs[from].emplace_back(i);
      i++;
    }
    auto orders = topical_sort(adjs);

//    cout << adjs << endl;
//    cout << orders << endl;
    if (orders.size() < n)
      return {};
    int nxt_group_number = m;
    unordered_map<int, int> in_degrees;
    unordered_map<int, vector<int>> group2members, group_adjs;
    for (int i = 0; i < n; ++i) {
      auto &g = group[orders[i]];
      if (g == -1)
        g = nxt_group_number++;
      group2members[g].emplace_back(orders[i]);
    }
    for (int i = 0; i < n; ++i) {
      auto g = group[orders[i]];
      in_degrees.operator[](g);
      for (auto from : beforeItems[orders[i]])
        if (auto gf = group[from]; g != gf)
          group_adjs[gf].emplace_back(g), in_degrees[g]++;
    }

    queue<int> q;
    for (const auto [g, in_d] : in_degrees)
      if (in_d == 0)
        q.push(g);
    vector<int> ans;
    ans.reserve(n);
    while (!q.empty()) {
      auto cur = q.front();
      for (auto mem : group2members[cur])
        ans.emplace_back(mem);
      for (auto tog : group_adjs[cur])
        if (--in_degrees[tog] == 0)
          q.push(tog);
      q.pop();
    }
    //    cout << group_adjs << endl;
    //    cout << in_degrees << endl;
    //    cout << ans;
    return ans.size() == n ? ans : vector<int>();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
