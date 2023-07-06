// 给你一个二叉树的根节点 root ，按 任意顺序
// ，返回所有从根节点到叶子节点的路径。
//
//  叶子节点 是指没有子节点的节点。
//
//  示例 1：
//
//
// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]
//
//
//  示例 2：
//
//
// 输入：root = [1]
// 输出：["1"]
//
//
//
//
//  提示：
//
//
//  树中节点的数目在范围 [1, 100] 内
//  -100 <= Node.val <= 100
//
//
//  Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 944 👎 0
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
  auto binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string path{};
    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      auto old_s_len = path.size();
      if (cur != root)
        path += "->";
      path += to_string(cur->val);
//      cout << "old_l: " << old_s_len << " " << path<< endl;
      if (cur->left)
        dfs(cur->left);
      else if (cur->right == nullptr) {
        ans.emplace_back(path);
        path.resize(old_s_len);
        return;
      }
      if (cur->right)
        dfs(cur->right);
      path.resize(old_s_len);
    };
    dfs(root);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
