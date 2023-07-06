// 在 `n*m` 大小的棋盘中，有黑白两种棋子，黑棋记作字母 `"X"`, 白棋记作字母
// `"O"`，空余位置记作 `"."`。当落下的棋子与其他相同颜色的棋
// 子在行、列或对角线完全包围（中间不存在空白位置）另一种颜色的棋子，则可以翻转这些棋子的颜色。
//
//![1.gif](https://pic.leetcode-cn.com/1630396029-eTgzpN-6da662e67368466a96d203
// f67bb6e793.gif){:height=170px}![2.gif](https://pic.leetcode-cn.com/1630396240-
// nMvdcc-8e4261afe9f60e05a4f740694b439b6b.gif){:height=170px}![3.gif](https://pic.
// leetcode-cn.com/1630396291-kEtzLL-6fcb682daeecb5c3f56eb88b23c81d33.gif){:height=170
// px}
//
// 「力扣挑战赛」黑白翻转棋项目中，将提供给选手一个未形成可翻转棋子的棋盘残局，其状态记作
// `chessboard`。若下一步可放置一枚黑棋，请问选手最多能翻转 多少枚白棋。
//
//**注意：**
//- 若翻转白棋成黑棋后，棋盘上仍存在可以翻转的白棋，将可以 **继续** 翻转白棋
//- 输入数据保证初始棋盘状态无可以翻转的棋子且存在空余位置
//
//**示例 1：**
//
//> 输入：`chessboard = ["....X.","....X.","XOOO..","......","......"]`
//>
//> 输出：`3`
//>
//> 解释：
//> 可以选择下在 `[2,4]` 处，能够翻转白方三枚棋子。
//
//**示例 2：**
//
//> 输入：`chessboard = [".X.",".O.","XO."]`
//>
//> 输出：`2`
//>
//> 解释：
//> 可以选择下在 `[2,2]` 处，能够翻转白方两枚棋子。
//> ![2126c1d21b1b9a9924c639d449cc6e65.gif](https://pic.leetcode-cn.com/16266832
// 55-OBtBud-2126c1d21b1b9a9924c639d449cc6e65.gif)
//
//**示例 3：**
//
//> 输入：`chessboard =
//[".......",".......",".......","X......",".O.....","..O....
//","....OOX"]`
//>
//> 输出：`4`
//>
//> 解释：
//> 可以选择下在 `[6,3]` 处，能够翻转白方四枚棋子。
//> ![803f2f04098b6174397d6c696f54d709.gif](https://pic.leetcode-cn.com/16303937
// 70-Puyked-803f2f04098b6174397d6c696f54d709.gif)
//
//**提示：**
//- `1 <= chessboard.length, chessboard[i].length <= 8`
//- `chessboard[i]` 仅包含 `"."、"O"` 和 `"X"`
//
//  Related Topics 广度优先搜索 数组 矩阵 👍 16 👎 0

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

// leetcode submit region begin(Prohibit modification and deletion)

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
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
enum Dot : char { BLANK = '.', BLACK = 'X', WHITE = 'O' };
using xy = pair<int, int>;
constexpr auto dirs = []() -> array<xy, 8> {
  array<xy, 8> res;
  for (int i = -1, idx = 0; i < 2; ++i)
    for (int j = -1; j < 2; ++j)
      if (i || j)
        res[idx].first = i, res[idx++].second = j;
  return res;
}();
class Solution {
public:
  int flipChess(vector<string> &chessboard) {
    int ans = 0;
    const auto m = chessboard.size(), n = chessboard[0].length();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (chessboard[i][j] == Dot::BLANK) {
          auto tmp = chessboard;
          auto cnt = 0;
          queue<xy> q;
          q.emplace(i, j);
          tmp[i][j] = Dot::BLACK;

          while (!q.empty()) {
            auto [ci, cj] = q.front();
            for (const auto [di, dj] : dirs)
              for (auto ni = ci + di, nj = cj + dj;
                   ni > -1 && ni < m && nj > -1 && nj < n; ni += di, nj += dj) {
                if (tmp[ni][nj] == Dot::BLANK)
                  break;
                else if (tmp[ni][nj] == Dot::BLACK) {
                  for (auto ti = ci + di, tj = cj + dj; ti != ni || tj != nj;
                       ti += di, tj += dj) {
                    q.emplace(ti, tj);

                    tmp[ti][tj] = Dot::BLACK;
                    ++cnt;
                  }
                  break;
                }
              }
            q.pop();
          }
          ans = max(ans, cnt);
        }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
