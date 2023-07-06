// 从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。
//
//  给定一个由不同节点组成的二叉搜索树 root，输出所有可能生成此树的数组。
//
//
//
//  示例 1:
//
//
// 输入: root = [2,1,3]
// 输出: [[2,1,3],[2,3,1]]
// 解释: 数组 [2,1,3]、[2,3,1]
// 均可以通过从左向右遍历元素插入树中形成以下二叉搜索树        2
//                 / \
//     1   3
//
//
//
//
//
//  示例 2:
//
//
// 输入: root = [4,1,null,null,3,2]
// 输出: [[4,1,3,2]]
//
//
//
//
//  提示：
//
//
//  二叉搜索树中的节点数在
//  [0, 1000] 的范围内
//  1 <= 节点值 <= 10^6
//  用例保证符合要求的数组数量不超过 5000
//
//
//  Related Topics 树 二叉搜索树 回溯 二叉树 👍 111 👎 0

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  auto BSTSequences(TreeNode *root) {
    function<vector<vector<int>>(TreeNode *)> dfs =
        [&](TreeNode *cur) -> vector<vector<int>> {
      if (cur == nullptr)
        return {{}};
      vector<vector<int>> ret;
      auto &&lef = dfs(cur->left), &&rig = dfs(cur->right);

      auto tmp = vector{cur->val};
      function<void(const vector<int> &, const vector<int> &, int, int)> dfs2 =
          [&](const auto &l, const auto &r, int i, int j) {
            if (i == l.size()) {
              if (j == r.size())
                ret.emplace_back(tmp);
            }
            else {
              tmp.push_back(l[i]);
              dfs2(l, r, i + 1, j);
              tmp.pop_back();
            }
            if (j < r.size()) {
              tmp.push_back(r[j]);
              dfs2(l, r, i, j + 1);
              tmp.pop_back();
            }
          };
      for (const auto &l : lef)
        for (const auto &r : rig)
          dfs2(l, r, 0, 0);
      return ret;
    };
    return dfs(root);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
