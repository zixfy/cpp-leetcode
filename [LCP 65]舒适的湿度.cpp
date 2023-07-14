// 力扣嘉年华为了确保更舒适的游览环境条件，在会场的各处设置了湿度调节装置，这些调节装置受控于总控室中的一台控制器。
// 控制器中已经预设了一些调节指令，整数数组`operate[i]` 表示第 `i`
// 条指令增加空气湿度的大小。现在你可以将任意数量的指令修改为降低湿度（变化的
// 数值不变），以确保湿度尽可能的适宜：
//- 控制器会选择 **一段连续的指令** ，从而进行湿度调节的操作；
//- 这段指令最终对湿度影响的绝对值，即为当前操作的「不适宜度」
//- 在控制器所有可能的操作中，**最大** 的「不适宜度」即为「整体不适宜度」
//
// 请返回在所有修改指令的方案中，可以得到的 **最小** 「整体不适宜度」。
//
//**示例 1：**
//
//> 输入：`operate = [5,3,7]`
//>
//> 输出：`8`
//>
//> 解释：对于方案 `2` 的 `[5,3,-7]`
//> 操作指令 `[5],[3],[-7]` 的「不适宜度」分别为 `5,3,7`
//> 操作指令 `[5,3],[3,-7]` 的「不适宜度」分别为 `8,4`
//> 操作指令 `[5,3,-7]` 的「不适宜度」为 `1`，
//> 因此对于方案 `[5,3,-7]`的「整体不适宜度」为
//`8`，其余方案的「整体不适宜度」均不小于 `8`，如下表所示： >
//![image.png](https://pic.leetcode-cn.com/1663902759-dgDCxn-image.png)
//
//**示例 2：**
//
//> 输入：`operate = [20,10]`
//>
//> 输出：`20`
//
//**提示：**
//- `1 <= operate.length <= 1000`
//- `1 <= operate[i] <= 1000`
//
//  Related Topics 数组 动态规划 👍 14 👎 0

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
template <typename... Args, typename T> auto maxx(T fa, Args... args) {
  if constexpr (sizeof...(args) == 0)
    return fa;
  else
    return max(fa, maxx(args...));
}
template <typename... Args, typename T> auto print(T fa, Args... args) {
  cout << fa << ", ";
  if constexpr (sizeof...(args) > 0)
    print(args...);
  cout << endl;
}
class Solution {
public:
  int unSuitability(vector<int> &operate) {
    int ans = 0;
    const auto n = operate.size();
    int min_pos=0, max_neg=0;
    for (auto o : operate) {
      auto t1 = min_pos - o, t2 = max_neg + o;
      min_pos = max(min_pos, t2);
      max_neg = min(max_neg, t1);
      ans = max(ans, max(min_pos, -max_neg));
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
