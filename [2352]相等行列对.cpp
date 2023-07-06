// 给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj
// 列相等的行列对 (Ri, Cj) 的数目。
//
//  如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
//
//
//
//  示例 1：
//
//
//
//
// 输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
// 输出：1
// 解释：存在一对相等行列对：
//- (第 2 行，第 1 列)：[2,7,7]
//
//
//  示例 2：
//
//
//
//
// 输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// 输出：3
// 解释：存在三对相等行列对：
//- (第 0 行，第 0 列)：[3,1,2,2]
//- (第 2 行, 第 2 列)：[2,4,2,2]
//- (第 3 行, 第 2 列)：[2,4,2,2]
//
//
//
//
//  提示：
//
//
//  n == grid.length == grid[i].length
//  1 <= n <= 200
//  1 <= grid[i][j] <= 10⁵
//
//
//  Related Topics 数组 哈希表 矩阵 模拟 👍 52 👎 0

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

// leetcode submit region begin(Prohibit modification and deletion)
template <class T> inline void hash_combine(std::size_t &seed, T const &v);
namespace std {
template <typename T> struct hash<vector<T>> {
  typedef vector<T> argument_type;
  typedef std::size_t result_type;
  result_type operator()(argument_type const &in) const {
    size_t size = in.size();
    size_t seed = 0;
    for (size_t i = 0; i < size; i++)
      // Combine the hash of the current vector with the hashes of the previous
      // ones
      hash_combine(seed, in[i]);
    return seed;
  }
};
} // namespace std
// using boost::hash_combine
template <class T> inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    unordered_map<vector<int>, int> q1, q2;
    for (const auto &row : grid)
      q1[row]++;
    const auto n = grid.size();
    for (auto i = 0; i < n; ++i) {
      vector<int> tmp;
      tmp.reserve(n);
      for (auto j = 0; j < n; ++j)
        tmp.emplace_back(grid[j][i]);
      q2[tmp]++;
    }
    int ans = 0;
    for (const auto &[k, v] : q1)
      ans += v * q2[k];
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
