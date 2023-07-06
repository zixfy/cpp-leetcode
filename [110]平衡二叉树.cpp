// 给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//  本题中，一棵高度平衡二叉树定义为：
//
//
//  一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//
//
//
//  示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：true
//
//
//  示例 2：
//
//
// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false
//
//
//  示例 3：
//
//
// 输入：root = []
// 输出：true
//
//
//
//
//  提示：
//
//
//  树中的节点数在范围 [0, 5000] 内
//  -10⁴ <= Node.val <= 10⁴
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 1317 👎 0
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;
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
  bool isBalanced(TreeNode *root) {
    function<pair<bool, int>(TreeNode *)> dfs = [&](TreeNode *cur) -> pair<bool, int>{
        if (cur == nullptr)
          return {true, 0};
        auto [b1, h1] = dfs(cur -> left);
        auto [b2, h2] = dfs(cur -> right);
        return {b1 && b2 && abs(h1 - h2) < 2, max(h1 , h2) + 1};
    };
    return dfs(root).first;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
