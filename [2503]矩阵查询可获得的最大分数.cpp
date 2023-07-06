//给你一个大小为 m x n 的整数矩阵 grid 和一个大小为 k 的数组 queries 。 
//
// 找出一个大小为 k 的数组 answer ，且满足对于每个整数 queries[i] ，你从矩阵 左上角 单元格开始，重复以下过程： 
//
// 
// 如果 queries[i] 严格 大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1 分，并且你可以移动到所有 4 个方向（上、下、左、右）上
//任一 相邻 单元格。 
// 否则，你不能获得任何分，并且结束这一过程。 
// 
//
// 在过程结束后，answer[i] 是你可以获得的最大分数。注意，对于每个查询，你可以访问同一个单元格 多次 。 
//
// 返回结果数组 answer 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
//输出：[5,8,1]
//解释：上图展示了每个查询中访问并获得分数的单元格。 
//
// 示例 2： 
// 
// 
//输入：grid = [[5,2,1],[1,1,2]], queries = [3]
//输出：[0]
//解释：无法获得分数，因为左上角单元格的值大于等于 3 。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 2 <= m, n <= 1000 
// 4 <= m * n <= 10⁵ 
// k == queries.length 
// 1 <= k <= 10⁴ 
// 1 <= grid[i][j], queries[i] <= 10⁶ 
// 
//
// Related Topics 广度优先搜索 并查集 数组 排序 堆（优先队列） 👍 36 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




