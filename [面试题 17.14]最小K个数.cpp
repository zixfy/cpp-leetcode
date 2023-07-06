// 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
//
//  示例：
//
//  输入： arr = [1,3,5,7,2,4,6,8], k = 4
// 输出： [1,2,3,4]
//
//
//  提示：
//
//
//  0 <= len(arr) <= 100000
//  0 <= k <= min(100000, len(arr))
//
//
//  Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 216 👎 0

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
private:
  int _findKth(vector<int> &nums, int i, int j, int k) {

    int base = nums[i];
    int p1 = i + 1, p2 = j + 1;
    while (p1 < p2) {
      if (nums[p1] <= base)
        ++p1;
      else
        swap(nums[p1], nums[--p2]);
    }
    swap(nums[i], nums[p1 - 1]);
    int cur_k = p1 - i;
    if (cur_k == k)
      return base;
    else if (cur_k > k)
      return _findKth(nums, i, p1 - 2, k);
    return _findKth(nums, p1, j, k - cur_k);
  }

public:
  vector<int> smallestK(vector<int> &arr, int k) {
    if (k == 0)
      return {};
    _findKth(arr, 0, arr.size() - 1, k);
    return {arr.begin(), arr.begin() + k};
  }
};
// leetcode submit region end(Prohibit modification and deletion)
