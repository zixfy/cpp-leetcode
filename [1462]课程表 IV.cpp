// 你总共需要上
//  numCourses 门课，课程编号依次为 0 到 numCourses-1 。你会得到一个数组
//  prerequisite ，其中 prerequisites[i] = [ai, bi] 表示如果你想选 bi 课程，你
//  必须 先选 ai 课程。
//
//
//  有的课会有直接的先修课程，比如如果想上课程 1 ，你必须先上课程 0 ，那么会以
//  [0,1] 数对的形式给出先修课程数对。
//
//
//  先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c
//  的先决条件，那么课程 a 就是课程 c 的先决条件。
//
//  你也得到一个数组
//  queries ，其中
//  queries[j] = [uj, vj]。对于第 j 个查询，您应该回答课程
//  uj 是否是课程
//  vj 的先决条件。
//
//  返回一个布尔数组 answer ，其中 answer[j] 是第 j 个查询的答案。
//
//
//
//  示例 1：
//
//
//
//
// 输入：numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
// 输出：[false,true]
// 解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
//
//
//  示例 2：
//
//
// 输入：numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
// 输出：[false,false]
// 解释：没有先修课程对，所以每门课程之间是独立的。
//
//
//  示例 3：
//
//
//
//
// 输入：numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries =
// [[1,0],[1,2]
//]
// 输出：[true,true]
//
//
//
//
//  提示：
//
//
//
//
//
//  2 <= numCourses <= 100
//  0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
//  prerequisites[i].length == 2
//  0 <= ai, bi <= n - 1
//  ai != bi
//  每一对
//  [ai, bi] 都 不同
//  先修课程图中没有环。
//  0 <= ui, vi <= n - 1
//  ui != vi
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 107 👎 0

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
std::ostream &operator<<(std::ostream &o, const std::unordered_set<T> &v) {
  o << "hashset [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {

    const auto n = numCourses;
    vector<int> in_deg(n, 0);
    vector pres(n, unordered_set<int>{});
    vector adjs(n, vector<int>{});
    for (const auto &e : prerequisites)
      in_deg[e[1]]++, adjs[e[0]].emplace_back(e[1]);
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (in_deg[i] == 0)
        q.push(i);

    while (!q.empty()) {
      auto cur = q.front();
      for (auto to : adjs[cur]) {
        if (--in_deg[to] == 0)
          q.push(to);
        pres[to].emplace(cur);
        for (auto prepre : pres[cur])
          pres[to].emplace(prepre);
      }
      q.pop();
    }
    vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto &q : queries) {
      ans.emplace_back(pres[q[1]].count(q[0]));
    }
//    cout << pres;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
