// 给你一个由正整数组成的数组 nums 。
//
//  数字序列的 最大公约数 定义为序列中所有整数的共有约数中的最大整数。
//
//
//  例如，序列 [4,6,16] 的最大公约数是 2 。
//
//
//  数组的一个 子序列
//  本质是一个序列，可以通过删除数组中的某些元素（或者不删除）得到。
//
//
//  例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
//
//
//  计算并返回 nums 的所有 非空 子序列中 不同 最大公约数的 数目 。
//
//
//
//  示例 1：
//
//
// 输入：nums = [6,10,3]
// 输出：5
// 解释：上图显示了所有的非空子序列与各自的最大公约数。
// 不同的最大公约数为 6 、10 、3 、2 和 1 。
//
//
//  示例 2：
//
//
// 输入：nums = [5,15,40,5,6]
// 输出：7
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 10⁵
//  1 <= nums[i] <= 2 * 10⁵
//
//
//  Related Topics 数组 数学 计数 数论 👍 159 👎 0

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
#include "bits/stdc++.h"
using namespace std;
constexpr vector<int> euler(int n) {
  vector<int> vis(n+1, 0), pris;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      pris.emplace_back(i);
    }
    for (auto pri: pris) {
      if (auto nxt = 1ll * i * pri; nxt > n)
        break;
      else
        vis[nxt] = 1;
      if (i % pri == 0)
        break;
    }
  }
  return pris;
}
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

class Solution {
public:
  int countDifferentSubsequenceGCDs(vector<int> &nums) {
    // 2 2 3 3 5
    //
    auto pri = euler(100);
    unordered_set<int> ans;


    return ans.size();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
