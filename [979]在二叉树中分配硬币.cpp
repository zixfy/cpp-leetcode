// 给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val
// 枚硬币，并且总共有 N 枚硬币。
//
//  在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。
//
//  返回使每个结点上只有一枚硬币所需的移动次数。
//
//
//
//  示例 1：
//
//
//
//  输入：[3,0,0]
// 输出：2
// 解释：从树的根结点开始，我们将一枚硬币移到它的左子结点上，一枚硬币移到它的右子结点上。
//
//
//  示例 2：
//
//
//
//  输入：[0,3,0]
// 输出：3
// 解释：从根结点的左子结点开始，我们将两枚硬币移到根结点上
// [移动两次]。然后，我们把一枚硬币从根结点移到右子结点上。
//
//
//  示例 3：
//
//
//
//  输入：[1,0,2]
// 输出：2
//
//
//  示例 4：
//
//
//
//  输入：[1,0,0,null,3]
// 输出：4
//
//
//
//
//  提示：
//
//
//  1<= N <= 100
//  0 <= node.val <= N
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 360 👎 0

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
  int distributeCoins(TreeNode *root) {
    using pT = TreeNode *;
    using xy = pair<int, int>;
    int ans = 0;
    function<xy(pT)> dfs = [&](pT cur) -> xy {
      if (cur == nullptr)
        return {0, 0};
      auto [s1, v1] = dfs(cur->left);
      auto [s2, v2] = dfs(cur->right);
      ans += abs(s1 - v1) + abs(s2 - v2);
      return {1 + s1 + s2, v1 + v2 + cur->val};
    };
    dfs(root);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
