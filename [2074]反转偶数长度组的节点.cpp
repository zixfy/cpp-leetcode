// 给你一个链表的头节点 head 。
//
//  链表中的节点 按顺序 划分成若干 非空
//  组，这些非空组的长度构成一个自然数序列（1, 2, 3, 4, ...）。一个组的 长度
//  就是组中分配到的节点数目
// 。换句话说：
//
//
//  节点 1 分配给第一组
//  节点 2 和 3 分配给第二组
//  节点 4、5 和 6 分配给第三组，以此类推
//
//
//  注意，最后一组的长度可能小于或者等于 1 + 倒数第二组的长度 。
//
//  反转 每个 偶数 长度组中的节点，并返回修改后链表的头节点 head 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：head = [5,2,6,3,9,1,7,3,8,4]
// 输出：[5,6,2,3,9,1,4,8,3,7]
// 解释：
//- 第一组长度为 1 ，奇数，没有发生反转。
//- 第二组长度为 2 ，偶数，节点反转。
//- 第三组长度为 3 ，奇数，没有发生反转。
//- 最后一组长度为 4 ，偶数，节点反转。
//
//
//  示例 2：
//
//
//
//
// 输入：head = [1,1,0,6]
// 输出：[1,0,1,6]
// 解释：
//- 第一组长度为 1 ，没有发生反转。
//- 第二组长度为 2 ，节点反转。
//- 最后一组长度为 1 ，没有发生反转。
//
//
//  示例 3：
//
//
//
//
// 输入：head = [2,1]
// 输出：[2,1]
// 解释：
//- 第一组长度为 1 ，没有发生反转。
//- 最后一组长度为 1 ，没有发生反转。
//
//
//
//
//  提示：
//
//
//  链表中节点数目范围是 [1, 10⁵]
//  0 <= Node.val <= 10⁵
//
//
//  Related Topics 链表 👍 25 👎 0
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
ostream &operator<<(ostream& o , ListNode* cur) {
  while (cur != nullptr) {
    o << cur->val << " -> " ;
    cur = cur-> next;
  }
  return o;
}
class Solution {
public:
  ListNode *reverseEvenLengthGroups(ListNode *head) {
    int layer_sz = 1;
    auto cur = new ListNode(114514, head);
    while (cur->next != nullptr) {
      auto old_cur = cur;
      int real_sz = 0;
      for (; real_sz < layer_sz && cur->next; ++real_sz)
        cur = cur->next;
      if (!(real_sz & 1)) {
        auto p = old_cur->next->next;
        old_cur->next->next = cur->next;
        cur = old_cur->next;
        ListNode* nxt_p;
        for (int i = 0; i < real_sz - 1; ++i, p=nxt_p)
          nxt_p = p->next, p->next = old_cur->next, old_cur->next = p;
      }
//      cout << real_sz << " "<< old_cur->next->val << " " << cur->val << endl;
//      cout << head << endl;
      ++layer_sz;
    }
    return head;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
