//给你一个下标从 0 开始的整数数组 nums 。 
//
// 现定义两个数字的 串联 是由这两个数值串联起来形成的新数字。 
//
// 
// 例如，15 和 49 的串联是 1549 。 
// 
//
// nums 的 串联值 最初等于 0 。执行下述操作直到 nums 变为空： 
//
// 
// 如果 nums 中存在不止一个数字，分别选中 nums 中的第一个元素和最后一个元素，将二者串联得到的值加到 nums 的 串联值 上，然后从 nums 
//中删除第一个和最后一个元素。 
// 如果仅存在一个元素，则将该元素的值加到 nums 的串联值上，然后删除这个元素。 
// 
//
// 返回执行完所有操作后 nums 的串联值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [7,52,2,4]
//输出：596
//解释：在执行任一步操作前，nums 为 [7,52,2,4] ，串联值为 0 。
// - 在第一步操作中：
//我们选中第一个元素 7 和最后一个元素 4 。
//二者的串联是 74 ，将其加到串联值上，所以串联值等于 74 。
//接着我们从 nums 中移除这两个元素，所以 nums 变为 [52,2] 。
// - 在第二步操作中： 
//我们选中第一个元素 52 和最后一个元素 2 。 
//二者的串联是 522 ，将其加到串联值上，所以串联值等于 596 。
//接着我们从 nums 中移除这两个元素，所以 nums 变为空。
//由于串联值等于 596 ，所以答案就是 596 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,14,13,8,12]
//输出：673
//解释：在执行任一步操作前，nums 为 [5,14,13,8,12] ，串联值为 0 。 
//- 在第一步操作中： 
//我们选中第一个元素 5 和最后一个元素 12 。 
//二者的串联是 512 ，将其加到串联值上，所以串联值等于 512 。 
//接着我们从 nums 中移除这两个元素，所以 nums 变为 [14,13,8] 。
//- 在第二步操作中：
//我们选中第一个元素 14 和最后一个元素 8 。
//二者的串联是 148 ，将其加到串联值上，所以串联值等于 660 。
//接着我们从 nums 中移除这两个元素，所以 nums 变为 [13] 。 
//- 在第三步操作中：
//nums 只有一个元素，所以我们选中 13 并将其加到串联值上，所以串联值等于 673 。
//接着我们从 nums 中移除这个元素，所以 nums 变为空。 
//由于串联值等于 673 ，所以答案就是 673 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 1 <= nums[i] <= 10⁴ 
// 
//
// Related Topics 数组 双指针 模拟 👍 7 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        auto ans = 0ll;
        const auto n = nums.size();
        array<long long, 5> bases{10, 100, 1000, 10000, 100000};
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
          int i = 0;
          for(auto n2 = nums[p2];bases[i] <= n2; ++i)
            ;
          ans += bases[i]*nums[p1] + nums[p2];
          p1++, p2--;
        }
        if (n & 1)
          ans += nums[n >> 1];
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




