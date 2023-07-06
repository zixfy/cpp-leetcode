// 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中
// courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi
// 天课，并且必须在不晚于 lastDayi 的时候完成。
//
//  你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
//
//  返回你最多可以修读的课程数目。
//
//
//
//  示例 1：
//
//
// 输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
// 输出：3
// 解释：
// 这里一共有 4 门课程，但是你最多可以修 3 门：
// 首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
// 第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
// 第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
// 第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
//
//  示例 2：
//
//
// 输入：courses = [[1,2]]
// 输出：1
//
//
//  示例 3：
//
//
// 输入：courses = [[3,2],[4,3]]
// 输出：0
//
//
//
//
//  提示:
//
//
//  1 <= courses.length <= 10⁴
//  1 <= durationi, lastDayi <= 10⁴
//
//
//  Related Topics 贪心 数组 堆（优先队列） 👍 398 👎 0

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
  o << "[";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    auto cmp = [](const auto &a, const auto &b) { return a[1] < b[1]; };
    std::sort(courses.begin(), courses.end(), cmp);
    priority_queue<int> q;
    int tim_sumy = 0;
    int ans = 0;
    for (const auto &c : courses) {
      auto dur = c[0], ed = c[1];
      if (auto nxt_tim_sum = tim_sumy + dur; nxt_tim_sum <= ed)
        ++ans, tim_sumy = nxt_tim_sum, q.push(dur);
      else if (!q.empty() && q.top() > dur) {
        tim_sumy -= q.top() - dur;
        q.pop();
        q.push(dur);
      }
//      cout << tim_sumy << endl;
    }
//    cout << courses << endl;
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
