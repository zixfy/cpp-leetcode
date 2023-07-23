// 给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差
//
//
//
//  示例：
//
//
// 输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
// 输出：3，即数值对(11, 8)
//
//
//
//
//  提示：
//
//
//  1 <= a.length, b.length <= 100000
//  -2147483648 <= a[i], b[i] <= 2147483647
//  正确结果在区间 [0, 2147483647] 内
//
//
//  Related Topics 数组 双指针 二分查找 排序 👍 74 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using std::vector;
class Solution {
public:
  int smallestDifference(vector<int> &a, vector<int> &b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int p1 = 0, p2 = 0;
    int na = a.size(), nb = b.size();
    auto ans = std::numeric_limits<int>::max();
    using i64 = long long;
    while (p1 < na || p2 < nb) {
      ans = std::min(i64(ans), std::abs(1ll * a[p1] - b[p2]));
      if (p1 < na - 1 && a[p1] <= b[p2]) {
        p1++;
      } else if (p2 < nb - 1 && b[p2] <= a[p1]) {
        p2++;
      } else
        break;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
