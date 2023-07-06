// 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
// （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//
//
//  示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[15,7],[9,20],[3]]
//
//
//  示例 2：
//
//
// 输入：root = [1]
// 输出：[[1]]
//
//
//  示例 3：
//
//
// 输入：root = []
// 输出：[]
//
//
//
//
//  提示：
//
//
//  树中节点数目在范围 [0, 2000] 内
//  -1000 <= Node.val <= 1000
//
//
//  Related Topics 树 广度优先搜索 二叉树 👍 680 👎 0
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    o << a << ", ";
  return o << "]";
}
class Solution {
public:
  auto levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans;
    int maxx_dep = 0;

    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int dep) {
      if (cur == nullptr)
        return;
      dfs(cur->left, dep + 1);
      dfs(cur->right, dep + 1);
      ans[maxx_dep - dep].emplace_back(cur->val);
    };
    function<void(TreeNode *, int)> dfs2 = [&](TreeNode *cur, int dep) {
      if (cur == nullptr)
        return;
      maxx_dep = max(maxx_dep, dep);
      dfs2(cur->left, dep + 1);
      dfs2(cur->right, dep + 1);
    };
    dfs2(root, 1);
    ans.resize(maxx_dep);
//    cout << ans << endl;
    dfs(root, 1);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
