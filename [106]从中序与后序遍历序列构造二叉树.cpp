// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
// postorder 是同一棵树的后序遍历，请你构造并 返回这颗 二叉树 。
//
//
//
//  示例 1:
//
//
// 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// 输出：[3,9,20,null,null,15,7]
//
//
//  示例 2:
//
//
// 输入：inorder = [-1], postorder = [-1]
// 输出：[-1]
//
//
//
//
//  提示:
//
//
//  1 <= inorder.length <= 3000
//  postorder.length == inorder.length
//  -3000 <= inorder[i], postorder[i] <= 3000
//  inorder 和 postorder 都由 不同 的值组成
//  postorder 中每一个值都在 inorder 中
//  inorder 保证是树的中序遍历
//  postorder 保证是树的后序遍历
//
//
//  Related Topics 树 数组 哈希表 分治 二叉树 👍 1015 👎 0

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
private:
  static TreeNode *_ctor(vector<int> &inorder, int l1, int r1,
                         vector<int> &postorder, int l2, int r2) {
    if (l1 > r1)
      return nullptr;
    auto r = new TreeNode(postorder[r2]);
    if (l2 == r2)
      return r;
    int sep = l1;
    while (inorder[sep] != r->val)
      ++sep;
    r->left = _ctor(inorder, l1, sep - 1, postorder, l2, sep - 1 + l2 - l1);
    r->right = _ctor(inorder, sep + 1, r1, postorder, sep + r2 - r1, r2 - 1);
    return r;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return _ctor(inorder, 0, inorder.size() - 1, postorder, 0,
                 postorder.size() - 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
