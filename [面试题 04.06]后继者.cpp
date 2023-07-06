// 设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
//
//  如果指定节点没有对应的“下一个”节点，则返回null。
//
//  示例 1:
//
//  输入: root = [2,1,3], p = 1
//
//   2
//   / \
//1   3
//
// 输出: 2
//
//  示例 2:
//
//  输入: root = [5,3,6,2,4,null,null,1], p = 6
//
//       5
//       / \
//    3   6
//     / \
//  2   4
//  /
// 1
//
// 输出: null
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 221 👎 0
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
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
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    decltype(p) ans{};
    stack<decltype(p)> stk{{root}};
    bool got_p{};
    while (!stk.empty()) {
      const auto &cur = stk.top();
      if (cur->left) {
        stk.push(cur->left);
        cur->left = nullptr;
        continue;
      }
      stk.pop();
      if (got_p)
        return cur;
      if (cur == p)
        got_p = true;
      if (cur->right)
        stk.push(cur->right);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
