// 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
//
//
//  如果字符串的长度为 1 ，算法停止
//  如果字符串的长度 > 1 ，执行下述步骤：
//
//  在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s
//  ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。 随机
//  决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s
//  可能是 s = x + y 或者 s = y +
// x 。
//  在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
//
//
//
//  给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1
//  的扰乱字符串。如果是，返回 true ；否则，返回 false 。
//
//
//
//  示例 1：
//
//
// 输入：s1 = "great", s2 = "rgeat"
// 输出：true
// 解释：s1 上可能发生的一种情形是：
//"great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
//"gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
//"gr/eat" --> "g/r / e/at" //
// 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割 "g/r /
// e/at" --> "r/g / e/at" //
// 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
//"r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
//"r/g / e/ a/t" --> "r/g / e/ a/t" //
// 随机决定：「保持这两个子字符串的顺序不变」 算法终止，结果字符串和 s2
// 相同，都是 "rgeat" 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1
// 的扰乱字符串，返回 true
//
//
//  示例 2：
//
//
// 输入：s1 = "abcde", s2 = "caebd"
// 输出：false
//
//
//  示例 3：
//
//
// 输入：s1 = "a", s2 = "a"
// 输出：true
//
//
//
//
//  提示：
//
//
//  s1.length == s2.length
//  1 <= s1.length <= 30
//  s1 和 s2 由小写英文字母组成
//
//
//  Related Topics 字符串 动态规划 👍 521 👎 0

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
#include <bits/stdc++.h>

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
namespace std {
namespace {

template <class T> inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// Recursive template code derived from Matthieu M.
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  static void apply(size_t &seed, Tuple const &tuple) {
    HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
    hash_combine(seed, get<Index>(tuple));
  }
};

template <class Tuple> struct HashValueImpl<Tuple, 0> {
  static void apply(size_t &seed, Tuple const &tuple) {
    hash_combine(seed, get<0>(tuple));
  }
};
} // namespace
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")";
}

template <typename... TT> struct hash<std::tuple<TT...>> {
  size_t operator()(std::tuple<TT...> const &tt) const {
    size_t seed = 0;
    HashValueImpl<std::tuple<TT...>>::apply(seed, tt);
    return seed;
  }
};
} // namespace std

template <typename U>
std::ostream &operator<<(std::ostream &o, std::unordered_set<U> p) {
  o << "set {";
  for (const auto &a : p)
    o << a << ", ";
  return o << "}\n";
}
class Solution {
public:
  bool isScramble(string s1, string s2) {
    const auto n = s1.length();
    unordered_map<tuple<int, int, int>, bool> dp;
    function<bool(int, int, int, int)> dfs = [&](int l1, int r1, int l2,
                                                 int r2) -> int {
      if (l1 > r1)
        return false;
      auto t = make_tuple(l1, r1, l2);
      if (dp.count(t))
        return dp[t];
      auto &dp_cur = dp[t];
      if (l1 == r1)
        return dp_cur = (s1[l1] == s2[l2]);
      for (int p1 = l1, p2 = l2, p3 = r2; p1 < r1; ++p1, ++p2, --p3) {
        dp_cur |= (dfs(l1, p1, l2, p2) && dfs(p1 + 1, r1, p2 + 1, r2)) ||
                  (dfs(l1, p1, p3, r2) && dfs(p1 + 1, r1, l2, p3 - 1));
      }
      return dp_cur;
    };
    return dfs(0, n - 1, 0, n - 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
