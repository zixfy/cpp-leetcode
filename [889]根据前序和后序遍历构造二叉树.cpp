// 给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复
// 值的二叉树的前序遍历，postorder 是同一棵 树的后序遍历，重构并返回二叉树。
//
//  如果存在多个答案，您可以返回其中 任何 一个。
//
//
//
//  示例 1：
//
//
//
//
// 输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// 输出：[1,2,3,4,5,6,7]
//
//
//  示例 2:
//
//
// 输入: preorder = [1], postorder = [1]
// 输出: [1]
//
//
//
//
//  提示：
//
//
//  1 <= preorder.length <= 30
//  1 <= preorder[i] <= preorder.length
//  preorder 中所有值都 不同
//  postorder.length == preorder.length
//  1 <= postorder[i] <= postorder.length
//  postorder 中所有值都 不同
//  保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
//
//
//  Related Topics 树 数组 哈希表 分治 二叉树 👍 309 👎 0

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
private:
  TreeNode *_ctor(const vector<int> &pre, int l1, int r1,
                  const vector<int> &post, int l2, int r2) {
    if (r1 < l1)
      return nullptr;
    auto r = new TreeNode(pre[l1]);
    if (r1 == l1)
      return r;
    int rig_val = post[r2 - 1];
    int sep = l1 + 1;
    while (pre[sep] != rig_val)
      ++sep;
    //sep -l1 -2
    r->right = _ctor(pre, sep, r1, post, r2 - 1 - r1 + sep, r2 - 1);
    r->left = _ctor(pre, l1 + 1, sep - 1, post, l2, sep + l2 - l1 - 2);
    return r;
  }

public:
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    return _ctor(preorder, 0, preorder.size() - 1, postorder, 0,
                 postorder.size() - 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
