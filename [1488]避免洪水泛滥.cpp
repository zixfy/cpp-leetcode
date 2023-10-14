// 你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 n
// 个湖泊下雨前是空的，那么它就会装满水。如果第 n 个湖泊下雨前是 满的
// ，这个湖泊会发生 洪水 。你 的目标是避免任意一个湖泊发生洪水。
//
//  给你一个整数数组 rains ，其中：
//
//
//  rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。
//  rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并 抽干
//  这个湖泊的水。
//
//
//  请返回一个数组 ans ，满足：
//
//
//  ans.length == rains.length
//  如果 rains[i] > 0 ，那么ans[i] == -1 。
//  如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。
//
//
//  如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个
//  空的数组 。
//
//  请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生。
//
//
//
//  示例 1：
//
//
// 输入：rains = [1,2,3,4]
// 输出：[-1,-1,-1,-1]
// 解释：第一天后，装满水的湖泊包括 [1]
// 第二天后，装满水的湖泊包括 [1,2]
// 第三天后，装满水的湖泊包括 [1,2,3]
// 第四天后，装满水的湖泊包括 [1,2,3,4]
// 没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
//
//
//  示例 2：
//
//
// 输入：rains = [1,2,0,0,2,1]
// 输出：[-1,-1,2,1,-1,-1]
// 解释：第一天后，装满水的湖泊包括 [1]
// 第二天后，装满水的湖泊包括 [1,2]
// 第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
// 第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
// 第五天后，装满水的湖泊包括 [2]。
// 第六天后，装满水的湖泊包括 [1,2]。
// 可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1]
// 也是另一个可行的没有洪水的方案。
//
//
//  示例 3：
//
//
// 输入：rains = [1,2,0,1,2]
// 输出：[]
// 解释：第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
// 但第三天后，湖泊 1 和 2
// 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
//
//
//
//
//  提示：
//
//
//  1 <= rains.length <= 10⁵
//  0 <= rains[i] <= 10⁹
//
//
//  Related Topics 贪心 数组 哈希表 二分查找 堆（优先队列） 👍 193 👎 0

#include <algorithm>
#include <array>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;

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
  vector<int> avoidFlood(vector<int> &rains) {
    using pT = pair<int, int>;
    auto n = rains.size();
    vector<int> ans;
    vector<pT> sparse;
    ans.reserve(n), sparse.reserve(n);
    std::transform(rains.begin(), rains.end(), back_inserter(sparse),
                   [i = 0](int x) mutable -> pT {
                     return {x, i++};
                   });
    std::sort(sparse.begin(), sparse.end());
    priority_queue<pT, vector<pT>, greater<>> q;
    unordered_map<int, bool> filled;
    int i = 0;
    for (auto rain : rains) {
      if (rain > 0) {
        if (filled[rain])
          return {};
        filled[rain] = true;
        auto iter =
            std::upper_bound(sparse.begin(), sparse.end(), make_pair(rain, i));
        if (iter != sparse.end() && iter->first == rain)
          q.emplace(iter->second, rain);
        ans.emplace_back(-1);
      } else {
        if (q.empty())
          ans.emplace_back(1);
        else {
          ans.emplace_back(q.top().second);
          filled[ans.back()] = false;
          q.pop();
        }
      }
//      cout << rain << ", " << q.size() << "@\n";
      ++i;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
