// 给你一个下标从 0 开始的整数数组 nums 。如果一对整数 x 和 y
// 满足以下条件，则称其为 强数对 ：
//
//
//  |x - y| <= min(x, y)
//
//
//  你需要从 nums
//  中选出两个整数，且满足：这两个整数可以形成一个强数对，并且它们的按位异或（XOR）值是在该数组所有强数对中的
//  最大值 。
//
//  返回数组 nums 所有可能的强数对中的 最大 异或值。
//
//  注意，你可以选择同一个整数两次来形成一个强数对。
//
//
//
//  示例 1：
//
//
// 输入：nums = [1,2,3,4,5]
// 输出：7
// 解释：数组 nums 中有 11 个强数对：(1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3,
// 3), (3, 4), (3, 5), (4, 4), (4, 5) 和 (5, 5) 。 这些强数对中的最大异或值是 3
// XOR 4 = 7 。
//
//
//  示例 2：
//
//
// 输入：nums = [10,100]
// 输出：0
// 解释：数组 nums 中有 2 个强数对：(10, 10) 和 (100, 100) 。
// 这些强数对中的最大异或值是 10 XOR 10 = 0 ，数对 (100, 100) 的异或值也是 100
// XOR 100 = 0 。
//
//
//  示例 3：
//
//
// 输入：nums = [500,520,2500,3000]
// 输出：1020
// 解释：数组 nums 中有 6 个强数对：(500, 500), (500, 520), (520, 520), (2500,
// 2500), (2500, 3000) 和 (3000, 3000) 。 这些强数对中的最大异或值是 500 XOR 520
// = 1020 ；另一个异或值非零的数对是 (5, 6) ，其异或值是 2500 XOR 3000 = 6 36 。
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 5 * 10⁴
//  1 <= nums[i] <= 2²⁰ - 1
//
//
//  Related Topics 位运算 字典树 数组 哈希表 滑动窗口 👍 10 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include "vector"
using namespace std;
struct BinaryTrie {
  constexpr static std::size_t depth = 20;
  struct Node {
    int size;
    Node *zero, *one;
    ~Node() {
      delete zero;
      delete one;
    }
  };
  Node root;

  using uz = std::size_t;
  void add(int x) {
    auto pivot = &root;
    for (uz i = depth; i-- > 0;) {
      auto &what = (x & (1 << i)) ? pivot->one : pivot->zero;
      if (what == nullptr)
        what = new Node{0, nullptr, nullptr};
      what->size++;
      pivot = what;
    }
  }
  void remove(int x) {
    auto pivot = &root;
    for (uz i = depth; i-- > 0;) {
      auto &what = (x & (1 << i)) ? pivot->one : pivot->zero;
      what->size--;
      pivot = what;
    }
  }
  int maxXorOf(int x) {
    int ret = 0;
    auto pivot = &root;
    for (uz i = depth; i-- > 0;) {
      auto digit = (x & (1 << i));
      if (digit) {
        if (pivot->zero != nullptr and pivot->zero->size > 0) {
          ret |= 1 << i;
          pivot = pivot->zero;
        } else
          pivot = pivot->one;
      } else {
        if (pivot->one != nullptr and pivot->one->size > 0) {
          ret |= 1 << i;
          pivot = pivot->one;
        } else
          pivot = pivot->zero;
      }
    }

    return ret;
  }
};
#include "algorithm"
class Solution {
public:
  int maximumStrongPairXor(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int l = 0, r = 0;
    auto tree = BinaryTrie();
    // [l, r)
    int ans = 0;
    while (r < nums.size()) {
      tree.add(nums[r]);
      while (nums[l] * 2 < nums[r]) {
        tree.remove(nums[l]);
        l++;
      }

      ans = max(ans, tree.maxXorOf(nums[r]));
      ++r;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
