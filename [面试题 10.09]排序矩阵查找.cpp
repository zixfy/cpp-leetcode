// 给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。
//
//  示例:
//
//  现有矩阵 matrix 如下：
//
//  [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
//]
//
//
//  给定 target = 5，返回 true。
//
//  给定 target = 20，返回 false。
//
//  Related Topics 数组 二分查找 分治 矩阵 👍 58 👎 0

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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    const auto m = matrix.size(), n = matrix[0].size();
    int l = -1, r = m;
    while (l + 1 < r) {
      auto mid = (l + r) >> 1;
      const auto &row = matrix[mid];
      if (row.front() > target)
        r = mid;
      else if (row.back() < target)
        l = mid;
      else
        break ;
    }
    if (l + 1 >= r)
      return false;
    const auto &row = matrix[l + 1];
    return std::binary_search(row.begin(), row.end(), target);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
