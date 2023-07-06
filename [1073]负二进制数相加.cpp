// 给出基数为 -2 的两个数 arr1 和 arr2，返回两数相加的结果。
//
//  数字以 数组形式 给出：数组由若干 0 和 1
//  组成，按最高有效位到最低有效位的顺序排列。例如，arr = [1,1,0,1] 表示数字
//  (-2)^3 +
//  (-2)^2 + (-2)^0 = -3。数组形式 中的数字 arr 也同样不含前导零：即 arr == [0]
//  或 arr[0] == 1。
//
//  返回相同表示形式的 arr1 和 arr2
//  相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。
//
//
//
//  示例 1：
//
//
// 输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]
// 输出：[1,0,0,0,0]
// 解释：arr1 表示 11，arr2 表示 5，输出表示 16 。
//
//
//
//
//
//  示例 2：
//
//
// 输入：arr1 = [0], arr2 = [0]
// 输出：[0]
//
//
//  示例 3：
//
//
// 输入：arr1 = [0], arr2 = [1]
// 输出：[1]
//
//
//
//
//  提示：
//
//
//
//  1 <= arr1.length, arr2.length <= 1000
//  arr1[i] 和 arr2[i] 都是 0 或 1
//  arr1 和 arr2 都没有前导0
//
//
//  Related Topics 数组 数学 👍 75 👎 0

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
  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    // 01 + 01 = -(-2)^{i+1} = (-2)^{i+2} + (-2)^{i+1} = 110
    // 01 + 00 = 01 = (-2) ^ i
    // 00 + 00 = 00 = 0
    // => 1 + 1 = 110
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    if (arr2.size() > arr1.size())
      arr1.swap(arr2);
    auto adder = [&arr1](int idx) {
      while (idx >= arr1.size())
        arr1.push_back(0);
      arr1[idx]++;
    };
    auto try_minus = [&arr1](int idx) {
      if (idx < arr1.size() && arr1[idx] > 0) {
        arr1[idx]--;
        return true;
      }
      return false;
    };
    for (int i = 0; i < arr1.size(); ++i) {
      if (i < arr2.size())
        arr1[i] += arr2[i];
      if (arr1[i] == 2) {
        arr1[i] = 0;
        if (!try_minus(i+1)) {
          adder(i + 1);
          adder(i + 2);
        }
        // 4 - 2
      } else if (arr1[i] == 3) {
        arr1[i] = 1;
        if (!try_minus(i+1)) {
          adder(i + 1);
          adder(i + 2);
        }
        // 1 -2 4
      } else if (arr1[i] == 4) {
        arr1[i] = 0;
        adder(i + 2);
        // 4
      }
    }
    while (arr1.size() > 1 && arr1.back() == 0)
      arr1.pop_back();
    reverse(arr1.begin(), arr1.end());
    return arr1;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
