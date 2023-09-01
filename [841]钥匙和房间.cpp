// 有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0
// 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候
// 进入锁住的房间。
//
//  当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。
//
//  给你一个数组 rooms 其中 rooms[i] 是你进入 i
//  号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。
//
//
//
//
//
//
//  示例 1：
//
//
// 输入：rooms = [[1],[2],[3],[]]
// 输出：true
// 解释：
// 我们从 0 号房间开始，拿到钥匙 1。
// 之后我们去 1 号房间，拿到钥匙 2。
// 然后我们去 2 号房间，拿到钥匙 3。
// 最后我们去了 3 号房间。
// 由于我们能够进入每个房间，我们返回 true。
//
//
//  示例 2：
//
//
// 输入：rooms = [[1,3],[3,0,1],[2],[0]]
// 输出：false
// 解释：我们不能进入 2 号房间。
//
//
//
//
//  提示：
//
//
//  n == rooms.length
//  2 <= n <= 1000
//  0 <= rooms[i].length <= 1000
//  1 <= sum(rooms[i].length) <= 3000
//  0 <= rooms[i][j] < n
//  所有 rooms[i] 的值 互不相同
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 👍 324 👎 0

#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    auto n = rooms.size();
    using u8 = uint8_t;
    vector vis(n, u8{});
    queue<int> q;
    q.emplace(0), vis[0] = true;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto to: rooms[cur])
        if (!vis[to])
          vis[to] = true, q.emplace(to);
    }
    return *std::min_element(vis.begin(), vis.end());
  }
};
// leetcode submit region end(Prohibit modification and deletion)
