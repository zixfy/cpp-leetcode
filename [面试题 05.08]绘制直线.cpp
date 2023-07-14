// 已知一个由像素点组成的单色屏幕，每行均有 w 个像素点，所有像素点初始为
// 0，左上角位置为 (0,0)。
//
//  现将每行的像素点按照「每 32 个像素点」为一组存放在一个 int
//  中，再依次存入长度为 length 的一维数组中。
//
//  我们将在屏幕上绘制一条从点 (x1,y) 到点 (x2,y) 的直线（即像素点修改为
//  1），请返回绘制过后的数组。
//
//
//
//  注意：
//
//
//  用例保证屏幕宽度 w 可被 32 整除（即一个 int 不会分布在两行上）
//
//
//
//
//  示例1:
//
//
//  输入：length = 1, w = 32, x1 = 30, x2 = 31, y = 0
//  输出：[3]
//  解释：在第 0 行的第 30 位到第 31 位画一条直线，屏幕二进制形式表示为
//  [00000000000000000000000000000011]，因此
// 返回 [3]
//
//
//  示例2:
//
//
//  输入：length = 3, w = 96, x1 = 0, x2 = 95, y = 0
//  输出：[-1, -1, -1]
//  解释：由于二进制 11111111111111111111111111111111 的 int 类型代表
//  -1，因此返回 [-1,-1,-1]
//
//
//
//  提示：
//
//
//  1 <= length <= 10^5
//  1 <= w <= 3 * 10^5
//  0 <= x1 <= x2 < w
//  0 <= y <= 10
//
//
//  Related Topics 位运算 数组 数学 👍 29 👎 0

#include <bits/stdc++.h>
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
class Solution {
public:
  vector<int> drawLine(int length, int w, int x1, int x2, int y) {
    vector ans(length, 0);
    auto row_len = w / 32;
    auto base = y * row_len;
    auto q1 = x1 / 32, r1 = x1 % 32;
    auto q2 = x2 / 32, r2 = x2 % 32;
    if (q1 == q2) {
      for (int j = r1; j <= r2; ++j)
        ans[base + q1] |= (1u << (31 - j));
    }
    else {
      for (int j = r1; j < 32; ++j)
        ans[base + q1] |= (1u << (31 - j));
      for (int i = q1 + 1; i < q2; ++i)
        ans[base + i] = -1;

      for (int j = 0; j <= r2; ++j)
        ans[base + q2] |= (1u << (31 - j));
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
