// 给你一个整数 n 表示某所大学里课程的数目，编号为 1 到 n ，数组 relations 中，
// relations[i] = [xi, yi] 表示一个先 修课的关系，也就是课程 xi 必须在课程 yi
// 之前上。同时你还有一个整数 k 。
//
//  在一个学期中，你 最多 可以同时上 k
//  门课，前提是这些课的先修课在之前的学期里已经上过了。
//
//  请你返回上完所有课最少需要多少个学期。题目保证一定存在一种上完所有课的方式。
//
//
//
//  示例 1：
//
//
//
//
// 输入：n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
// 输出：3
// 解释：上图展示了题目输入的图。在第一个学期中，我们可以上课程 2 和课程 3
// 。然后第二个学期上课程 1 ，第三个学期上课程 4 。
//
//
//  示例 2：
//
//
//
//
// 输入：n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
// 输出：4
// 解释：上图展示了题目输入的图。一个最优方案是：第一学期上课程 2 和
// 3，第二学期上课程 4 ，第三学期上课程 1 ，第四学期上课程 5 。
//
//
//  示例 3：
//
//
// 输入：n = 11, relations = [], k = 2
// 输出：6
//
//
//
//
//  提示：
//
//
//  1 <= n <= 15
//  1 <= k <= n
//  0 <= relations.length <= n * (n-1) / 2
//  relations[i].length == 2
//  1 <= xi, yi <= n
//  xi != yi
//  所有先修关系都是不同的，也就是说 relations[i] != relations[j] 。
//  题目输入的图是个有向无环图。
//
//
//  Related Topics 位运算 图 动态规划 状态压缩 👍 111 👎 0

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
  int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
    vector adjs(n, vector<int>{});
    for (const auto &rel : relations)
      adjs[rel[0] - 1].push_back(rel[1] - 1);
    vector<int> in_deg(n, 0), mask(n, 0);
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
    cout << ans;
    return 0;
    //dp[s] =
  }
};
// leetcode submit region end(Prohibit modification and deletion)
