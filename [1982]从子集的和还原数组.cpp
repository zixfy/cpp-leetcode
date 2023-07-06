//存在一个未知数组需要你进行还原，给你一个整数 n 表示该数组的长度。另给你一个数组 sums ，由未知数组中全部 2ⁿ 个 子集的和 组成（子集中的元素没有
//特定的顺序）。 
//
// 返回一个长度为 n 的数组 ans 表示还原得到的未知数组。如果存在 多种 答案，只需返回其中 任意一个 。 
//
// 如果可以由数组 arr 删除部分元素（也可能不删除或全删除）得到数组 sub ，那么数组 sub 就是数组 arr 的一个 子集 。sub 的元素之和就是
// arr 的一个 子集的和 。一个空数组的元素之和为 0 。 
//
// 注意：生成的测试用例将保证至少存在一个正确答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3, sums = [-3,-2,-1,0,0,1,2,3]
//输出：[1,2,-3]
//解释：[1,2,-3] 能够满足给出的子集的和：
//- []：和是 0
//- [1]：和是 1
//- [2]：和是 2
//- [1,2]：和是 3
//- [-3]：和是 -3
//- [1,-3]：和是 -2
//- [2,-3]：和是 -1
//- [1,2,-3]：和是 0
//注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
// 
//
// 示例 2： 
//
// 
//输入：n = 2, sums = [0,0,0,0]
//输出：[0,0]
//解释：唯一的正确答案是 [0,0] 。
// 
//
// 示例 3： 
//
// 
//输入：n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
//输出：[0,-1,4,5]
//解释：[0,-1,4,5] 能够满足给出的子集的和。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 15 
// sums.length == 2ⁿ 
// -10⁴ <= sums[i] <= 10⁴ 
// 
//
// Related Topics 数组 分治 👍 46 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
template<typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
      sort(sums.begin(), sums.end());
      cout << "n="<<n<< " " << sums <<endl;
      if (n==2) {
        // 0, a, b, a + b
        if (sums[0]==0 || sums[3]==0)
          return {sums[1], sums[2]};
        return {sums[0], sums[3]};
        // -a 0 b-a b  or -a b-a 0 b
      }
      if (n==1)
        return {sums[0] == 0 ? sums[1] : sums[0]};
      int ele = sums.back() - sums[sums.size() / 2 - 1];
      vector temp(sums.begin(), sums.begin() + sums.size() / 2 );
      vector ans = recoverArray(n-1, temp);
      ans.emplace_back(ele);
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
