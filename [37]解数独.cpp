// 编写一个程序，通过填充空格来解决数独问题。
//
//  数独的解法需 遵循如下规则：
//
//
//  数字 1-9 在每一行只能出现一次。
//  数字 1-9 在每一列只能出现一次。
//  数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//
//
//  数独部分空格内已填入了数字，空白格用 '.' 表示。
//
//
//
//
//
//
//  示例 1：
//
//
// 输入：board =
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".
//",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".
//","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6
//"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[
//".",".",".",".","8",".",".","7","9"]]
// 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8
//"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],[
//"4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9",
//"6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4",
//"5","2","8","6","1","7","9"]]
// 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
//
//
//
//
//
//
//
//
//
//  提示：
//
//
//  board.length == 9
//  board[i].length == 9
//  board[i][j] 是一位数字或者 '.'
//  题目数据 保证 输入数独仅有一个解
//
//
//  Related Topics 数组 哈希表 回溯 矩阵 👍 1611 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << " " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v);

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
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
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    array<int, 9 * 9> row_stat{}, col_stat{}, palace_stat{};
    auto fill_a_num = [&](int i, int j) {
      int n = board[i][j] - '0';
      if (n == 0)
        return false;
      if (row_stat[i * 9 + n - 1] || col_stat[j * 9 + n - 1] ||
          palace_stat[(i / 3 * 3 + j / 3) * 9 + n - 1])
        return false;
      row_stat[i * 9 + n - 1] = col_stat[j * 9 + n - 1] =
          palace_stat[(i / 3 * 3 + j / 3) * 9 + n - 1] = 1;
      return true;
    };
    vector<pair<int, int>> blk_pos;
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.')
          fill_a_num(i, j);
        else
          board[i][j] = '0', blk_pos.emplace_back(i, j);
      }
//    cout << blk_pos << endl;
    auto del_a_num = [&](int i, int j) {
      int n = board[i][j] - '0';
      if (n == 0)
        return;
      row_stat[i * 9 + n - 1] = col_stat[j * 9 + n - 1] =
          palace_stat[(i / 3 * 3 + j / 3) * 9 + n - 1] = 0;
    };
    int idx = 0;
    while (idx < blk_pos.size()) {
      const auto [x, y] = blk_pos[idx];
      del_a_num(x, y);
      while (++board[x][y] <= '9' && fill_a_num(x, y) == false)
        ;
      if (board[x][y] > '9') {
        board[x][y] = '0', --idx;
        continue ;
      }
      ++idx;
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
