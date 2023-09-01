// 给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth
// 处添加一个值为 val 的节点行。
//
//  注意，根节点 root 位于深度 1 。
//
//  加法规则如下:
//
//
//  给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val
//  的树节点作为 cur 的左子树根和右子树根。 cur
//  原来的左子树应该是新的左子树根的左子树。 cur
//  原来的右子树应该是新的右子树根的右子树。 如果 depth == 1 意味着 depth - 1
//  根本没有深度，那么创建一个树节点，值 val
//  作为整个原始树的新根，而原始树就是新根的左子树。
//
//
//
//
//  示例 1:
//
//
//
//
// 输入: root = [4,2,6,3,1,5], val = 1, depth = 2
// 输出: [4,1,1,2,null,null,6,3,1,5]
//
//  示例 2:
//
//
//
//
// 输入: root = [4,2,null,3,1], val = 1, depth = 3
// 输出:  [4,2,null,1,1,3,null,null,1]
//
//
//
//
//  提示:
//
//
//  节点数在 [1, 10⁴] 范围内
//  树的深度在 [1, 10⁴]范围内
//  -100 <= Node.val <= 100
//  -10⁵ <= val <= 10⁵
//  1 <= depth <= the depth of tree + 1
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 204 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
struct TreeNode;
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
  void _add(TreeNode *cur, int val, int dep, int cur_dep) {
    if (cur == nullptr)
      return;
    if (cur_dep == dep - 1) {
      cur->left = new TreeNode(val, cur->left, nullptr);
      cur->right = new TreeNode(val, nullptr, cur->right);
      return;
    }
    _add(cur->left, val, dep, cur_dep + 1);
    _add(cur->right, val, dep, cur_dep + 1);
  }
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1)
      return new TreeNode(val, root, nullptr);

    _add(root, val, depth, 1);

    return root;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
