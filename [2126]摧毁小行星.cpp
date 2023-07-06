//给你一个整数 mass ，它表示一颗行星的初始质量。再给你一个整数数组 asteroids ，其中 asteroids[i] 是第 i 颗小行星的质量。 
//
// 你可以按 任意顺序 重新安排小行星的顺序，然后让行星跟它们发生碰撞。如果行星碰撞时的质量 大于等于 小行星的质量，那么小行星被 摧毁 ，并且行星会 获得 
//这颗小行星的质量。否则，行星将被摧毁。 
//
// 如果所有小行星 都 能被摧毁，请返回 true ，否则返回 false 。 
//
// 
//
// 示例 1： 
//
// 输入：mass = 10, asteroids = [3,9,19,5,21]
//输出：true
//解释：一种安排小行星的方式为 [9,19,5,3,21] ：
//- 行星与质量为 9 的小行星碰撞。新的行星质量为：10 + 9 = 19
//- 行星与质量为 19 的小行星碰撞。新的行星质量为：19 + 19 = 38
//- 行星与质量为 5 的小行星碰撞。新的行星质量为：38 + 5 = 43
//- 行星与质量为 3 的小行星碰撞。新的行星质量为：43 + 3 = 46
//- 行星与质量为 21 的小行星碰撞。新的行星质量为：46 + 21 = 67
//所有小行星都被摧毁。
// 
//
// 示例 2： 
//
// 输入：mass = 5, asteroids = [4,9,23,4]
//输出：false
//解释：
//行星无论如何没法获得足够质量去摧毁质量为 23 的小行星。
//行星把别的小行星摧毁后，质量为 5 + 4 + 9 + 4 = 22 。
//它比 23 小，所以无法摧毁最后一颗小行星。 
//
// 
//
// 提示： 
//
// 
// 1 <= mass <= 10⁵ 
// 1 <= asteroids.length <= 10⁵ 
// 1 <= asteroids[i] <= 10⁵ 
// 
//
// Related Topics 贪心 数组 排序 👍 18 👎 0


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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (auto a : asteroids) {
          if (m >= a)
            m += a;
          else return false;
          if (m >= asteroids.back())
            return true;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




