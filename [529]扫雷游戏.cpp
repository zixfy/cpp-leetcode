// 让我们一起来玩扫雷游戏！
//
//  给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
//
//
//  'M' 代表一个 未挖出的 地雷，
//  'E' 代表一个 未挖出的 空方块，
//  'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的
//  空白方块， 数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻， 'X'
//  则表示一个 已挖出的 地雷。
//
//
//  给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的
//  方块（'M' 或者 'E'）中的下一个点击位
// 置（clickr 是行下标，clickc 是列下标）。
//
//  根据以下规则，返回相应位置被点击后对应的盘面：
//
//
//  如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
//  如果一个 没有相邻地雷
//  的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出
//  方块都应该被递归地揭露。 如果一个 至少与一个地雷相邻
//  的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
//  如果在此次点击中，若无更多方块可被揭露，则返回盘面。
//
//
//
//
//  示例 1：
//
//
// 输入：board =
// [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],
//["E","E","E","E","E"]], click = [3,0]
// 输出：[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B",
//"B","B","B","B"]]
//
//
//  示例 2：
//
//
// 输入：board =
// [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],
//["B","B","B","B","B"]], click = [1,2]
// 输出：[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B",
//"B","B","B","B"]]
//
//
//
//
//  提示：
//
//
//  m == board.length
//  n == board[i].length
//  1 <= m, n <= 50
//  board[i][j] 为 'M'、'E'、'B' 或数字 '1' 到 '8' 中的一个
//  click.length == 2
//  0 <= clickr < m
//  0 <= clickc < n
//  board[clickr][clickc] 为 'M' 或 'E'
//
//
//  Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 336 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
constexpr auto UNDER_MINE{'M'}, UNDER_BLK{'E'}, BLK{'B'};
constexpr auto dirs() {
  array<pair<int, int>, 8> ans;
  for (int i = -1, idx{}; i < 2; ++i)
    for (int j = -1; j < 2; ++j)
      if (i || j)
        ans[idx++] = make_pair(i, j);
  return ans;
}
constexpr auto dirs2() {
  return array<pair<int, int>, 4> {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
}
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << " " << p.second << ")";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "[";
  for (const auto& a: v)
    cout << a << ", " ;
  return o << "]";
}

class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
//    cout << dirs() << endl;
    const auto [x, y] = make_pair(click[0], click[1]);
    auto get_adj_mines_num = [&board](int x, int y) {
      int r{};
      for (const auto d : dirs()) {
        int nx{x + d.first}, ny{y + d.second};
        if (nx > -1 && nx < board.size() && ny > -1 && ny < board[0].size())
          r += board[nx][ny] == UNDER_MINE;
      }
      return r;
    };
    //cout << x << " " << y << endl;
    if (board[x][y] == UNDER_MINE) {
      board[x][y] = 'X';
      return board;
    }
    queue<pair<int, int>> q;
    q.emplace(x, y);
    while (!q.empty()) {
      const auto [x, y] = q.front();
      if (board[x][y] != UNDER_BLK) {
        q.pop();
        continue ;
      }
      auto n{get_adj_mines_num(x, y)};
      if (n == 0) {
        board[x][y] = BLK;
        for (const auto d : dirs()) {
          int nx{x + d.first}, ny{y + d.second};
          if (nx > -1 && nx < board.size() && ny > -1 && ny < board[0].size() && board[nx][ny] == UNDER_BLK) {
            q.emplace(nx, ny);
          }

        }
      }
      else {
        board[x][y] = '0' + n;
      }
      q.pop();
    }
//    cout << get_adj_mines_num(x, y);
    return board;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
