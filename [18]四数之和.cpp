// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
// 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[ b], nums[c],
// nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//
//
//  0 <= a, b, c, d < n
//  a、b、c 和 d 互不相同
//  nums[a] + nums[b] + nums[c] + nums[d] == target
//
//
//  你可以按 任意顺序 返回答案 。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,0,-1,0,-2,2], target = 0
// 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//
//
//  示例 2：
//
//
// 输入：nums = [2,2,2,2,2], target = 8
// 输出：[[2,2,2,2]]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 200
//  -10⁹ <= nums[i] <= 10⁹
//  -10⁹ <= target <= 10⁹
//
//
//  Related Topics 数组 双指针 排序 👍 1578 👎 0

#include <iostream>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)

template <typename... Args> struct tuple_hash {
  size_t operator()(const std::tuple<Args...> &t) const {
    return hash_impl(t, std::index_sequence_for<Args...>());
  }

private:
  template <size_t... Idx>
  size_t hash_impl(const std::tuple<Args...> &t,
                   std::index_sequence<Idx...>) const {
    return (std::hash<Args>{}(std::get<Idx>(t)) ^ ...);
  }
};

template <typename... T> struct tuple_equal {
  bool operator()(const std::tuple<T...> &t1,
                  const std::tuple<T...> &t2) const {
    return compare_impl(t1, t2, std::index_sequence_for<T...>());
  }

private:
  template <size_t... Idx>
  bool compare_impl(const std::tuple<T...> &t1, const std::tuple<T...> &t2,
                    std::index_sequence<Idx...>) const {
    return ((std::get<Idx>(t1) == std::get<Idx>(t2)) && ...);
  }
};

template <typename... Args>
using my_hashset = std::unordered_set<std::tuple<Args...>, tuple_hash<Args...>,
                                      tuple_equal<Args...>>;
class Solution {
public:
  auto fourSum(vector<int> &nums, int target) {
    using t4 = tuple<int, int, int, int>;
    //      unordered_set<t4, tuple_hash<int, int ,int ,int>, tuple_equal<int,
    //      int ,int ,int>> cnt;
    sort(nums.begin(), nums.end());
    remove_reference<decltype(nums)>::type tem;
    int las{numeric_limits<int>::min()};
    int cur{};
    for (const auto num : nums) {
      if (las != num) {
        cur = 1;
      } else
        ++cur;
      if (cur < 5)
        tem.emplace_back(num);
      las = num;
    }
    nums.swap(tem);

    my_hashset<int, int, int, int> cnt;
    //    decltype(cnt) a;
    unordered_map<int, vector<pair<int, int>>> sum2ij;
    vector<vector<int>> ans;
    const auto n{nums.size()};
    for (auto i{0}; i < n; ++i)
      for (auto j{i + 1}; j < n; ++j)
        sum2ij[nums[i] + nums[j]].emplace_back(i, j);
    for (auto i{0}; i < n; ++i)
      for (auto j{i + 1}; j < n; ++j) {
        auto base = nums[i] + nums[j];
        long long _  = 0ll + target - base;
        if (_ <= INT_MAX && _ >= INT_MIN)
        for (const auto &[x, y] : sum2ij[target - base])
          if (x > j) {
            auto t = make_tuple(nums[i], nums[j], nums[x], nums[y]);
            if (!cnt.count(t)) {
              cnt.insert(t);
              ans.emplace_back(initializer_list<int>{get<0>(t), get<1>(t),
                                                     get<2>(t), get<3>(t)});
            }
          }
      }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
