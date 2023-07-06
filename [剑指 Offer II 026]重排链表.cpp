// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//
//  L0 → L1 → … → Ln-1 → Ln 请将其重新排列后变为：
//
//  L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
//
//  不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//
//
//  示例 1:
//
//
//
//
// 输入: head = [1,2,3,4]
// 输出: [1,4,2,3]
//
//  示例 2:
//
//
//
//
// 输入: head = [1,2,3,4,5]
// 输出: [1,5,2,4,3]
//
//
//
//  提示：
//
//
//  链表的长度范围为 [1, 5 * 10⁴]
//  1 <= node.val <= 1000
//
//
//
//
//
//  注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/
//
//  Related Topics 栈 递归 链表 双指针 👍 111 👎 0

#include <bits/stdc++.h>
using namespace std;

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
class Solution {
public:
  void reorderList(ListNode *head) {
    auto p1 = head, p2 = head;
    while (p2 != nullptr) {
      p2 = p2->next;
      if (p2)
        p2 = p2->next;
      if (p2 == nullptr) {
        auto oldp = p1;
        p1 = p1->next;
        oldp->next = nullptr;
        break;
      }
      p1 = p1->next;
    }
    vector<ListNode*> stk;
    while (p1 != nullptr)
      stk.push_back(p1), p1 = p1->next;
    reverse(stk.begin(), stk.end());
    for (auto p : stk) {
      //      cout << p << endl;
      //      cout << head->val << ", " << p->val << endl;
      auto nxt_head = head->next;
      p->next = head->next;
      head->next = p;
      head = nxt_head;
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
