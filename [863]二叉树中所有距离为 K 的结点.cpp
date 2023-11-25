// 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k 。
//
//  返回到目标结点 target 距离为 k 的所有结点的值的列表。 答案可以以 任何顺序
//  返回。
//
//
//
//
//
//
//  示例 1：
//
//
//
//
// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// 输出：[7,4,1]
// 解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
//
//
//  示例 2:
//
//
// 输入: root = [1], target = 1, k = 3
// 输出: []
//
//
//
//
//  提示:
//
//
//  节点数在 [1, 500] 范围内
//  0 <= Node.val <= 500
//  Node.val 中所有值 不同
//  目标结点 target 是树上的结点。
//  0 <= k <= 1000
//
//
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 633 👎 0

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
}
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "queue"
#include "vector"
using namespace std;
auto RecursiveLam = [](auto &&lam) {
  return [lam_impl = std::forward<decltype(lam)>(lam)](
             auto &&...args) -> decltype(auto) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};
class Solution {
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {

    if (k == 0)
      return std::initializer_list<int> {target->val};

    std::queue<TreeNode *> bfs;
    bfs.push(target);
    for (int i = 0; i < k; ++i) {
      auto qsz = bfs.size();
      for (int j = 0; j < qsz; ++j) {
        auto cur = bfs.front();
        bfs.pop();
        if (cur->left != nullptr)
          bfs.push(cur->left);
        if (cur->right != nullptr)
          bfs.push(cur->right);
      }
    }

    std::vector<TreeNode *> st;
    std::vector<std::pair<TreeNode *, bool>> dfs;
    dfs.emplace_back(root, false);
    while (not dfs.empty()) {
      auto [cur, flag] = dfs.back();
      dfs.pop_back();
      if (!flag) {
        st.emplace_back(cur);
        if (cur == target)
          break;
        dfs.emplace_back(cur, true);
        if (cur->left != nullptr)
          dfs.emplace_back(cur->left, false);
        if (cur->right != nullptr)
          dfs.emplace_back(cur->right, false);

      } else {
        st.pop_back();
      }
    }
//        for (auto p : st)
//          cout << "\n | " << p->val;
    std::queue<TreeNode *> bfs2;
    bfs2.push(target);

    for (int i = 0; i < k; ++i) {
      auto qsz = bfs2.size();
      for (int j = 0; j < qsz; ++j) {
        auto cur = bfs2.front();
        bfs2.pop();

        auto iter = std::find(st.begin(), st.end(), cur);
        if (iter == st.end()) {
          if (cur->left != nullptr)
            bfs2.push(cur->left);
          if (cur->right != nullptr)
            bfs2.push(cur->right);
        } else {
          if (cur == root) {
            if (cur->left != nullptr and
                std::find(st.begin(), st.end(), cur->left) == st.end())
              bfs2.push(cur->left);
            if (cur->right != nullptr and
                std::find(st.begin(), st.end(), cur->right) == st.end())
              bfs2.push(cur->right);
          } else {
            bfs2.push(*prev(iter));
          }
        }
      }
    }

    vector<int> ans;
    while (not bfs.empty())
      ans.emplace_back(bfs.front()->val), bfs.pop();
    if (root != target)
      while (not bfs2.empty())
        ans.emplace_back(bfs2.front()->val), bfs2.pop();
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
