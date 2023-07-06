// 给定一个单链表的头节点 head ，其中的元素 按升序排序
// ，将其转换为高度平衡的二叉搜索树。
//
//  本题中，一个高度平衡二叉树是指一个二叉树每个节点
//  的左右两个子树的高度差不超过 1。
//
//
//
//  示例 1:
//
//
//
//
// 输入: head = [-10,-3,0,5,9]
// 输出: [0,-3,9,-10,null,5]
// 解释:
// 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
//
//
//  示例 2:
//
//
// 输入: head = []
// 输出: []
//
//
//
//
//  提示:
//
//
//  head 中的节点数在[0, 2 * 10⁴] 范围内
//  -10⁵ <= Node.val <= 10⁵
//
//
//  Related Topics 树 二叉搜索树 链表 分治 二叉树 👍 824 👎 0

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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  TreeNode *_ctor(const vector<int> &nums, int l, int r) {
    if (l > r)
      return nullptr;
    auto m = (l + r) >> 1;
    auto ret = new TreeNode(nums[m]);
    ret->left = _ctor(nums, l, m - 1);
    ret->right = _ctor(nums, m + 1, r);
    return ret;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    vector<int> ans;
    while (head != nullptr)
      ans.emplace_back(head->val), head = head->next;
    return _ctor(ans, 0, ans.size() - 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
