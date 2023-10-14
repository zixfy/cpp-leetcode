// 你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k
// 个列表中的每个列表至少有一个数包含在其中。
//
//  我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d]
//  小。
//
//
//
//  示例 1：
//
//
// 输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// 输出：[20,24]
// 解释：
// 列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
// 列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
// 列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
//
//
//  示例 2：
//
//
// 输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
// 输出：[1,1]
//
//
//
//
//  提示：
//
//
//  nums.length == k
//  1 <= k <= 3500
//  1 <= nums[i].length <= 50
//  -10⁵ <= nums[i][j] <= 10⁵
//  nums[i] 按非递减顺序排列
//
//
//
//
//  Related Topics 贪心 数组 哈希表 排序 滑动窗口 堆（优先队列） 👍 401 👎 0

#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

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
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    using pT = pair<int, int>;
    vector<pT> all_points;

    all_points.reserve(std::accumulate(
        nums.begin(), nums.end(), size_t{0},
        [](auto acc, auto const &vec) { return acc + vec.size(); }));
    auto cmp = [&](pT const &a, pT const &b) {
      return nums[a.first][a.second] > nums[b.first][b.second];
    };
    priority_queue<pT, vector<pT>, decltype(cmp)> q(cmp);
    for (int i = 0; i < nums.size(); ++i)
      q.emplace(i, 0);
    while (!q.empty()) {
      auto [i, j] = q.top();
      all_points.emplace_back(nums[i][j], i);
      if (++j < nums[i].size())
        q.emplace(i, j);
      q.pop();
    }
    auto ans = vector{0, numeric_limits<int>::max()};
    unordered_map<int, int> cnt;
    int total = 0;
    for (int l = 0, r = 0; r < all_points.size(); ++r) {
      if (++cnt[all_points[r].second] == 1)
        ++total;
      while (total == nums.size()) {
        if (all_points[r].first - all_points[l].first < ans[1] - ans[0])
          ans[0] = all_points[l].first, ans[1] = all_points[r].first;
        if (--cnt[all_points[l++].second] == 0)
          --total;
      }
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
