// 请你实现一个「数字乘积类」ProductOfNumbers，要求支持下述两种方法：
//
//  1. add(int num)
//
//
//  将数字 num 添加到当前数字列表的最后面。
//
//
//  2. getProduct(int k)
//
//
//  返回当前数字列表中，最后 k 个数字的乘积。
//  你可以假设当前列表中始终 至少 包含 k 个数字。
//
//
//  题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit
//  整数范围内，不会溢出。
//
//
//
//  示例：
//
//  输入：
//["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct",
//"getProduct","add","getProduct"]
//[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
//
// 输出：
//[null,null,null,null,null,null,20,40,0,null,32]
//
// 解释：
// ProductOfNumbers productOfNumbers = new ProductOfNumbers();
// productOfNumbers.add(3);        // [3]
// productOfNumbers.add(0);        // [3,0]
// productOfNumbers.add(2);        // [3,0,2]
// productOfNumbers.add(5);        // [3,0,2,5]
// productOfNumbers.add(4);        // [3,0,2,5,4]
// productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
// productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4
// = 40 productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2
// * 5 * 4 = 0 productOfNumbers.add(8);        // [3,0,2,5,4,8]
// productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32
//
//
//
//
//  提示：
//
//
//  add 和 getProduct 两种操作加起来总共不会超过 40000 次。
//  0 <= num <= 100
//  1 <= k <= 40000
//
//
//  Related Topics 设计 队列 数组 数学 数据流 👍 95 👎 0

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
class ProductOfNumbers {
private:
  using u32 = uint32_t;
  vector<u32> nums, lazy_val;
  int lazy_idx;

public:
  ProductOfNumbers() {}

  void add(int num) {
    nums.emplace_back(num);
    lazy_val.emplace_back(num);
    lazy_idx = nums.size() - 1;
  }

  int getProduct(int k) {
    int idx = nums.size() - k;
    if (idx >= lazy_idx)
      return nums[idx];
    u32 p = lazy_val[lazy_idx];
    int jdx = lazy_idx - 1;
    while (jdx >= idx) {
      nums[jdx] *= p;

      p *= lazy_val[jdx];
      lazy_val[jdx + 1] = 1;
      --jdx;
    }
    lazy_val[idx] = p;
    lazy_idx = idx;
//    cout << nums << endl << lazy_val << endl << lazy_idx << endl;
    return nums[idx];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// leetcode submit region end(Prohibit modification and deletion)
