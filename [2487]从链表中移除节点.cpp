// 给你一个链表的头节点 head 。
//
//  移除每个右侧有一个更大数值的节点。
//
//  返回修改后链表的头节点 head 。
//
//
//
//  示例 1：
//
//
//
//
// 输入：head = [5,2,13,3,8]
// 输出：[13,8]
// 解释：需要移除的节点是 5 ，2 和 3 。
//- 节点 13 在节点 5 右侧。
//- 节点 13 在节点 2 右侧。
//- 节点 8 在节点 3 右侧。
//
//
//  示例 2：
//
//
// 输入：head = [1,1,1,1]
// 输出：[1,1,1,1]
// 解释：每个节点的值都是 1 ，所以没有需要移除的节点。
//
//
//
//
//  提示：
//
//
//  给定列表中的节点数目在范围 [1, 10⁵] 内
//  1 <= Node.val <= 10⁵
//
//
//  Related Topics 栈 递归 链表 单调栈 👍 38 👎 0

struct ListNode {
  int val;
  ListNode *next;
}
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
#include "stack"
using namespace std;

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    std::deque<ListNode *> st;
    auto cur = head;
    while (cur != nullptr) {
      while (not st.empty() and st.back()->val < cur->val)
        st.pop_back();
      st.push_back(cur);
      cur = cur->next;
    }
    for (int i = 0; i + 1 < st.size(); ++i)
      st[i]->next = st[i + 1];
    return st.front();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
