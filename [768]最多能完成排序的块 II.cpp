// 给你一个整数数组 arr 。
//
//  将 arr 分割成若干 块
//  ，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
//
//  返回能将数组分成的最多块数？
//
//  示例 1：
//
//
// 输入：arr = [5,4,3,2,1]
// 输出：1
// 解释：
// 将数组分成2块或者更多块，都无法得到所需的结果。
// 例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。
//
//
//  示例 2：
//
//
// 输入：arr = [2,1,3,4,4]
// 输出：4
// 解释：
// 可以把它分成两块，例如 [2, 1], [3, 4, 4]。
// 然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。
//
//
//
//
//  提示：
//
//
//  1 <= arr.length <= 2000
//  0 <= arr[i] <= 10⁸
//
//
//  Related Topics 栈 贪心 数组 排序 单调栈 👍 288 👎 0

#include <algorithm>
#include <array>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
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
  int maxChunksToSorted(vector<int> &arr) {
    auto ans = 0;
    stack<int> st;
    for (auto a : arr) {
      if (st.empty() || st.top() <= a) {
        st.emplace(a);
        continue ;
      }
      else {
        auto cur = st.top();
        while (!st.empty() && st.top() > a)
          st.pop();
        st.emplace(cur);
      }
    }

    return st.size()  ;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
