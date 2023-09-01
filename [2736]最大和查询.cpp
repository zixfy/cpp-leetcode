//给你两个长度为 n 、下标从 0 开始的整数数组 nums1 和 nums2 ，另给你一个下标从 1 开始的二维数组 queries ，其中 
//queries[i] = [xi, yi] 。 
//
// 对于第 i 个查询，在所有满足 nums1[j] >= xi 且 nums2[j] >= yi 的下标 j (0 <= j < n) 中，找出 nums1
//[j] + nums2[j] 的 最大值 ，如果不存在满足条件的 j 则返回 -1 。 
//
// 返回数组 answer ，其中 answer[i] 是第 i 个查询的答案。 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [4,3,1,2], nums2 = [2,4,9,5], queries = [[4,1],[1,3],[2,5]]
//输出：[6,10,7]
//解释：
//对于第 1 个查询：xi = 4 且 yi = 1 ，可以选择下标 j = 0 ，此时 nums1[j] >= 4 且 nums2[j] >= 1 。
//nums1[j] + nums2[j] 等于 6 ，可以证明 6 是可以获得的最大值。
//对于第 2 个查询：xi = 1 且 yi = 3 ，可以选择下标 j = 2 ，此时 nums1[j] >= 1 且 nums2[j] >= 3 。
//nums1[j] + nums2[j] 等于 10 ，可以证明 10 是可以获得的最大值。
//对于第 3 个查询：xi = 2 且 yi = 5 ，可以选择下标 j = 3 ，此时 nums1[j] >= 2 且 nums2[j] >= 5 。
//nums1[j] + nums2[j] 等于 7 ，可以证明 7 是可以获得的最大值。
//因此，我们返回 [6,10,7] 。
// 
//
// 示例 2： 
//
// 输入：nums1 = [3,2,5], nums2 = [2,3,4], queries = [[4,4],[3,2],[1,1]]
//输出：[9,9,9]
//解释：对于这个示例，我们可以选择下标 j = 2 ，该下标可以满足每个查询的限制。
// 
//
// 示例 3： 
//
// 输入：nums1 = [2,1], nums2 = [2,3], queries = [[3,3]]
//输出：[-1]
//解释：示例中的查询 xi = 3 且 yi = 3 。对于每个下标 j ，都只满足 nums1[j] < xi 或者 nums2[j] < yi 。因此，不
//存在答案。 
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == nums2.length 
// n == nums1.length 
// 1 <= n <= 10⁵ 
// 1 <= nums1[i], nums2[i] <= 10⁹ 
// 1 <= queries.length <= 10⁵ 
// queries[i].length == 2 
// xi == queries[i][1] 
// yi == queries[i][2] 
// 1 <= xi, yi <= 10⁹ 
// 
//
// Related Topics 栈 树状数组 线段树 数组 二分查找 排序 单调栈 👍 19 👎 0


#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




