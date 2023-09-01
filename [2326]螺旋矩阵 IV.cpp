// 给你两个整数：m 和 n ，表示矩阵的维数。
//
//  另给你一个整数链表的头节点 head 。
//
//  请你生成一个大小为 m x n
//  的螺旋矩阵，矩阵包含链表中的所有整数。链表中的整数从矩阵 左上角 开始、顺时针
//  按 螺旋 顺序填充。如果还存在剩余的空格，
// 则用 -1 填充。
//
//  返回生成的矩阵。
//
//
//
//  示例 1：
//  输入：m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// 输出：[[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// 解释：上图展示了链表中的整数在矩阵中是如何排布的。
// 注意，矩阵中剩下的空格用 -1 填充。
//
//
//  示例 2：
//  输入：m = 1, n = 4, head = [0,1,2]
// 输出：[[0,1,2,-1]]
// 解释：上图展示了链表中的整数在矩阵中是如何从左到右排布的。
// 注意，矩阵中剩下的空格用 -1 填充。
//
//
//
//  提示：
//
//
//  1 <= m, n <= 10⁵
//  1 <= m * n <= 10⁵
//  链表中节点数目在范围 [1, m * n] 内
//  0 <= Node.val <= 1000
//
//
//  Related Topics 数组 链表 矩阵 模拟 👍 23 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
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
using std::vector;
class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    auto nxt = [&head]() {
      if (head == nullptr)
        return -1;
      auto ret = head->val;
      head = head->next;
      return ret;
    };
    vector ans(m, vector (n, -1));
    int lx = 0, ly = 0, rx = m, ry = n;
    int dir = 0;
    while (head != nullptr) {
      switch (dir % 4) {
      case 0: {
        for (int y = ly; y < ry; ++y)
          ans[lx][y] = nxt();
        ++lx;
        break;
      }
      case 1: {
        for (int x = lx; x < rx; ++x)
          ans[x][ry - 1] = nxt();
        --ry;
        break;
      }
      case 2: {
        for (int y = ry - 1; y >= ly; --y)
          ans[rx - 1][y] = nxt();
        --rx;
        break ;
      }
      default: {
        for (int x = rx - 1; x >= lx; --x)
          ans[x][ly] = nxt();
        ++ly;
      }
      }
      ++dir;
    }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
