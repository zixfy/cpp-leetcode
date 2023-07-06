// 有 n 座城市，编号从 1 到 n 。编号为 x 和 y 的两座城市直接连通的前提是： x 和
// y 的公因数中，至少有一个 严格大于 某个阈值 threshold
// 。更正式地说，如果存在整数 z ，且满足以下所有条件，则编号 x 和 y
// 的城市之间有一条道路：
//
//
//  x % z == 0
//  y % z == 0
//  z > threshold
//
//
//  给你两个整数 n 和 threshold ，以及一个待查询数组，请你判断每个查询
//  queries[i] = [ai, bi] 指向的城市 ai 和 bi
// 是否连通（即，它们之间是否存在一条路径）。
//
//  返回数组 answer ，其中answer.length == queries.length 。如果第 i
//  个查询中指向的城市 ai 和 bi 连通，则
// answer[i] 为 true ；如果不连通，则 answer[i] 为 false 。
//
//
//
//  示例 1：
//
//
//
//
//
//
// 输入：n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
// 输出：[false,false,true]
// 解释：每个数的因数如下：
// 1:   1
// 2:   1, 2
// 3:   1, 3
// 4:   1, 2, 4
// 5:   1, 5
// 6:   1, 2, 3, 6
// 所有大于阈值的的因数已经加粗标识，只有城市 3 和 6 共享公约数 3 ，因此结果是：
//[1,4]   1 与 4 不连通
//[2,5]   2 与 5 不连通
//[3,6]   3 与 6 连通，存在路径 3--6
//
//
//  示例 2：
//
//
//
//
//
//
// 输入：n = 6, threshold = 0, queries = [[4,5],[3,4],[3,2],[2,6],[1,3]]
// 输出：[true,true,true,true,true]
// 解释：每个数的因数与上一个例子相同。但是，由于阈值为 0
// ，所有的因数都大于阈值。因为所有的数字共享公因数 1
// ，所以所有的城市都互相连通。
//
//
//  示例 3：
//
//
//
//
//
//
// 输入：n = 5, threshold = 1, queries = [[4,5],[4,5],[3,2],[2,3],[3,4]]
// 输出：[false,false,false,false,false]
// 解释：只有城市 2 和 4 共享的公约数 2 严格大于阈值 1
// ，所以只有这两座城市是连通的。 注意，同一对节点 [x, y]
// 可以有多个查询，并且查询 [x，y] 等同于查询 [y，x] 。
//
//
//
//
//  提示：
//
//
//  2 <= n <= 10⁴
//  0 <= threshold <= n
//  1 <= queries.length <= 10⁵
//  queries[i].length == 2
//  1 <= ai, bi <= cities
//  ai != bi
//
//
//  Related Topics 并查集 数组 数学 👍 45 👎 0

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

class UnionFind {
public:
  UnionFind() = delete;
  UnionFind(size_t n) : _n(n), _scc(n) {
    _par.reserve(_n);
    for (auto i = 0; i < _n; ++i)
      _par.push_back(i);
  };
  bool add_link(int a, int b);
  inline int get_scc_n() { return _scc; }
  friend class Solution;

private:
  int find_par(int);
  size_t _n, _scc;
  vector<int> _par;
};

int UnionFind::find_par(int x) {
  if (_par[x] != x)
    _par[x] = find_par(_par[x]);
  return _par[x];
}
bool UnionFind::add_link(int a, int b) {
  auto p1 = find_par(a), p2 = find_par(b);
  if (p1 == p2)
    return false;
  _par[p1] = p2;
  --_scc;
  return true;
}
class Solution {
public:
  vector<bool> areConnected(int n, int threshold,
                            vector<vector<int>> &queries) {
    vector<bool> ans;
    ans.reserve(queries.size());

    auto ufs = UnionFind(n);
    for (const auto &q : queries)
      ans.emplace_back(ufs.find_par(q[0] - 1) == ufs.find_par(q[1] - 1));
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
