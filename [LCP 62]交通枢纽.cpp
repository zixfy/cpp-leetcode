// 为了缓解「力扣嘉年华」期间的人流压力，组委会在活动期间开设了一些交通专线。`path[i]
// = [a, b]` 表示有一条从地点 `a`通往地点 `b` 的
//  **单向** 交通专线。
// 若存在一个地点，满足以下要求，我们则称之为 **交通枢纽**：
//- 所有地点（除自身外）均有一条 **单向** 专线 **直接** 通往该地点；
//- 该地点不存在任何 **通往其他地点** 的单向专线。
//
// 请返回交通专线的 **交通枢纽**。若不存在，则返回 `-1`。
//
//**注意：**
//- 对于任意一个地点，至少被一条专线连通。
//
//**示例 1：**
//
//> 输入：`path = [[0,1],[0,3],[1,3],[2,0],[2,3]]`
//>
//> 输出：`3`
//>
//> 解释：如下图所示：
//> 地点 `0,1,2` 各有一条通往地点 `3` 的交通专线，
//> 且地点 `3` 不存在任何**通往其他地点**的交通专线。
//> ![image.png](https://pic.leetcode-cn.com/1663902572-yOlUCr-image.png)
//
//**示例 2：**
//
//> 输入：`path = [[0,3],[1,0],[1,3],[2,0],[3,0],[3,2]]`
//>
//> 输出：`-1`
//>
//> 解释：如下图所示：不存在满足 **交通枢纽** 的地点。
//> ![image.png](https://pic.leetcode-cn.com/1663902595-McsEkY-image.png)
//
//**提示：**
//- `1 <= path.length <= 1000`
//- `0 <= path[i][0], path[i][1] <= 1000`
//- `path[i][0]` 与 `path[i][1]` 不相等
//
//  Related Topics 图 👍 8 👎 0

#include <bits/stdc++.h>
using namespace std;
// leetcode submit region begin(Prohibit modification and deletion)
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, const std::pair<U, V> &v) {
  return o << "(" << v.first << " " << v.second << ")";
}
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "span [";
  for (auto iter = v.begin(); iter != v.end(); ++iter)
    o << *iter << ((iter != v.end() - 1) ? ", " : "");
  return o << "]";
}

class Solution {
public:
  int transportationHub(vector<vector<int>> &path);
};
int Solution::transportationHub(vector<vector<int>> &path) {
  array<pair<int, int>, 1007> degs{};
  // (indeg, outdeg)
  int n{};
  for (const auto &p : path) {
    n = max(n, p[1]);
    n = max(n, p[0]);
    degs[p[0]].second++;
    degs[p[1]].first++;
  }
  ++n;
//  cout << "n: " << n << endl;
//  cout << vector(degs.begin(), degs.begin() + n) << endl;
  for (decltype(n) i{}; i < n; ++i) {
    if (degs[i].second == 0 && degs[i].first == n - 1)
      return i;
  }
  return -1;
}
// leetcode submit region end(Prohibit modification and deletion)
