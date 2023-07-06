//给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两者长度都为 n 。 
//
// 每次操作中，你可以选择交换 nums1 中任意两个下标处的值。操作的 开销 为两个下标的 和 。 
//
// 你的目标是对于所有的 0 <= i <= n - 1 ，都满足 nums1[i] != nums2[i] ，你可以进行 任意次 操作，请你返回达到这个目标
//的 最小 总代价。 
//
// 请你返回让 nums1 和 nums2 满足上述条件的 最小总代价 ，如果无法达成目标，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,2,3,4,5], nums2 = [1,2,3,4,5]
//输出：10
//解释：
//实现目标的其中一种方法为：
//- 交换下标为 0 和 3 的两个值，代价为 0 + 3 = 3 。现在 nums1 = [4,2,3,1,5] 。
//- 交换下标为 1 和 2 的两个值，代价为 1 + 2 = 3 。现在 nums1 = [4,3,2,1,5] 。
//- 交换下标为 0 和 4 的两个值，代价为 0 + 4 = 4 。现在 nums1 = [5,3,2,1,4] 。
//最后，对于每个下标 i ，都有 nums1[i] != nums2[i] 。总代价为 10 。
//还有别的交换值的方法，但是无法得到代价和小于 10 的方案。
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [2,2,2,1,3], nums2 = [1,2,2,3,3]
//输出：10
//解释：
//实现目标的一种方法为：
//- 交换下标为 2 和 3 的两个值，代价为 2 + 3 = 5 。现在 nums1 = [2,2,1,2,3] 。
//- 交换下标为 1 和 4 的两个值，代价为 1 + 4 = 5 。现在 nums1 = [2,3,1,2,2] 。
//总代价为 10 ，是所有方案中的最小代价。
// 
//
// 示例 3： 
//
// 
//输入：nums1 = [1,2,2], nums2 = [1,2,2]
//输出：-1
//解释：
//不管怎么操作，都无法满足题目要求。
//所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// n == nums1.length == nums2.length 
// 1 <= n <= 10⁵ 
// 1 <= nums1[i], nums2[i] <= n 
// 
//
// Related Topics 贪心 数组 哈希表 计数 👍 22 👎 0


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
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




