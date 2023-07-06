// 给你一个二维整数数组 descriptions ，其中 descriptions[i] = [parenti, childi,
// isLefti] 表示 parenti 是 childi 在 二叉树 中的 父节点，二叉树中各节点的值
// 互不相同 。此外：
//
//
//  如果 isLefti == 1 ，那么 childi 就是 parenti 的左子节点。
//  如果 isLefti == 0 ，那么 childi 就是 parenti 的右子节点。
//
//
//  请你根据 descriptions 的描述来构造二叉树并返回其 根节点 。
//
//  测试用例会保证可以构造出 有效 的二叉树。
//
//
//
//  示例 1：
//
//
//
//
// 输入：descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// 输出：[50,20,80,15,17,19]
// 解释：根节点是值为 50 的节点，因为它没有父节点。
// 结果二叉树如上图所示。
//
//
//  示例 2：
//
//
//
//
// 输入：descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// 输出：[1,2,null,null,3,4]
// 解释：根节点是值为 1 的节点，因为它没有父节点。
// 结果二叉树如上图所示。
//
//
//
//  提示：
//
//
//  1 <= descriptions.length <= 10⁴
//  descriptions[i].length == 3
//  1 <= parenti, childi <= 10⁵
//  0 <= isLefti <= 1
//  descriptions 所描述的二叉树是一棵有效二叉树
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 数组 哈希表 二叉树 👍 36 👎 0
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
#include "bits/stdc++.h";
using namespace std;
class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> mapy;
    unordered_set<TreeNode *> derived;
    auto f = [&mapy](int v) {
      if (!mapy.count(v))
        mapy[v] = new TreeNode(v);
      return mapy[v];
    };
    for (const auto &des : descriptions) {
      auto par = f(des[0]), child = f(des[1]);
      derived.insert(child);
      auto is_lef = des[2];
      if (is_lef)
        par->left = child;
      else
        par->right = child;
    }
    for (auto [k, v]: mapy)
      if (!derived.count(v))
        return v;
    return nullptr;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
