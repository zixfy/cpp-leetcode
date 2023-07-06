// 力扣嘉年华将举办一系列展览活动，后勤部将负责为每场展览提供所需要的展台。
// 已知后勤部得到了一份需求清单，记录了近期展览所需要的展台类型， `demand[i][j]`
// 表示第 `i` 天展览时第 `j` 个展台的类型。
// 在满足每一天展台需求的基础上，请返回后勤部需要准备的 **最小** 展台数量。
//
//**注意：**
//- 同一展台在不同天中可以重复使用。
//
//**示例 1：**
//
//> 输入：`demand = ["acd","bed","accd"]`
//>
//> 输出：`6`
//>
//> 解释：
//> 第 `0` 天需要展台 `a、c、d`；
//> 第 `1` 天需要展台 `b、e、d`；
//> 第 `2` 天需要展台 `a、c、c、d`；
//> 因此，后勤部准备 `abccde` 的展台，可以满足每天的展览需求;
//
//**示例 2：**
//
//> 输入：`demand = ["abc","ab","ac","b"]`
//>
//> 输出：`3`
//
//**提示：**
//- `1 <= demand.length,demand[i].length <= 100`
//- `demand[i][j]` 仅为小写字母
//
//  Related Topics 数组 哈希表 字符串 计数 👍 7 👎 0

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
  int minNumBooths(vector<string> &demand) {
    unordered_map<char, size_t> ans;
    for (const auto &d : demand) {
      multiset cnt(d.begin(), d.end());
      for (auto c: cnt)
        ans[c] = max(ans[c], cnt.count(c));
    }
    int _ = 0;
    for (auto [k, v] : ans)
      _ += v;
    return _;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
