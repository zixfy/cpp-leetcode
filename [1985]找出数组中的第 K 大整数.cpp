// 给你一个字符串数组 nums 和一个整数 k 。nums
// 中的每个字符串都表示一个不含前导零的整数。
//
//  返回 nums 中表示第 k 大整数的字符串。
//
//  注意：重复的数字在统计时会视为不同元素考虑。例如，如果 nums 是
//  ["1","2","2"]，那么 "2" 是最大的整数，"2" 是第二大的整数，"1
//" 是第三大的整数。
//
//
//
//  示例 1：
//
//
// 输入：nums = ["3","6","7","10"], k = 4
// 输出："3"
// 解释：
// nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
// 其中第 4 大整数是 "3"
//
//
//  示例 2：
//
//
// 输入：nums = ["2","21","12","1"], k = 3
// 输出："2"
// 解释：
// nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
// 其中第 3 大整数是 "2"
//
//
//  示例 3：
//
//
// 输入：nums = ["0","0"], k = 2
// 输出："0"
// 解释：
// nums 中的数字按非递减顺序排列为 ["0","0"]
// 其中第 2 大整数是 "0"
//
//
//
//
//  提示：
//
//
//  1 <= k <= nums.length <= 10⁴
//  1 <= nums[i].length <= 100
//  nums[i] 仅由数字组成
//  nums[i] 不含任何前导零
//
//
//  Related Topics 数组 字符串 分治 快速选择 排序 堆（优先队列） 👍 44 👎 0

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
template <typename T, typename Comp>
T _findKth(vector<T> &nums, int i, int j, int k, Comp cmp = less<T>()) {

  T base = nums[i];
  int p1 = i + 1, p2 = j + 1;
  while (p1 < p2) {
    if (cmp(nums[p1], base))
      ++p1;
    else if (cmp(base, nums[p1]))
      swap(nums[p1], nums[--p2]);
    else {
      if (rand() & 1)
        ++p1;
      else
        swap(nums[p1], nums[--p2]);
    }
  }
  swap(nums[i], nums[p1 - 1]);
  int cur_k = p1 - i;
  if (cur_k == k)
    return base;
  else if (cur_k > k)
    return _findKth(nums, i, p1 - 2, k, cmp);
  return _findKth(nums, p1, j, k - cur_k, cmp);
}
class Solution {
public:
  string kthLargestNumber(vector<string> &nums, int k) {
    std::srand(std::time(nullptr));
    auto f = [](const auto &a, const auto &b) {
      if (a.length() != b.length())
        return a.length() > b.length();
      return a > b;
    };
    sort(nums.begin(), nums.end(), f);
//    _findKth(nums, 0, nums.size() - 1, k, f);
    return nums[k - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
