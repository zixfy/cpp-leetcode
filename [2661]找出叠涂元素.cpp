// 给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。arr 和 mat
// 都包含范围 [1，m * n] 内的 所有 整数 。
//
//  从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat
//  单元格涂色。
//
//  请你找出 arr 中在 mat
//  的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 i 。
//
//
//
//  示例 1：
//
//
// 输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
// 输出：2
// 解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
//
//
//  示例 2：
//
//
// 输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// 输出：3
// 解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
//
//
//
//
//  提示：
//
//
//  m == mat.length
//  n = mat[i].length
//  arr.length == m * n
//  1 <= m, n <= 10⁵
//  1 <= m * n <= 10⁵
//  1 <= arr[i], mat[r][c] <= m * n
//  arr 中的所有整数 互不相同
//  mat 中的所有整数 互不相同
//
//
//  Related Topics 数组 哈希表 矩阵 👍 14 👎 0

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
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    const auto m = mat.size(), n = mat[0].size();
    unordered_map<int, int> col_cnt, row_cnt, v2col, v2row;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        v2col[mat[i][j]] = j, v2row[mat[i][j]] = i;
    int i = 0;
    for (const auto a : arr) {
      if (++col_cnt[v2col[a]] == m || ++row_cnt[v2row[a]] == n)
        return i;
      ++i;
    }
    return -1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
