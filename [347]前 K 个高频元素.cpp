// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k
// 高的元素。你可以按 任意顺序 返回答案。
//
//
//
//  示例 1:
//
//
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
//
//
//  示例 2:
//
//
// 输入: nums = [1], k = 1
// 输出: [1]
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  k 的取值范围是 [1, 数组中不相同的元素的个数]
//  题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//
//
//
//
//  进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
//
//  Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍
//  1560 👎 0

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
template <typename T, typename Comp>
T _findKth(vector<T> &nums, int i, int j, int k, Comp cmp = less<T>()) {

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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> cnt;
    for (auto n : nums)
      cnt[n]++;
    vector<pair<int, int>> ps;
    ps.reserve(nums.size());
    for (auto [key, val] : cnt)
      ps.emplace_back(key, val);

    _findKth(ps, 0, ps.size() - 1, k,
             [](const pair<int, int> &a, const pair<int, int> &b) {
               return a.second > b.second;
             });
//    cout << ps << endl;
    vector<int> ans;
    ans.reserve(k);
    for (int i = 0; i < k; ++i)
      ans.emplace_back(ps[i].first);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
