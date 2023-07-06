// 给出一个整数数组 A 和一个查询数组 queries。
//
//  对于第 i 次查询，有 val = queries[i][0], index = queries[i][1]，我们会把 val
//  加到 A[index] 上
// 。然后，第 i 次查询的答案是 A 中偶数值的和。
//
//  （此处给定的 index = queries[i][1] 是从 0
//  开始的索引，每次查询都会永久修改数组 A。）
//
//  返回所有查询的答案。你的答案应当以数组 answer 给出，answer[i] 为第 i
//  次查询的答案。
//
//
//
//  示例：
//
//  输入：A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
// 输出：[8,6,2,4]
// 解释：
// 开始时，数组为 [1,2,3,4]。
// 将 1 加到 A[0] 上之后，数组为 [2,2,3,4]，偶数值之和为 2 + 2 + 4 = 8。
// 将 -3 加到 A[1] 上之后，数组为 [2,-1,3,4]，偶数值之和为 2 + 4 = 6。
// 将 -4 加到 A[0] 上之后，数组为 [-2,-1,3,4]，偶数值之和为 -2 + 4 = 2。
// 将 2 加到 A[3] 上之后，数组为 [-2,-1,3,6]，偶数值之和为 -2 + 6 = 4。
//
//
//
//
//  提示：
//
//
//  1 <= A.length <= 10000
//  -10000 <= A[i] <= 10000
//  1 <= queries.length <= 10000
//  -10000 <= queries[i][0] <= 10000
//  0 <= queries[i][1] < A.length
//
//
//  Related Topics 数组 模拟 👍 78 👎 0

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
  vector<int> sumEvenAfterQueries(vector<int> &nums,
                                  vector<vector<int>> &queries) {
    int ans = 0;
    for (auto n : nums)
      if (!(n & 1))
        ans += n;
    vector<int> aans;
    for (const auto &q : queries) {
      auto val = q[0], idx = q[1];
      nums[idx] += val;
      auto cur = nums[idx];
      if (val & 1) {
        if (cur & 1)
          ans -= (cur - val);
        else
          ans += cur;
      } else if (!(cur & 1))
        ans += val;
      aans.emplace_back(ans);
    }
    return aans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
