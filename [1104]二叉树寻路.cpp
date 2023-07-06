// 在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之”
// 字形进行标记。
//
//  如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
//
//  而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
//
//
//
//  给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label
//  节点的路径，该路径是由途经的节点标号所组成的。
//
//
//
//  示例 1：
//
//  输入：label = 14
// 输出：[1,3,4,14]
//
//
//  示例 2：
//
//  输入：label = 26
// 输出：[1,2,6,10,26]
//
//
//
//
//  提示：
//
//
//  1 <= label <= 10^6
//
//
//  Related Topics 树 数学 二叉树 👍 195 👎 0

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
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
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
  vector<int> pathInZigZagTree(int label) {
    vector<int> ans;
    vector<pair<int, int>> dps;
    dps.emplace_back(1, 1);
    while (label > dps.back().second)
      dps.emplace_back(dps.back().second + 1,
                       dps.back().second +
                           ((dps.back().second - dps.back().first + 1) << 1));
//    cout << dps;
    while (label) {
      ans.emplace_back(label);
      auto [l, r] = dps.back();
      label = l + r - label;
      label >>= 1;
      dps.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
