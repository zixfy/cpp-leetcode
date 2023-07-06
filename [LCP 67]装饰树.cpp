// 力扣嘉年华上的 DIY 手工展位准备了一棵缩小版的 **二叉** 装饰树 `root`
// 和灯饰，你需要将灯饰逐一插入装饰树中，要求如下：
//
//- 完成装饰的二叉树根结点与 `root` 的根结点值相同
//- 若一个节点拥有父节点，则在该节点和他的父节点之间插入一个灯饰（即插入一个值为
//`-1` 的节点）。具体地：
//  - 在一个 父节点 x 与其左子节点 y 之间添加 -1 节点， 节点 -1、节点 y
//  为各自父节点的左子节点，
//  - 在一个 父节点 x 与其右子节点 y 之间添加 -1 节点， 节点 -1、节点 y
//  为各自父节点的右子节点，
//
// 现给定二叉树的根节点 `root` ，请返回完成装饰后的树的根节点。
//**示例 1：**
//
//> 输入：
//> `root = [7,5,6]`
//>
//> 输出：`[7,-1,-1,5,null,null,6]`
//>
//> 解释：如下图所示，
//> ![image.png](https://pic.leetcode-cn.com/1663575757-yRLGaq-image.png)
//
//**示例 2：**
//
//> 输入：
//> `root = [3,1,7,3,8,null,4]`
//>
//> 输出：`[3,-1,-1,1,null,null,7,-1,-1,null,-1,3,null,null,8,null,4]`
//>
//> 解释：如下图所示
//> ![image.png](https://pic.leetcode-cn.com/1663577920-sjrAYH-image.png)
//
//**提示：**
//
//> `0 <= root.Val <= 1000`
//> `root` 节点数量范围为 `[1, 10^5]`
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 10 👎 0

#include "bits/stdc++.h"
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
  TreeNode *expandBinaryTree(TreeNode *root) {
    function<void(TreeNode *)> f = [&](TreeNode *cur) {
      if (cur->left) {
        auto ex_node = new TreeNode(-1, cur->left, nullptr);
        cur->left = ex_node;
        f(ex_node->left);
      }
      if (cur->right) {
        auto ex_node = new TreeNode(-1, nullptr, cur->right);
        cur->right = ex_node;
        f(ex_node->right);
      }
    };
    f(root);
    return root;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
