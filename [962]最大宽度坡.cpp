// 给定一个整数数组 A，坡是元组 (i, j)，其中 i < j 且 A[i] <=
// A[j]。这样的坡的宽度为 j - i。
//
//  找出 A 中的坡的最大宽度，如果不存在，返回 0 。
//
//
//
//  示例 1：
//
//  输入：[6,0,8,2,1,5]
// 输出：4
// 解释：
// 最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
//
//
//  示例 2：
//
//  输入：[9,8,1,0,1,9,4,0,4,1]
// 输出：7
// 解释：
// 最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.
//
//
//
//
//  提示：
//
//
//  2 <= A.length <= 50000
//  0 <= A[i] <= 50000
//
//
//
//
//  Related Topics 栈 数组 单调栈 👍 224 👎 0

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
  int maxWidthRamp(vector<int> &nums) {
    using xy = pair<int, int>;
    vector<xy> stk;
    stk.emplace_back(0, nums.front());
    const auto n = nums.size();
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      const auto cur = nums[i];
      if (cur < stk.back().second)
        stk.emplace_back(i, cur);
      else {
        int l = -1, r = stk.size() - 1;
        while (l + 1 < r) {
          auto m = (l + r) >> 1;
          auto val = stk[m].second;
          if (val <= cur)
            r = m;
          else l = m;
        }
        ans = max(ans, i - stk[r].first);
        // (l, r]
      }
    }

    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
