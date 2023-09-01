// 给你一个 非空 链表的头节点 head ，表示一个不含前导零的非负数整数。
//
//  将链表 翻倍 后，返回头节点 head 。
//
//
//
//  示例 1：
//
//
// 输入：head = [1,8,9]
// 输出：[3,7,8]
// 解释：上图中给出的链表，表示数字 189 。返回的链表表示数字 189 * 2 = 378 。
//
//  示例 2：
//
//
// 输入：head = [9,9,9]
// 输出：[1,9,9,8]
// 解释：上图中给出的链表，表示数字 999 。返回的链表表示数字 999 * 2 = 1998 。
//
//
//
//
//  提示：
//
//
//  链表中节点的数目在范围 [1, 10⁴] 内
//  0 <= Node.val <= 9
//  生成的输入满足：链表表示一个不含前导零的数字，除了数字 0 本身。
//
//
//  👍 9 👎 0

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
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
  ListNode *doubleIt(ListNode *head) {
    auto p = head;
    p->val <<= 1;
    while (p->next != nullptr) {
      p->next->val *= 2;
      if (p->next->val > 9) {
        p->val++;
        p->next->val -= 10;
      }
      p = p->next;
    }
    if (head -> val > 9) {
      head -> val -= 10;
      return new ListNode(1, head);
    }
    return head;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
