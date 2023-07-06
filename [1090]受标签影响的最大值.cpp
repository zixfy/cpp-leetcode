// 我们有一个 n 项的集合。给出两个整数数组 values 和 labels ，第 i
// 个元素的值和标签分别是 values[i] 和 labels[i]。还 会给出两个整数 numWanted 和
// useLimit 。
//
//  从 n 个元素中选择一个子集 s :
//
//
//  子集 s 的大小 小于或等于 numWanted 。
//  s 中 最多 有相同标签的 useLimit 项。
//
//
//  一个子集的 分数 是该子集的值之和。
//
//  返回子集 s 的最大 分数 。
//
//
//
//  示例 1：
//
//
// 输入：values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
// 输出：9
// 解释：选出的子集是第一项，第三项和第五项。
//
//
//  示例 2：
//
//
// 输入：values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
// 输出：12
// 解释：选出的子集是第一项，第二项和第三项。
//
//
//  示例 3：
//
//
// 输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
// 输出：16
// 解释：选出的子集是第一项和第四项。
//
//
//
//
//  提示：
//
//
//  n == values.length == labels.length
//  1 <= n <= 2 * 10⁴
//  0 <= values[i], labels[i] <= 2 * 10⁴
//  1 <= numWanted, useLimit <= n
//
//
//  Related Topics 贪心 数组 哈希表 计数 排序 👍 30 👎 0

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

template <typename T, typename Comp=less<T>>
T _findKth(vector<T> &nums, int i, int j, int k, Comp cmp = {}) {

  T base = nums[i];
  int p1 = i + 1, p2 = j + 1;
  while (p1 < p2) {
    if (cmp(nums[p1], base))
      ++p1;
    else
      swap(nums[p1], nums[--p2]);
  }
  swap(nums[i], nums[p1 - 1]);
  int cur_k = p1 - i;
  if (cur_k == k)
    return base;
  else if (cur_k > k)
    return _findKth(nums, i, p1 - 2, k, cmp);
  return _findKth(nums, p1, j, k - cur_k, cmp);
}
class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> candidates;
    const auto n = values.size();
    for (int i = 0; i < n; ++i) {
      auto &candi = candidates[labels[i]];
      candi.push(values[i]);
      if (candi.size() > useLimit)
        candi.pop();
    }
    vector<int> ans;
    ans.reserve(n);
    for (auto &[_, candi] : candidates)
      while (!candi.empty()) {
        ans.emplace_back(candi.top());
        candi.pop();
      }
    numWanted = min(numWanted, static_cast<int>(ans.size()));
    _findKth(ans, 0, ans.size() - 1, numWanted, greater<int>());
    return accumulate(ans.begin(), ans.begin() + numWanted, 0);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
