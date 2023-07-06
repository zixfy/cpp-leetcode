//给你一个下标从 0 开始长度为 n 的整数数组 stations ，其中 stations[i] 表示第 i 座城市的供电站数目。 
//
// 每个供电站可以在一定 范围 内给所有城市提供电力。换句话说，如果给定的范围是 r ，在城市 i 处的供电站可以给所有满足 |i - j| <= r 且 0
// <= i, j <= n - 1 的城市 j 供电。 
//
// 
// |x| 表示 x 的 绝对值 。比方说，|7 - 5| = 2 ，|3 - 10| = 7 。 
// 
//
// 一座城市的 电量 是所有能给它供电的供电站数目。 
//
// 政府批准了可以额外建造 k 座供电站，你需要决定这些供电站分别应该建在哪里，这些供电站与已经存在的供电站有相同的供电范围。 
//
// 给你两个整数 r 和 k ，如果以最优策略建造额外的发电站，返回所有城市中，最小供电站数目的最大值是多少。 
//
// 这 k 座供电站可以建在多个城市。 
//
// 
//
// 示例 1： 
//
// 
//输入：stations = [1,2,4,5,0], r = 1, k = 2
//输出：5
//解释：
//最优方案之一是把 2 座供电站都建在城市 1 。
//每座城市的供电站数目分别为 [1,4,4,5,0] 。
//- 城市 0 的供电站数目为 1 + 4 = 5 。
//- 城市 1 的供电站数目为 1 + 4 + 4 = 9 。
//- 城市 2 的供电站数目为 4 + 4 + 5 = 13 。
//- 城市 3 的供电站数目为 5 + 4 = 9 。
//- 城市 4 的供电站数目为 5 + 0 = 5 。
//供电站数目最少是 5 。
//无法得到更优解，所以我们返回 5 。
// 
//
// 示例 2： 
//
// 
//输入：stations = [4,4,4,4], r = 0, k = 3
//输出：4
//解释：
//无论如何安排，总有一座城市的供电站数目是 4 ，所以最优解是 4 。
// 
//
// 
//
// 提示： 
//
// 
// n == stations.length 
// 1 <= n <= 10⁵ 
// 0 <= stations[i] <= 10⁵ 
// 0 <= r <= n - 1 
// 0 <= k <= 10⁹ 
// 
//
// Related Topics 贪心 队列 数组 二分查找 前缀和 滑动窗口 👍 27 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




