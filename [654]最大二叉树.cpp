// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums
// 递归地构建:
//
//
//  创建一个根节点，其值为 nums 中的最大值。
//  递归地在最大值 左边 的 子数组前缀上 构建左子树。
//  递归地在最大值 右边 的 子数组后缀上 构建右子树。
//
//
//  返回 nums 构建的 最大二叉树 。
//
//
//
//  示例 1：
//
//
// 输入：nums = [3,2,1,6,0,5]
// 输出：[6,3,5,null,2,0,null,null,1]
// 解释：递归调用如下所示：
//- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//     - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//         - 空数组，无子节点。
//         - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//             - 空数组，无子节点。
//             - 只有一个元素，所以子节点是一个值为 1 的节点。
//     - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//         - 只有一个元素，所以子节点是一个值为 0 的节点。
//         - 空数组，无子节点。
//
//
//  示例 2：
//
//
// 输入：nums = [3,2,1]
// 输出：[3,null,2,null,1]
//
//
//
//
//  提示：
//
//
//  1 <= nums.length <= 1000
//  0 <= nums[i] <= 1000
//  nums 中的所有整数 互不相同
//
//
//  Related Topics 栈 树 数组 分治 二叉树 单调栈 👍 686 👎 0

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    vector<TreeNode *> stk;
    stk.push_back(new TreeNode(nums.front()));
    for (int i = 1, n = nums.size(); i < n; ++i) {
      auto num = nums[i];
      auto tp = new TreeNode(num);
      TreeNode *lef_p = nullptr;
      while (!stk.empty() && num > stk.back()->val) {
        stk.back()->right = lef_p;
        lef_p = stk.back();
        stk.pop_back();
      }
      tp->left = lef_p;
      stk.emplace_back(tp);
    }
    TreeNode *ans = nullptr;
    while (!stk.empty()) {
      stk.back()->right = ans;
      ans = stk.back();
      stk.pop_back();
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
