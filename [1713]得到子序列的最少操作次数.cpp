// 给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr
// 可能 包含重复元素。
//
//  每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr =
//  [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,
// 2] 。你可以在数组最开始或最后面添加整数。
//
//  请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。
//
//  一个数组的 子序列
//  指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，[2,7,4]
//  是 [4,2,3,
// 7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。
//
//
//
//  示例 1：
//
//  输入：target = [5,1,3], arr = [9,4,2,3,4]
// 输出：2
// 解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr
// 的子序列。
//
//
//  示例 2：
//
//  输入：target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
// 输出：3
//
//
//
//
//  提示：
//
//
//  1 <= target.length, arr.length <= 10⁵
//  1 <= target[i], arr[i] <= 10⁹
//  target 不包含任何重复元素。
//
//
//  Related Topics 贪心 数组 哈希表 二分查找 👍 203 👎 0

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

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

// leetcode submit region begin(Prohibit modification and deletion)

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template<typename T>
int binary_search(const vector<T>& arr, const T& x) {
  // (l, r)
  int l = -1, r = arr.size();
  while (l + 1 < r) {
    auto m = (l + r) >> 1;
    const auto& mid_val = arr[m];
    cout << l << ", " << r << ", " << m << ", " << mid_val << endl;
    if (mid_val == x)
      return m;
    if (mid_val > x)
      r = m;
    else l = m;
  }
  return -1;
}
class Solution {
public:
  int minOperations(vector<int> &target, vector<int> &arr) {
    vector<int> dp;
    binary_search(arr, 6);
    for (auto t: target)
      dp.emplace_back(binary_search(arr, t));
    int old_len = target.size();
    cout << dp <<endl;
    return old_len - dp.size();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
