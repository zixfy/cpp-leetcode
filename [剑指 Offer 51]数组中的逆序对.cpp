// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
//
//
//
//  示例 1:
//
//  输入: [7,5,6,4]
// 输出: 5
//
//
//
//  限制：
//
//  0 <= 数组长度 <= 50000
//
//  Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 1007
//  👎 0

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

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int ans = 0;
    function<void(const int, const int)> merge_sort = [&](const int i,
                                                          const int j) {
      if (i >= j)
        return;
      auto m = (i + j) >> 1;
      merge_sort(i, m);
      merge_sort(m + 1, j);
      vector tmp(nums.begin() + i, nums.begin() + j + 1);
      int p1 = 0, p2 = m + 1 - i;
      int pivot = i;
      while (p1 <= m - i && p2 <= j - i) {
        if (tmp[p1] > tmp[p2])
          nums[pivot++] = tmp[p1++], ans += j - i - p2 + 1;
        else
          nums[pivot++] = tmp[p2++];
      }
      while (p1 <= m - i)
        nums[pivot++] = tmp[p1++];
      while (p2 <= j - i)
        nums[pivot++] = tmp[p2++];
    };
    merge_sort(0, nums.size() - 1);
//    cout << nums;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
