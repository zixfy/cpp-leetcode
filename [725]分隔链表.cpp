// 给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k
// 个连续的部分。
//
//  每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1
//  。这可能会导致有些部分为 null 。
//
//  这 k
//  个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。
//
//  返回一个由上述 k 部分组成的数组。
//
//  示例 1：
//
//
// 输入：head = [1,2,3], k = 5
// 输出：[[1],[2],[3],[],[]]
// 解释：
// 第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
// 最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
//
//
//  示例 2：
//
//
// 输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
// 输出：[[1,2,3,4],[5,6,7],[8,9,10]]
// 解释：
// 输入被分成了几个连续的部分，并且每部分的长度相差不超过 1
// 。前面部分的长度大于等于后面部分的长度。
//
//
//
//
//  提示：
//
//
//  链表中节点的数目在范围 [0, 1000]
//  0 <= Node.val <= 1000
//  1 <= k <= 50
//
//
//  Related Topics 链表 👍 285 👎 0
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


class LeetcodeListView {
private:
  mutable size_t _size = 0;
  mutable bool _size_dirty = true;
  ListNode *_p_head;
  ListNode *_p_tail, *_p_cursor{};
  int _cursor_idx{};
  inline void _reset_cursor() {
    _cursor_idx = -1;
    _p_cursor = _p_head;
  }

public:
  LeetcodeListView() = delete;
  explicit LeetcodeListView(ListNode *head) {
    _p_head = new ListNode(0, head);
    _p_tail = _p_head;
    _reset_cursor();
  }
  size_t size() const {
    if (_size_dirty) {
      _size = 0;
      for (auto cur = _p_head->next; cur != nullptr; cur = cur->next)
        ++_size;
      _size_dirty = false;
    }
    return _size;
  }
  ListNode *get(int i) {
    if (i >= _size)
      return nullptr;
    if (_cursor_idx > i)
      _reset_cursor();
    while (_cursor_idx != i)
      ++_cursor_idx, _p_cursor = _p_cursor->next;
    return _p_cursor;
  }
  ListNode *get_detached(int i) {
    auto r = get(i);
    auto o = _p_cursor->next;
    ++_cursor_idx, _p_cursor->next = nullptr, _p_cursor = o;
    return r;
  }
  inline ListNode *front() { return _p_head->next; }
  inline bool empty() { return size() == 0; }
  void reverse() {}
};

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    LeetcodeListView ls(head);
    auto sz = ls.size();

    auto q = sz / k, r = sz % k;
    vector<ListNode *> ans;
    ans.reserve(k);
    size_t cur = 0;
    for (int i = 0; i < k; ++i) {
      auto lef = cur, rig = cur + q + (i < r);
//      cout << lef << " " << rig  << endl;
      auto lef_node = ls.get(lef);
      if (lef < rig)
        auto rig_node = ls.get_detached(rig - 1);
      ans.emplace_back(lef_node);
      cur = rig;
    }
//    cout << ls.size() << endl;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
