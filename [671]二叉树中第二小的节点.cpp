// 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2
// 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一
// 个。
//
//  更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。
//
//  给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。
//
//  如果第二小的值不存在的话，输出 -1 。
//
//
//
//  示例 1：
//
//
// 输入：root = [2,2,5,null,null,5,7]
// 输出：5
// 解释：最小的值是 2 ，第二小的值是 5 。
//
//
//  示例 2：
//
//
// 输入：root = [2,2,2]
// 输出：-1
// 解释：最小的值是 2, 但是不存在第二小的值。
//
//
//
//
//  提示：
//
//
//  树中节点数目在范围 [1, 25] 内
//  1 <= Node.val <= 2³¹ - 1
//  对于树中每个节点 root.val == min(root.left.val, root.right.val)
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 294 👎 0

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
  int findSecondMinimumValue(TreeNode *root) {
    long long min1 = numeric_limits<long long>::max();
    long long min2 = min1;
    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      if (cur->left == nullptr && cur->right == nullptr) {
//        cout << min1 << ", " << min2 << ", " << cur->val << endl;
        if (cur->val < min1)
          min2 = min1, min1 = cur->val;
        else if (cur->val > min1 && cur->val < min2)
          min2 = cur->val;
      } else
        dfs(cur->left), dfs(cur->right);
    };
    dfs(root);
    return min2 < numeric_limits<long long>::max() ? min2 : -1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
