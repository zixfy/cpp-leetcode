// 给定两个用链表表示的整数，每个节点包含一个数位。
//
//  这些数位是反向存放的，也就是个位排在链表首部。
//
//  编写函数对这两个整数求和，并用链表形式返回结果。
//
//
//
//  示例：
//
//  输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
// 输出：2 -> 1 -> 9，即912
//
//
//  进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?
//
//  示例：
//
//  输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
// 输出：9 -> 1 -> 2，即912
//
//
//  Related Topics 递归 链表 数学 👍 188 👎 0

#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
};
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto p1 = l1, p2 = l2;
    while (p1->next != nullptr && p2->next != nullptr) {
      p1->val += p2->val;
      p1 = p1->next, p2 = p2->next;
    }
    p1->val += p2->val;
    if (p1->next == nullptr)
      p1->next = p2->next;

    for (auto p = l1; p != nullptr; p = p->next) {
      if (p->val > 9) {
        p->val -= 10;
        if (p->next == nullptr)
          p->next = new ListNode(0);
        p->next->val++;
      }
    }
    return l1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
