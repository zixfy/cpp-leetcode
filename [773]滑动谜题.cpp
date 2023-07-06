// 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0
// 来表示。一次 移动 定义为选择 0 与一个相邻的数字（ 上下左右）进行交换.
//
//  最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
//
//  给出一个谜板的初始状态 board
//  ，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：board = [[1,2,3],[4,0,5]]
// 输出：1
// 解释：交换 0 和 5 ，1 步完成
//
//
//  示例 2:
//
//
//
//
// 输入：board = [[1,2,3],[5,4,0]]
// 输出：-1
// 解释：没有办法完成谜板
//
//
//  示例 3:
//
//
//
//
// 输入：board = [[4,1,2],[5,0,3]]
// 输出：5
// 解释：
// 最少完成谜板的最少移动次数是 5 ，
// 一种移动路径:
// 尚未移动: [[4,1,2],[5,0,3]]
// 移动 1 次: [[4,1,2],[0,5,3]]
// 移动 2 次: [[0,1,2],[4,5,3]]
// 移动 3 次: [[1,0,2],[4,5,3]]
// 移动 4 次: [[1,2,0],[4,5,3]]
// 移动 5 次: [[1,2,3],[4,5,0]]
//
//
//
//
//  提示：
//
//
//  board.length == 2
//  board[i].length == 3
//  0 <= board[i][j] <= 5
//  board[i][j] 中每个值都 不同
//
//
//  Related Topics 广度优先搜索 数组 矩阵 👍 303 👎 0

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
  int slidingPuzzle(vector<vector<int>> &board) {

    array<int, 6> target{1, 2, 3, 4, 5, 0};
    array<int, 6> start;
    queue<tuple<int, array<int, 6>, int>> q;
    int i;
    for (i = 0; i < 6; i++)
      start[i] = board[i / 3][i % 3];
    for (i = 0; i < 6; i++)
      if (start[i] == 0)
        break;
    int ans = -1;
    q.emplace(i, start, 0);
    set<array<int, 6>> cnt{start};
    while (!q.empty()) {
      auto [idx, arr, dep] = q.front();
      if (arr == target) {
        ans = dep;
        break;
      }
      vector<int> nxt_idx;
      if (idx >= 3)
        nxt_idx.push_back(idx - 3);
      else
        nxt_idx.push_back(idx + 3);
      if (idx % 3)
        nxt_idx.push_back(idx - 1);
      if (idx % 3 < 2)
        nxt_idx.push_back(idx + 1);
      for (auto ndx : nxt_idx) {
        swap(arr[idx], arr[ndx]);
        if (!cnt.count(arr))
          cnt.insert(arr), q.emplace(ndx, arr, dep+1);

        swap(arr[idx], arr[ndx]);
      }
      q.pop();
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
