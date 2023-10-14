//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
//
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 916 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

void qSort(vector<int> &vec, int l, int r) {
    static std::random_device rd{};
    static std::mt19937 rng{rd()};
    if (l + 1 >= r)
        return;
    // [l, r)
    auto base = vec[l + rng() % (r - l)];
    auto p1 = l, p2 = r - 1;
    while (p1 <= p2) {
        if (vec[p1] < base || (vec[p1] == base && p1 - l < r  - p2))
            ++p1;
        else
            swap(vec[p1], vec[p2--]);
    }
    qSort(vec, l, p1);
    qSort(vec, p2 + 1, r);
}

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        qSort(nums, 0, nums.size());
        return std::move(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)




