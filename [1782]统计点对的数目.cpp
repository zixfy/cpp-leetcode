//给你一个无向图，无向图由整数 n ，表示图中节点的数目，和 edges 组成，其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条
//无向边。同时给你一个代表查询的整数数组 queries 。 
//
// 第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目： 
//
// 
// a < b 
// cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。 
// 
//
// 请你返回一个数组 answers ，其中 answers.length == queries.length 且 answers[j] 是第 j 个查询的答
//案。 
//
// 请注意，图中可能会有 多重边 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
//输出：[6,5]
//解释：每个点对中，与至少一个点相连的边的数目如上图所示。
//answers[0] = 6。所有的点对(a, b)中边数和都大于2，故有6个；
//answers[1] = 5。所有的点对(a, b)中除了(3,4)边数等于3，其它点对边数和都大于3，故有5个。
// 
//
// 示例 2： 
//
// 
//输入：n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries =
// [1,2,3,4,5]
//输出：[10,10,9,8,6]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= n <= 2 * 10⁴ 
// 1 <= edges.length <= 10⁵ 
// 1 <= ui, vi <= n 
// ui != vi 
// 1 <= queries.length <= 20 
// 0 <= queries[j] < edges.length 
// 
//
// Related Topics 图 数组 双指针 二分查找 排序 👍 165 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <iterator>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;

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
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




