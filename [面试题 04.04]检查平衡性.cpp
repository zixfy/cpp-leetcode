// 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过
// 1。
//  示例 1: 给定二叉树 [3,9,20,null,null,15,7]     3    / \   9  20     /
//  \    15   7 返
// 回  true 。 示例 2: 给定二叉树 [1,2,2,3,3,null,null,4,4]       1      /
// \     2   2    / \
//   3   3  / \ 4 4 返回 false 。
//
//  Related Topics 树 深度优先搜索 二叉树 👍 108 👎 0

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  using pt = pair<bool, int>;

private:
  pt _is_balanced(TreeNode *cur) {
    if (cur == nullptr)
      return {true, 0};
    int hei = 1;
    auto [b1, h1] = _is_balanced(cur->left);
    if (!b1)
      return {false, hei};
    auto [b2, h2] = _is_balanced(cur->right);
    if (!b2)
      return {false, hei};
    return {abs(h1 - h2) < 2, hei + max(h1, h2)};
  }

public:
  bool isBalanced(TreeNode *root) { return _is_balanced(root).first; }
};
// leetcode submit region end(Prohibit modification and deletion)
