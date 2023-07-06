// 给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。
//
//  每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0]
//  与 arr[1] 的大小，较大的整数将会取得这一回合的
// 胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k
// 个连续回合时，游戏结束，该整数就是比赛的 赢家 。
//
//  返回赢得比赛的整数。
//
//  题目数据 保证 游戏存在赢家。
//
//
//
//  示例 1：
//
//  输入：arr = [2,1,3,5,4,6,7], k = 2
// 输出：5
// 解释：一起看一下本场游戏每回合的情况：
//
// 因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。
//
//
//  示例 2：
//
//  输入：arr = [3,2,1], k = 10
// 输出：3
// 解释：3 将会在前 10 个回合中连续获胜。
//
//
//  示例 3：
//
//  输入：arr = [1,9,8,2,3,7,6,4,5], k = 7
// 输出：9
//
//
//  示例 4：
//
//  输入：arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
// 输出：99
//
//
//
//
//  提示：
//
//
//  2 <= arr.length <= 10^5
//  1 <= arr[i] <= 10^6
//  arr 所含的整数 各不相同 。
//  1 <= k <= 10^9
//
//
//  Related Topics 数组 模拟 👍 47 👎 0

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
  int getWinner(vector<int> &arr, int k) {
    if (k >= arr.size())
      return *std::max_element(arr.begin(), arr.end());
    int cnt = 0;
    int ans = 0;
    deque q(arr.begin(), arr.end());
    while (true) {
      auto a1 = q.front(), a2 = q[1];
      auto am = max(a1, a2);
      if (a1 == am) {
        q.erase(q.begin() + 1);
        q.emplace_back(a2);
      } else {
        q.emplace_back(a1);
        q.pop_front();
      }
      if (am == ans)
        ++cnt;
      else
        ans = am, cnt = 1;
      if (cnt == k)
        break;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
