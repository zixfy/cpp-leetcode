// 完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 n 层有
// 2ⁿ⁻¹ 个节点）的，并且所有的节点都尽可能地集中在左侧。
//
//  设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：
//
//
//  CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
//  CBTInserter.insert(int v) 向树中插入一个新节点，节点类型为 TreeNode，值为 v
//  。使树保持完全二叉树的状态，并返回插入的
// 新节点的父节点的值；
//  CBTInserter.get_root() 将返回树的根节点。
//
//
//
//
//
//
//
//  示例 1：
//
//
// 输入：inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
// 输出：[null,1,[1,2]]
//
//
//  示例 2：
//
//
// 输入：inputs = ["CBTInserter","insert","insert","get_root"], inputs =
// [[[1,2,3,4, 5,6]],[7],[8],[]] 输出：[null,3,4,[1,2,3,4,5,6,7,8]]
//
//
//
//
//  提示：
//
//
//  最初给定的树是完全二叉树，且包含 1 到 1000 个节点。
//  每个测试用例最多调用 CBTInserter.insert 操作 10000 次。
//  给定节点或插入节点的每个值都在 0 到 5000 之间。
//
//
//
//
//
//  注意：本题与主站 919 题相同：
//  https://leetcode-cn.com/problems/complete-binary-tree-
// inserter/
//
//  Related Topics 树 广度优先搜索 设计 二叉树 👍 58 👎 0

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
class CBTInserter {
private:
  vector<TreeNode *> q;
  int cur_child_cnt = 0, cur_child_max;
  TreeNode *_root;

public:
  ~CBTInserter() {}
  CBTInserter(TreeNode *root) {
    q.push_back(root);
    _root = root;
    cur_child_max = 2;

    while (true) {
      for (auto p : q) {
        int c = (p->left != nullptr) + (p->right != nullptr);
        cur_child_cnt += c;
        if (c < 2)
          break;
      }
      if (cur_child_cnt < cur_child_max)
        break;
      vector<TreeNode *> nxt;
      nxt.reserve(cur_child_max);
      for (auto p : q)
        nxt.push_back(p->left), nxt.push_back(p->right);
      q.swap(nxt);
      cur_child_cnt = 0;
      cur_child_max <<= 1;
    }
  }

  int insert(int v) {
    auto par = q[cur_child_cnt >> 1];
    auto ret = par->val;
    auto & ref = ((cur_child_cnt & 1) ? par->right : par->left);
    ref = new TreeNode(v);

    ++cur_child_cnt;

//    cout << cur_child_cnt << endl;
    if (cur_child_cnt == cur_child_max) {
      vector<TreeNode *> nxt;
      nxt.reserve(cur_child_max);
      for (auto p : q)
        nxt.push_back(p->left), nxt.push_back(p->right);
      q.swap(nxt);
      cur_child_cnt = 0;
      cur_child_max <<= 1;
    }
    return ret;
  }

  TreeNode *get_root() { return _root; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
// leetcode submit region end(Prohibit modification and deletion)
