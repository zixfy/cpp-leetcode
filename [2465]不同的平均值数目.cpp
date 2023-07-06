//给你一个下标从 0 开始长度为 偶数 的整数数组 nums 。 
//
// 只要 nums 不是 空数组，你就重复执行以下步骤： 
//
// 
// 找到 nums 中的最小值，并删除它。 
// 找到 nums 中的最大值，并删除它。 
// 计算删除两数的平均值。 
// 
//
// 两数 a 和 b 的 平均值 为 (a + b) / 2 。 
//
// 
// 比方说，2 和 3 的平均值是 (2 + 3) / 2 = 2.5 。 
// 
//
// 返回上述过程能得到的 不同 平均值的数目。 
//
// 注意 ，如果最小值或者最大值有重复元素，可以删除任意一个。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [4,1,4,0,3,5]
//输出：2
//解释：
//1. 删除 0 和 5 ，平均值是 (0 + 5) / 2 = 2.5 ，现在 nums = [4,1,4,3] 。
//2. 删除 1 和 4 ，平均值是 (1 + 4) / 2 = 2.5 ，现在 nums = [4,3] 。
//3. 删除 3 和 4 ，平均值是 (3 + 4) / 2 = 3.5 。
//2.5 ，2.5 和 3.5 之中总共有 2 个不同的数，我们返回 2 。
// 
//
// 示例 2： 
//
// 输入：nums = [1,100]
//输出：1
//解释：
//删除 1 和 100 后只有一个平均值，所以我们返回 1 。
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 100 
// nums.length 是偶数。 
// 0 <= nums[i] <= 100 
// 
//
// Related Topics 数组 哈希表 双指针 排序 👍 24 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
        const auto n = nums.size();
        int p1 =0, p2=n-1;
        unordered_set<int> ans;
        while (p1 < p2)
          ans.emplace(nums[p1++] + nums[p2--]);
        return ans.size();

    }
};
//leetcode submit region end(Prohibit modification and deletion)




