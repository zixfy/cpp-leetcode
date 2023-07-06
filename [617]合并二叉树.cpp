// 给你两棵二叉树： root1 和 root2 。
//
//  想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠
// ，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null
// 的节点将直接作为新二叉树的节点。
//
//  返回合并后的二叉树。
//
//  注意: 合并过程必须从两个树的根节点开始。
//
//
//
//  示例 1：
//
//
// 输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// 输出：[3,4,5,5,4,null,7]
//
//
//  示例 2：
//
//
// 输入：root1 = [1], root2 = [1,2]
// 输出：[2,2]
//
//
//
//
//  提示：
//
//
//  两棵树中的节点数目在范围 [0, 2000] 内
//  -10⁴ <= Node.val <= 10⁴
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1221 👎 0

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
using pT = TreeNode *;
class Solution {
public:
  pT mergeTrees(TreeNode *root1, TreeNode *root2) {
    function<pT(pT, pT)> dfs = [&](pT c1, pT c2) {
      if (c1 == nullptr && c2 == nullptr)
        return static_cast<pT>(nullptr);
      auto r = new TreeNode;
      pT l1{}, r1{}, l2{}, r2{};
      if (c1 != nullptr) {
        r->val += c1->val;
        l1 = c1->left;
        r1 = c1->right;
      }
      if (c2 != nullptr) {
        r->val += c2->val;
        l2 = c2->left;
        r2 = c2->right;
      }
      r->left = dfs(l1, l2);
      r->right = dfs(r1, r2);
      return r;
    };
    return dfs(root1, root2);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
