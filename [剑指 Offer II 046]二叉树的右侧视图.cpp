//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: [1,2,3,null,5,null,4]
//输出: [1,3,4]
// 
//
// 示例 2: 
//
// 
//输入: [1,null,3]
//输出: [1,3]
// 
//
// 示例 3: 
//
// 
//输入: []
//输出: []
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,100] 
// 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 
// 注意：本题与主站 199 题相同：https://leetcode-cn.com/problems/binary-tree-right-side-
//view/ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 44 👎 0


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
//
// Created by wwww on 2023/4/16.
//
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
#include <bits/stdc++.h>
using namespace std;
template<typename T>
using matrix = vector<vector<T>>;
template<typename T>
std::ostream& operator<<(std::ostream &o, const std::vector<T> &v){
  o << "vector [" ;
  if (!v.empty())
    std::copy(v.begin(), v.end(), ostream_iterator<T, char> (o, ", ")), o << "\b\b";
  return o << "]";
}
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    function<void(TreeNode*, int)> dfs = [&] (TreeNode* cur, int dep) {
      if (cur == nullptr)
        return;
      if (dep >= ans.size())
        ans.emplace_back(cur -> val);
      dfs(cur -> right, dep + 1);
      dfs(cur -> left, dep + 1);
    };
    dfs(root, 0);
    return std::move(ans);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
