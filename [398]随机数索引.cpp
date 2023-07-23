// 给你一个可能含有 重复元素 的整数数组 nums ，请你随机输出给定的目标数字 target
// 的索引。你可以假设给定的数字一定存在于数组中。
//
//  实现 Solution 类：
//
//
//  Solution(int[] nums) 用数组 nums 初始化对象。
//  int pick(int target) 从 nums 中选出一个满足 nums[i] == target 的随机索引 i
//  。如果存在多个有效的索引，则每
// 个索引的返回概率应当相等。
//
//
//
//
//  示例：
//
//
// 输入
//["Solution", "pick", "pick", "pick"]
//[[[1, 2, 3, 3, 3]], [3], [1], [3]]
// 输出
//[null, 4, 0, 2]
//
// 解释
// Solution solution = new Solution([1, 2, 3, 3, 3]);
// solution.pick(3); // 随机返回索引 2, 3 或者 4
// 之一。每个索引的返回概率应该相等。 solution.pick(1); // 返回 0 。因为只有
// nums[0] 等于 1 。 solution.pick(3); // 随机返回索引 2, 3 或者 4
// 之一。每个索引的返回概率应该相等。
//
//
//
//
//
//
//
//  提示：
//
//
//
//
//
//  1 <= nums.length <= 2 * 10⁴
//  -2³¹ <= nums[i] <= 2³¹ - 1
//  target 是 nums 中的一个整数
//  最多调用 pick 函数 10⁴ 次
//
//
//
//
//
//
//  Related Topics 水塘抽样 哈希表 数学 随机化 👍 268 👎 0

#include <bits/stdc++.h>
using namespace std;

auto recursive_lambda = [](auto &&lam) {
  return [lam_impl = lam](auto &&...args) {
    return lam_impl(lam_impl, std::forward<decltype(args)>(args)...);
  };
};

// leetcode submit region begin(Prohibit modification and deletion)

#include <ctime>
#include <random>
#include <vector>
class FibRandInt {
  std::vector<unsigned> vec;
  int l, j, k, cur;

public:
  FibRandInt(int l, int j, int k) : l(l), j(j), k(k), cur(0) {
    std::mt19937 rd(std::time(nullptr));
    for (int i = 0; i < l; i++)
      vec.push_back(rd());
  }

  unsigned next() {
    auto ret = vec[cur] = vec[(cur - j + l) % l] ^ (vec[(cur - k + l) % l] << 1);
    cur = (cur + 1) % l;
    return ret;
  }
};
class Solution {
private:
  unordered_map<int, vector<int>> dict;
  FibRandInt fri;

public:
  Solution(vector<int> &nums) : dict{}, fri{107, 37, 89} {
    for (int i = 0, n = nums.size(); i < n; ++i)
      dict[nums[i]].emplace_back(i);
  }

  int pick(int target) {
    const auto &idx = dict[target];
    return idx[fri.next() % idx.size()];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// leetcode submit region end(Prohibit modification and deletion)
