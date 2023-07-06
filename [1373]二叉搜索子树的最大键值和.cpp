// 给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。
//
//  二叉搜索树的定义如下：
//
//
//  任意节点的左子树中的键值都 小于 此节点的键值。
//  任意节点的右子树中的键值都 大于 此节点的键值。
//  任意节点的左子树和右子树都是二叉搜索树。
//
//
//
//
//  示例 1：
//
//
//
//
// 输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// 输出：20
// 解释：键值为 3 的子树是和最大的二叉搜索树。
//
//
//  示例 2：
//
//
//
//
// 输入：root = [4,3,null,1,2]
// 输出：2
// 解释：键值为 2 的单节点子树是和最大的二叉搜索树。
//
//
//  示例 3：
//
//
// 输入：root = [-4,-2,-5]
// 输出：0
// 解释：所有节点键值都为负数，和最大的二叉搜索树为空。
//
//
//  示例 4：
//
//
// 输入：root = [2,1,3]
// 输出：6
//
//
//  示例 5：
//
//
// 输入：root = [5,4,8,3,null,6,3]
// 输出：7
//
//
//
//
//  提示：
//
//
//  每棵树有 1 到 40000 个节点。
//  每个节点的键值在 [-4 * 10^4 , 4 * 10^4] 之间。
//
//
//  Related Topics 树 深度优先搜索 二叉搜索树 动态规划 二叉树 👍 146 👎 0

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
  int maxSumBST(TreeNode *root) {
    using stat = tuple<int, int, int, bool>;
    // [min, max, sum]
    int ans = 0;
    function<stat(TreeNode *)> dfs = [&](TreeNode *cur) -> stat {
      if (cur == nullptr)
        return {numeric_limits<int>::max(), numeric_limits<int>::min(), 0, true};
      auto [min1, max1, sum1, okay1] = dfs(cur->left);
      auto [min2, max2, sum2, okay2] = dfs(cur->right);
      auto okay = okay1 && okay2 && cur->val > max1 && cur->val < min2;
      auto sum = sum1 + sum2 + cur->val;
      if (okay)
        ans = max(ans, sum);
      return {min(cur->val, min(min1, min2)), max(cur->val, max(max1, max2)),
              sum, okay};
    };
    dfs(root);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
