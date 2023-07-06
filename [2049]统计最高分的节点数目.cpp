// 给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1
// 。同时给你一个下标从 0 开始的整数数组 parents 表示这棵 树，其中 parents[i]
// 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。
//
//  一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数
//  。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，剩余部分是若
// 干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。
//
//  请你返回有 最高得分 节点的 数目 。
//
//
//
//  示例 1:
//
//
//
//  输入：parents = [-1,2,0,2,0]
// 输出：3
// 解释：
//- 节点 0 的分数为：3 * 1 = 3
//- 节点 1 的分数为：4 = 4
//- 节点 2 的分数为：1 * 1 * 2 = 2
//- 节点 3 的分数为：4 = 4
//- 节点 4 的分数为：4 = 4
// 最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
//
//
//  示例 2：
//
//
//
//  输入：parents = [-1,2,0]
// 输出：2
// 解释：
//- 节点 0 的分数为：2 = 2
//- 节点 1 的分数为：2 = 2
//- 节点 2 的分数为：1 * 1 = 1
// 最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
//
//
//
//
//  提示：
//
//
//  n == parents.length
//  2 <= n <= 10⁵
//  parents[0] == -1
//  对于 i != 0 ，有 0 <= parents[i] <= n - 1
//  parents 表示一棵二叉树。
//
//
//  Related Topics 树 深度优先搜索 数组 二叉树 👍 152 👎 0

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
  int countHighestScoreNodes(vector<int> &parents) {
    int ans = 0;
    uint64_t maxx = 0;
    auto update = [&ans, &maxx](uint64_t x) {
      if (maxx < x)
        maxx = x, ans = 0;
      if (maxx == x)
        ans++;
    };

    const auto n = parents.size();
    vector children(n, vector<int>{});
    for (int i = 1; i < parents.size(); ++i)
      children[parents[i]].push_back(i);

    vector<int> in_deg(n, 0), cnt(n, 1);
    for (int i = 1; i < parents.size(); ++i)
      in_deg[parents[i]]++;
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (in_deg[i] == 0)
        q.push(i);
    while (!q.empty()) {
      auto cur = q.front();
      auto to = parents[cur];
      if (to > -1) {
        if (--in_deg[to] == 0)
          q.push(to);
        cnt[to] += cnt[cur];
      }
      q.pop();
    }
    function<void(int, int)> dfs = [&](int cur, int par_score) {
      ::uint64_t base = max(1, par_score);
      vector<int> child_cnts;
      const auto &childs = children[cur];
      for (auto child : childs) {
        base *= cnt[child];
        child_cnts.push_back(cnt[child]);
      }
      if (childs.size() == 1)
        dfs(childs.front(), par_score + 1);
      else if (childs.size() == 2)
        dfs(childs[0], par_score + 1 + child_cnts[1]),
            dfs(childs[1], par_score + 1 + child_cnts[0]);

      update(base);
    };
    dfs(0, 0);
    return ans;
  };
};
// leetcode submit region end(Prohibit modification and deletion)
