// 符合下列属性的数组 arr 称为 山脉数组 ：
//
//
//  arr.length >= 3
//  存在 i（0 < i < arr.length - 1）使得：
//
//  arr[0] < arr[1] < ... arr[i-1] < arr[i]
//  arr[i] > arr[i+1] > ... > arr[arr.length - 1]
//
//
//
//  给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] <
//  arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。
//
//  你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。
//
//
//
//  示例 1：
//
//
// 输入：arr = [0,1,0]
// 输出：1
//
//
//  示例 2：
//
//
// 输入：arr = [0,2,1,0]
// 输出：1
//
//
//  示例 3：
//
//
// 输入：arr = [0,10,5,2]
// 输出：1
//
//
//
//
//  提示：
//
//
//  3 <= arr.length <= 10⁵
//  0 <= arr[i] <= 10⁶
//  题目数据保证 arr 是一个山脉数组
//
//
//  Related Topics 数组 二分查找 👍 350 👎 0
#include "bits/stdc++.h"
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    // (l, r)
    while (l + 2 < r) {
      int m = (l + r) >> 1;
      if (arr[m] <= arr[m - 1]) {
        r = m;
        continue ;
      }
      if (arr[m] > arr[m + 1])
        return m;
      else l = m;
    }
    return l + 1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
