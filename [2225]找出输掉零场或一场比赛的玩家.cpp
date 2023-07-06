// 给你一个整数数组 matches 其中 matches[i] = [winneri, loseri] 表示在一场比赛中
// winneri 击败了 loseri 。
//
//  返回一个长度为 2 的列表 answer ：
//
//
//  answer[0] 是所有 没有 输掉任何比赛的玩家列表。
//  answer[1] 是所有恰好输掉 一场 比赛的玩家列表。
//
//
//  两个列表中的值都应该按 递增 顺序返回。
//
//  注意：
//
//
//  只考虑那些参与 至少一场 比赛的玩家。
//  生成的测试用例保证 不存在 两场比赛结果 相同 。
//
//
//
//
//  示例 1：
//
//
// 输入：matches =
// [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// 输出：[[1,2,10],[4,5,7,8]]
// 解释：
// 玩家 1、2 和 10 都没有输掉任何比赛。
// 玩家 4、5、7 和 8 每个都输掉一场比赛。
// 玩家 3、6 和 9 每个都输掉两场比赛。
// 因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。
//
//
//  示例 2：
//
//
// 输入：matches = [[2,3],[1,3],[5,4],[6,4]]
// 输出：[[1,2,5,6],[]]
// 解释：
// 玩家 1、2、5 和 6 都没有输掉任何比赛。
// 玩家 3 和 4 每个都输掉两场比赛。
// 因此，answer[0] = [1,2,5,6] 和 answer[1] = [] 。
//
//
//
//
//  提示：
//
//
//  1 <= matches.length <= 10⁵
//  matches[i].length == 2
//  1 <= winneri, loseri <= 10⁵
//  winneri != loseri
//  所有 matches[i] 互不相同
//
//
//  Related Topics 数组 哈希表 计数 排序 👍 13 👎 0

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
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    map<int, int> cnt;
    for (const auto& m: matches) {
      cnt[m[1]]++;
      cnt.operator[](m[0]);
    }
    vector ans(2, vector<int>{});
    for (const auto[k, v]: cnt) {
      if (v == 0)
        ans[0].push_back(k);
      else if (v == 1)
        ans[1].push_back(k);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
