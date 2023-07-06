// 给你一个 m * n 的矩阵 mat，以及一个整数 k
// ，矩阵中的每一行都以非递减的顺序排列。
//
//  你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 最小
//  数组和。
//
//
//
//  示例 1：
//
//  输入：mat = [[1,3,11],[2,4,6]], k = 5
// 输出：7
// 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
//[1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。
//
//  示例 2：
//
//  输入：mat = [[1,3,11],[2,4,6]], k = 9
// 输出：17
//
//
//  示例 3：
//
//  输入：mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
// 输出：9
// 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
//[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7
// 个的和是 9 。
//
//
//  示例 4：
//
//  输入：mat = [[1,1,10],[2,2,9]], k = 7
// 输出：12
//
//
//
//
//  提示：
//
//
//  m == mat.length
//  n == mat.length[i]
//  1 <= m, n <= 40
//  1 <= k <= min(200, n ^ m)
//  1 <= mat[i][j] <= 5000
//  mat[i] 是一个非递减数组
//
//
//  Related Topics 数组 二分查找 矩阵 堆（优先队列） 👍 137 👎 0

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
  int kthSmallest(vector<vector<int>> &mat, int k) {
    using u64 = uint64_t;
    const auto [m, n] = make_pair(mat.size(), mat[0].size());
    string init_stat(m, 0);
    int init_sum = 0;
    unordered_set<string> vis;
    for (int i = 0; i < m; ++i)
      init_sum += mat[i][0];
    using pT = pair<int, string>;
    auto cmp = [](const auto &a, const auto &b) { return a.first > b.first; };
    vis.emplace(init_stat);
    priority_queue<pT, vector<pT>, function<bool(const pT &, const pT &)>> q(
        cmp);
    q.emplace(init_sum, init_stat);
    int ans;
    for (int i = 0; i < k; ++i) {
      const auto [sum, stat] = q.top();
//      cout << sum << "@" << i << ", " << stat.length() << endl;
      ans = sum;
      for (int j = 0; j < m; ++j) {
//        cout << "j=" << j << " " << stat.size() << endl;
        if (stat[j] < n - 1) {
          string tmp = stat;
          tmp[j]++;
          if (!vis.count(tmp))
//            cout << sum + mat[j][tmp[j]] - mat[j][stat[j]] << "#" << endl,
                vis.emplace(tmp),
                q.emplace(sum + mat[j][tmp[j]] - mat[j][stat[j]], tmp);
        }
      }
      q.pop();
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
