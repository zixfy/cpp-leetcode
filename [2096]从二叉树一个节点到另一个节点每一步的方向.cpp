// 给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1
// 到 n 中的一个整数，且互不相同。给你一个整数 startValue ，表示起点节点 s
// 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。
//
//  请找到从节点 s 到节点 t 的 最短路径
//  ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U'
//  分别表示一种方向：
//
//
//  'L' 表示从一个节点前往它的 左孩子 节点。
//  'R' 表示从一个节点前往它的 右孩子 节点。
//  'U' 表示从一个节点前往它的 父 节点。
//
//
//  请你返回从 s 到 t 最短路径 每一步的方向。
//
//
//
//  示例 1：
//
//
//
//  输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// 输出："UURL"
// 解释：最短路径为：3 → 1 → 5 → 2 → 6 。
//
//
//  示例 2：
//
//
//
//  输入：root = [2,1], startValue = 2, destValue = 1
// 输出："L"
// 解释：最短路径为：2 → 1 。
//
//
//
//
//  提示：
//
//
//  树中节点数目为 n 。
//  2 <= n <= 10⁵
//  1 <= Node.val <= n
//  树中所有节点的值 互不相同 。
//  1 <= startValue, destValue <= n
//  startValue != destValue
//
//
//  Related Topics 树 深度优先搜索 字符串 二叉树 👍 60 👎 0

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  string getDirections(TreeNode *root, int startValue, int destValue) {

  }
};
// leetcode submit region end(Prohibit modification and deletion)
