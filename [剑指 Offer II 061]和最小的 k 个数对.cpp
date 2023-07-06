// 给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。
//
//  定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
//
//  请找到和最小的 k 个数对 (u1,v1), (u2,v2) ... (uk,vk) 。
//
//
//
//  示例 1:
//
//
// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
//
//  示例 2:
//
//
// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//
//  示例 3:
//
//
// 输入: nums1 = [1,2], nums2 = [3], k = 3
// 输出: [1,3],[2,3]
// 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
//
//
//
//
//  提示:
//
//
//  1 <= nums1.length, nums2.length <= 10⁴
//  -10⁹ <= nums1[i], nums2[i] <= 10⁹
//  nums1, nums2 均为升序排列
//  1 <= k <= 1000
//
//
//
//
//
//  注意：本题与主站 373
//  题相同：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-
// sums/
//
//  Related Topics 数组 堆（优先队列） 👍 72 👎 0

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

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    using xy = pair<int, int>;
    auto f = [&nums1, &nums2](const auto &a, const auto &b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    priority_queue<xy, vector<xy>, function<bool(const xy &, const xy &)>> q(f);
    set<xy> vis;
    vector<vector<int>> ans;
    ans.reserve(k);
    q.emplace(0, 0);
//    vis.emplace(0, 0);
    for (int idx = 0; idx < k && !q.empty(); ++idx) {
      if (vis.count(q.top())) {
        q.pop();--idx;
        continue ;
      }
      vis.emplace(q.top());
      auto [i, j] = q.top();

      //      cout << q.size() << ", " << i << ", " << j << endl;
      if (i < nums1.size() - 1)
        q.emplace(i + 1, j);
      if (j < nums2.size() - 1)
        q.emplace(i, j + 1);
      ans.emplace_back(initializer_list<int>{nums1[i], nums2[j]});
      q.pop();
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)

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
