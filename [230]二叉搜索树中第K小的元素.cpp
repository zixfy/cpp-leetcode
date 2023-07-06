// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k
// 个最小元素（从 1 开始计数）。
//
//
//
//  示例 1：
//
//
// 输入：root = [3,1,4,null,2], k = 1
// 输出：1
//
//
//  示例 2：
//
//
// 输入：root = [5,3,6,2,4,null,null,1], k = 3
// 输出：3
//
//
//
//
//
//
//  提示：
//
//
//  树中的节点数为 n 。
//  1 <= k <= n <= 10⁴
//  0 <= Node.val <= 10⁴
//
//
//
//
//  进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k
//  小的值，你将如何优化算法？
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 732 👎 0
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
  int kthSmallest(TreeNode *root, int k) {
    unordered_map<TreeNode *, int> sizes;
    function<int(TreeNode *)> get_size = [&](TreeNode *cur) {
      if (cur == nullptr)
        return 0;
      if (!sizes.count(cur))
        sizes[cur] = 1 + get_size(cur->left) + get_size(cur->right);
      return sizes[cur];
    };
    function<int(TreeNode *, int)> _kth = [&](TreeNode *cur, int k) {
//      cout << k << " " << cur->val << endl;
      auto sz = get_size(cur->left);
      if (sz == k - 1)
        return cur->val;
      if (sz < k - 1)
        return _kth(cur->right, k - sz - 1);
      return _kth(cur->left, k);
    };
    return _kth(root, k);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
