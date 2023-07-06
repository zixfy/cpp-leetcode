//给定一个根为 root 的二叉树，每个节点的深度是 该节点到根的最短距离 。 
//
// 返回包含原始树中所有 最深节点 的 最小子树 。 
//
// 如果一个节点在 整个树 的任意节点之间具有最大的深度，则该节点是 最深的 。 
//
// 一个节点的 子树 是该节点加上它的所有后代的集合。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4]
//输出：[2,7,4]
//解释：
//我们返回值为 2 的节点，在图中用黄色标记。
//在图中用蓝色标记的是树的最深的节点。
//注意，节点 5、3 和 2 包含树中最深的节点，但节点 2 的子树最小，因此我们返回它。
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[1]
//解释：根节点是树中最深的节点。 
//
// 示例 3： 
//
// 
//输入：root = [0,1,3,null,2]
//输出：[2]
//解释：树中最深的节点为 2 ，有效子树为节点 2、1 和 0 的子树，但节点 2 的子树最小。 
//
// 
//
// 提示： 
//
// 
// 树中节点的数量在
// [1, 500] 范围内。 
// 0 <= Node.val <= 500 
// 每个节点的值都是 独一无二 的。 
// 
//
// 
//
// 注意：本题与力扣 1123 重复：https://leetcode-cn.com/problems/lowest-common-ancestor-of-
//deepest-leaves 
//
// Related Topics 树 深度优先搜索 广度优先搜索 哈希表 二叉树 👍 192 👎 0


#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      int max_dep = 0;
      int max_dep_leaves_cnt = 0;
      function<void(TreeNode *, int)> f1 = [&](TreeNode *cur, int dep) {
        if (cur == nullptr)
          return;
        if (max_dep < dep)
          max_dep = dep, max_dep_leaves_cnt = 0;
        if (max_dep == dep)
          ++max_dep_leaves_cnt;
        f1(cur->left, dep + 1), f1(cur->right, dep + 1);
      };
      f1(root, 1);
      TreeNode *ans = nullptr;
      function<int(TreeNode *, int)> f2 = [&](TreeNode *cur, int dep) {
        if (cur == nullptr || ans != nullptr)
          return 0;
        int r = 0;
        if (dep == max_dep)
          r += 1;
        r += f2(cur->left, dep + 1) + f2(cur->right, dep + 1);
        if (ans == nullptr && r == max_dep_leaves_cnt)
          ans = cur;
        return r;
      };
      f2(root, 1);
      //    cout << max_dep << ", " << max_dep_leaves_cnt << endl;
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
