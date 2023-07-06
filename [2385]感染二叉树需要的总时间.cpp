// 给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数
// start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发 。
//
//  每分钟，如果节点满足以下全部条件，就会被感染：
//
//
//  节点此前还没有感染。
//  节点与一个已感染节点相邻。
//
//
//  返回感染整棵树需要的分钟数。
//
//
//
//  示例 1：
//  输入：root = [1,5,3,null,4,10,6,9,2], start = 3
// 输出：4
// 解释：节点按以下过程被感染：
//- 第 0 分钟：节点 3
//- 第 1 分钟：节点 1、10、6
//- 第 2 分钟：节点5
//- 第 3 分钟：节点 4
//- 第 4 分钟：节点 9 和 2
// 感染整棵树需要 4 分钟，所以返回 4 。
//
//
//  示例 2：
//  输入：root = [1], start = 1
// 输出：0
// 解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
//
//
//
//
//  提示：
//
//
//  树中节点的数目在范围 [1, 10⁵] 内
//  1 <= Node.val <= 10⁵
//  每个节点的值 互不相同
//  树中必定存在值为 start 的节点
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 38 👎 0

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
  int amountOfTime(TreeNode *root, int start) {
    int ans = 0;
    function<int(TreeNode *, int)> dfs = [&](TreeNode *cur, int par_tim) {
      if (cur == nullptr)
        return -1;
      int cur_tim = par_tim > -1 ? par_tim + 1 : par_tim;
      if (cur->val == start)
        cur_tim = 0;
      if (cur_tim >= 0) {

        dfs(cur->left, cur_tim);
        dfs(cur->right, cur_tim);
      } else {
        auto t1 = dfs(cur->left, cur_tim);
        auto t2 = dfs(cur->right, cur_tim);
        if (t1 > -1) {
          cur_tim = t1 + 1;
          dfs(cur->right, cur_tim);
        } else if (t2 > -1) {
          cur_tim = t2 + 1;
          dfs(cur->left, cur_tim);
        }
      }
      ans = max(cur_tim, ans);
      return cur_tim;
    };
    dfs(root, -1);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
