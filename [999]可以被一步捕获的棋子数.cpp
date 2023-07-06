// 在一个 8 x 8 的棋盘上，有一个白色的车（Rook），用字符 'R'
// 表示。棋盘上还可能存在空方块，白色的象（Bishop）以及黑色的卒（pawn），分
// 别用字符 '.'，'B' 和 'p'
// 表示。不难看出，大写字符表示的是白棋，小写字符表示的是黑棋。
//
//  车按国际象棋中的规则移动。东，西，南，北四个基本方向任选其一，然后一直向选定的方向移动，直到满足下列四个条件之一：
//
//
//  棋手选择主动停下来。
//  棋子因到达棋盘的边缘而停下。
//  棋子移动到某一方格来捕获位于该方格上敌方（黑色）的卒，停在该方格内。
//  车不能进入/越过已经放有其他友方棋子（白色的象）的方格，停在友方棋子前。
//
//
//  你现在可以控制车移动一次，请你统计有多少敌方的卒处于你的捕获范围内（即，可以被一步捕获的棋子数）。
//
//
//
//  示例 1：
//
//
//
//  输入：[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",
//".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",
//".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".",
//"."],[".",".",".",".",".",".",".","."]]
// 输出：3
// 解释：
// 在本例中，车能够捕获所有的卒。
//
//
//  示例 2：
//
//
//
//  输入：[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".",
//"p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B",
//"p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".",
//"."],[".",".",".",".",".",".",".","."]]
// 输出：0
// 解释：
// 象阻止了车捕获任何卒。
//
//
//  示例 3：
//
//
//
//  输入：[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",
//".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",
//".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".",
//"."],[".",".",".",".",".",".",".","."]]
// 输出：3
// 解释：
// 车可以捕获位置 b5，d6 和 f5 的卒。
//
//
//
//
//  提示：
//
//
//  board.length == board[i].length == 8
//  board[i][j] 可以是 'R'，'.'，'B' 或 'p'
//  只有一个格子上存在 board[i][j] == 'R'
//
//
//  Related Topics 数组 矩阵 模拟 👍 110 👎 0

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
  int numRookCaptures(vector<vector<char>> &board) {
    const auto [m, n] = make_pair(board.size(), board[0].size());
    int x, y;
    for (x = 0, y = 0; board[x][y] != 'R';)
      if (++y == n)
        y = 0, ++x;
//    cout << x << ", " << y << endl;
    int ans = 0;
    auto dy = y - 1;
    while (dy >= 0) {
      if (board[x][dy] == '.')
        dy--;
      else {
        if (board[x][dy] == 'p')
          ++ans;
        break;
      }
    }

    dy = y + 1;
    while (dy < n) {
      if (board[x][dy] == '.')
        dy++;
      else {
        if (board[x][dy] == 'p')
          ++ans;
        break;
      }
    }

    auto dx = x - 1;
    while (dx >= 0) {
      if (board[dx][y] == '.')
        dx--;
      else {
        if (board[dx][y] == 'p')
          ++ans;
        break;
      }
    }

    dx = x + 1;
    while (dx < m) {
      if (board[dx][y] == '.')
        dx++;
      else {
        if (board[dx][y] == 'p')
          ++ans;
        break;
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
