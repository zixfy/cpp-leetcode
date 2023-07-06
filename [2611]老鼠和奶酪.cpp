// 有两只老鼠和 n 块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。
//
//  下标为 i 处的奶酪被吃掉的得分为：
//
//
//  如果第一只老鼠吃掉，则得分为 reward1[i] 。
//  如果第二只老鼠吃掉，则得分为 reward2[i] 。
//
//
//  给你一个正整数数组 reward1 ，一个正整数数组 reward2 ，和一个非负整数 k 。
//
//  请你返回第一只老鼠恰好吃掉 k 块奶酪的情况下，最大 得分为多少。
//
//
//
//  示例 1：
//
//
// 输入：reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
// 输出：15
// 解释：这个例子中，第一只老鼠吃掉第 2 和 3 块奶酪（下标从 0
// 开始），第二只老鼠吃掉第 0 和 1 块奶酪。 总得分为 4 + 4 + 3 + 4 = 15 。 15
// 是最高得分。
//
//
//  示例 2：
//
//
// 输入：reward1 = [1,1], reward2 = [1,1], k = 2
// 输出：2
// 解释：这个例子中，第一只老鼠吃掉第 0 和 1 块奶酪（下标从 0
// 开始），第二只老鼠不吃任何奶酪。 总得分为 1 + 1 = 2 。 2 是最高得分。
//
//
//
//
//  提示：
//
//
//  1 <= n == reward1.length == reward2.length <= 10⁵
//  1 <= reward1[i], reward2[i] <= 1000
//  0 <= k <= n
//
//
//  Related Topics 贪心 数组 排序 堆（优先队列） 👍 41 👎 0

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
  o << "[";
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
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    const auto n = reward1.size();
    vector<int> tmp;
    tmp.reserve(n);
    generate_n(back_inserter(tmp), n, [i = 0]() mutable { return i++; });
    std::nth_element(tmp.begin(), tmp.begin() + k - 1, tmp.end(),
                     [&reward1, &reward2](int const &a, int const &b) {
                       return reward1[a] - reward2[a] > reward1[b] - reward2[b];
                     });
    auto ans = 0;
    for (int i = 0; i < k; i++)
      ans += reward1[tmp[i]];
    for (int i = k; i < n; i++)
      ans += reward2[tmp[i]];
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
