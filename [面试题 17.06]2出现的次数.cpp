// 编写一个方法，计算从 0 到 n (含 n) 中数字 2 出现的次数。
//
//  示例:
//
//  输入: 25
// 输出: 9
// 解释: (2, 12, 20, 21, 22, 23, 24, 25)(注意 22 应该算作两次)
//
//  提示：
//
//
//  n <= 10^9
//
//
//  Related Topics 递归 数学 动态规划 👍 70 👎 0

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
// #define $ auto

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Solution {
public:
  int numberOf2sInRange(int n) {
    vector<int> digits;
    while (n)
      digits.emplace_back(n % 10), n /= 10;
    // dp[i] = 2s of 0~10^{i}-1
    const auto digit_n = digits.size();
    vector<int> dp, exp10;
    dp.reserve(digit_n);
    exp10.reserve(digit_n);

    for (uint32_t i = 0, a = 0, b = 1; i < digit_n; ++i) {
      dp.emplace_back(a);
      exp10.emplace_back(b);
      a = a * 10 + b;
      b *= 10;
    }
    int idx = 0;
    int ans = 0;
    for (auto digit : digits) {
      ans += digit * dp[idx];
      if (digit == 2)
        ans += n + 1;
      else if (digit > 2)
        ans += exp10[idx];
      //      cout << ans << ", " << n << ", " << idx << endl;

      n += digits[idx] * exp10[idx];
      ++idx;
    }
    //        cout << dp << endl << exp10 << endl;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
