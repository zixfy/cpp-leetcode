// 给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵
// grid 。
//
//  你需要返回能表示矩阵的 四叉树 的根结点。
//
//  注意，当 isLeaf 为 False 时，你可以把 True 或者 False
//  赋值给节点，两种值都会被判题机制 接受 。
//
//  四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：
//
//
//  val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False；
//  isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
//
//
//  class Node {
//     public boolean val;
//     public boolean isLeaf;
//     public Node topLeft;
//     public Node topRight;
//     public Node bottomLeft;
//     public Node bottomRight;
// }
//
//  我们可以按以下步骤为二维区域构建四叉树：
//
//
//  如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val
//  设为网格相应的值，并将四个子节点都设为 Null 然后
// 停止。
//  如果当前网格的值不同，将 isLeaf 设为 False， 将 val
//  设为任意值，然后如下图所示，将当前网格划分为四个子网格。
//  使用适当的子网格递归每个子节点。
//
//
//
//
//  如果你想了解更多关于四叉树的内容，可以参考 wiki 。
//
//  四叉树格式：
//
//  输出为使用层序遍历后四叉树的序列化形式，其中 null
//  表示路径终止符，其下面不存在节点。
//
//  它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 [isLeaf, val] 。
//
//  如果 isLeaf 或者 val 的值为 True ，则表示它在列表 [isLeaf, val] 中的值为 1
//  ；如果 isLeaf 或者 val 的值为 False ，则表示值为 0 。
//
//
//
//  示例 1：
//
//
//
//  输入：grid = [[0,1],[1,0]]
// 输出：[[0,1],[1,0],[1,1],[1,1],[1,0]]
// 解释：此示例的解释如下：
// 请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。
//
//
//
//  示例 2：
//
//
//
//  输入：grid =
//  [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1
//,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
// 输出：[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
//
// 解释：网格中的所有值都不相同。我们将网格划分为四个子网格。
// topLeft，bottomLeft 和 bottomRight 均具有相同的值。
// topRight 具有不同的值，因此我们将其再分为 4
// 个子网格，这样每个子网格都具有相同的值。 解释如下图所示：
//
//
//
//  示例 3：
//
//  输入：grid = [[1,1],[1,1]]
// 输出：[[1,1]]
//
//
//  示例 4：
//
//  输入：grid = [[0]]
// 输出：[[1,0]]
//
//
//  示例 5：
//
//  输入：grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
// 输出：[[0,1],[1,1],[1,0],[1,0],[1,1]]
//
//
//
//
//  提示：
//
//
//  n == grid.length == grid[i].length
//  n == 2^x 其中 0 <= x <= 6
//
//
//  Related Topics 树 数组 分治 矩阵 👍 181 👎 0
#include "bits/stdc++.h"
using namespace std;

class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

// leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/
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
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
template <typename T> class PrefixView2D {
public:
  PrefixView2D() = delete;
  explicit PrefixView2D(const std::vector<std::vector<T>> &mat) : _prefix(mat) {
    const auto m = _prefix.size(), n = _prefix[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        _prefix[i][j] += _get(i, j - 1) + _get(i - 1, j) - _get(i - 1, j - 1);
//    cout << _prefix << endl;
  }
  T get_area_sum(int i1, int j1, int i2, int j2) const {
    return _get(i2, j2) + _get(i1 - 1, j1 - 1) - _get(i1 - 1, j2) -
           _get(i2, j1 - 1);
  }

private:
  inline T _get(int i, int j) const {
    if (i < 0 || j < 0)
      return T();
    return _prefix[i][j];
  }
  std::vector<std::vector<T>> _prefix;
};
class Solution {
private:
  Node *_ctor(int i1, int j1, int i2, int j2, const PrefixView2D<int> &g) {
    //    cout << make_tuple(i1, j1, i2, j2) << endl;

    if (i1 == i2)
      return new Node(bool(g.get_area_sum(i1, j1, i1, j1)), true);
    auto sumy = g.get_area_sum(i1, j1, i2, j2);
//    cout << make_tuple(i1, j1, i2, j2) <<  sumy << endl;
    if (sumy == 0)
      return new Node(false, true);
    if (sumy == (i2 - i1 + 1) * (j2 - j1 + 1))
      return new Node(true, true);
    auto r = new Node(true, false);
    r->topLeft = _ctor(i1, j1, (i1 + i2) >> 1, (j1 + j2) >> 1, g);
    r->topRight = _ctor(i1, ((j1 + j2) >> 1) + 1, (i1 + i2) >> 1, j2, g);
    r->bottomLeft = _ctor(((i1 + i2) >> 1) + 1, j1, i2, (j1 + j2) >> 1, g);
    r->bottomRight =
        _ctor(((i1 + i2) >> 1) + 1, ((j1 + j2) >> 1) + 1, i2, j2, g);
    return r;
  }

public:
  Node *construct(vector<vector<int>> &grid) {
    auto n = grid.size();
    auto pre = PrefixView2D(grid);

    return _ctor(0, 0, n - 1, n - 1, pre);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
