// 给你一个整数数组 cards ，其中 cards[i] 表示第 i 张卡牌的 值
// 。如果两张卡牌的值相同，则认为这一对卡牌 匹配 。
//
//  返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。如果无法得到一对匹配的卡牌，返回
//  -1 。
//
//
//
//  示例 1：
//
//  输入：cards = [3,4,2,3,4,7]
// 输出：4
// 解释：拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4]
// 也是最优方案。
//
//  示例 2：
//
//  输入：cards = [1,0,5,3]
// 输出：-1
// 解释：无法找出含一对匹配卡牌的一组连续卡牌。
//
//
//
//  提示：
//
//
//  1 <= cards.length <= 10⁵
//  0 <= cards[i] <= 10⁶
//
//
//  Related Topics 数组 哈希表 滑动窗口 👍 16 👎 0

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
  int minimumCardPickup(vector<int> &cards) {
    const auto n = cards.size();
    int l = 0, r = 0;
    unordered_map<int, int> cnt;
    int ans = numeric_limits<int>::max();
    int okay_cnt = 0;
    for (; r < n; ++r) {
      if (++cnt[cards[r]] == 2)
        okay_cnt++;
      bool okay = okay_cnt >= 1;
      while (l <= r && okay_cnt >= 1) {
        if (--cnt[cards[l++]] == 1)
          okay_cnt--;
      }

      if (okay)
//        cout << l << ", " << r << endl,
        ans = min(r - l + 2, ans);
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
