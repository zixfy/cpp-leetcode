// 给出二叉树的根节点 root，树上每个节点都有一个不同的值。
//
//  如果节点值在 to_delete
//  中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
//
//  返回森林中的每棵树。你可以按任意顺序组织答案。
//
//
//
//  示例 1：
//
//
//
//
// 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
// 输出：[[1,2,null,4],[6],[7]]
//
//
//  示例 2：
//
//
// 输入：root = [1,2,4,null,3], to_delete = [3]
// 输出：[[1,2,4]]
//
//
//
//
//  提示：
//
//
//  树中的节点数最大为 1000。
//  每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
//  to_delete.length <= 1000
//  to_delete 包含一些从 1 到 1000、各不相同的值。
//
//
//  Related Topics 树 深度优先搜索 二叉树 👍 206 👎 0
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <unordered_set>
#include <vector>
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
  template <typename T> auto delNodes(TreeNode *root, vector<T> &to_delete) {
    using pt = TreeNode *;
    vector<TreeNode *> ans;
    unordered_set<T> cnt(to_delete.begin(), to_delete.end());
    function<void(pt, pt)> dfs = [&](TreeNode *cur, TreeNode *par) {
      if (cur == nullptr)
        return;
      auto lef{cur->left}, rig{cur->right};
      if (cnt.count(cur->val)) {
        if (par)
          if (par->left == cur)
            par->left = nullptr;
          else
            par->right = nullptr;
        if (cur ->left)
          cur->left = nullptr;
        if (cur->right)
          cur->right = nullptr;
        cur = nullptr;
      }
      else if (par == nullptr)
        ans.emplace_back(cur);
      dfs(lef, cur);
      dfs(rig, cur);
    };
    dfs(root, nullptr);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
