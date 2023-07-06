// 存在一个由 n 个不同元素组成的整数数组 nums
// ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。
//
//  给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个
//  adjacentPairs[i] = [ui, vi] 表示元素
// ui 和 vi 在 nums 中相邻。
//
//  题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于
//  adjacentPairs 中，存在形式可能是 [nums[i]
//, nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序
// 出现。
//
//  返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
//
//
//
//  示例 1：
//
//
// 输入：adjacentPairs = [[2,1],[3,4],[3,2]]
// 输出：[1,2,3,4]
// 解释：数组的所有相邻元素对都在 adjacentPairs 中。
// 特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
//
//
//  示例 2：
//
//
// 输入：adjacentPairs = [[4,-2],[1,4],[-3,1]]
// 输出：[-2,4,1,-3]
// 解释：数组中可能存在负数。
// 另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
//
//
//  示例 3：
//
//
// 输入：adjacentPairs = [[100000,-100000]]
// 输出：[100000,-100000]
//
//
//
//
//  提示：
//
//
//  nums.length == n
//  adjacentPairs.length == n - 1
//  adjacentPairs[i].length == 2
//  2 <= n <= 10⁵
//  -10⁵ <= nums[i], ui, vi <= 10⁵
//  题目数据保证存在一些以 adjacentPairs 作为元素对的数组 nums
//
//
//  Related Topics 数组 哈希表 👍 118 👎 0

#include <bits/stdc++.h>
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
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>);
template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);

template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    const auto n = adjacentPairs.size() + 1;
    if (n==2)
      return adjacentPairs.front();
    vector<int> ans(n);
    int p1 = 0, p2 = n - 1;
    unordered_map<int, vector<int>> adjs;
    for (const auto &a : adjacentPairs)
      adjs[a[0]].emplace_back(a[1]), adjs[a[1]].emplace_back(a[0]);
    unordered_set<int> vis;
    vector<int> tmp;
    for (const auto &[k, v] : adjs)
      if (v.size() == 1)
        tmp.emplace_back(k);

    int head = tmp[0], tail = tmp[1];
    while (p1 <= p2) {
      vis.emplace(head), vis.emplace(tail);
      ans[p1] = head;
      ans[p2] = tail;
      auto tmp = vis.count(adjs[head][0]) ? adjs[head][1] : adjs[head][0];
      head = tmp;
      tmp = vis.count(adjs[tail][0]) ? adjs[tail][1] : adjs[tail][0];
      tail = tmp;
      p1++, p2--;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
