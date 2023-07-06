// 给你一个二叉树的根结点 root
// ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
//
//  一个结点的 「子树元素和」
//  定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//
//
//
//  示例 1：
//
//
//
//
// 输入: root = [5,2,-3]
// 输出: [2,-3,4]
//
//
//  示例 2：
//
//
//
//
// 输入: root = [5,2,-5]
// 输出: [2]
//
//
//
//
//  提示:
//
//
//  节点数在 [1, 10⁴] 范围内
//  -10⁵ <= Node.val <= 10⁵
//
//
//  Related Topics 树 深度优先搜索 哈希表 二叉树 👍 224 👎 0
#include <bits/stdc++.h>
using namespace std;
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
class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> cnt;
    function<int(decltype(root))> dfs = [&](decltype(root) cur) {
      if (cur == nullptr)
        return 0;
      int r = cur->val + dfs(cur->left) + dfs(cur->right);
      cnt[r]++;
      return r;
    };
    dfs(root);
    vector<int> ans;
    int maxx{numeric_limits<int>::min() / 2};
    for (const auto &[v, c] : cnt) {
      if (maxx <= c) {
        if (maxx < c)
          ans.clear(), maxx = c;
        ans.emplace_back(v);
      }
    }
    return std::move(ans);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
