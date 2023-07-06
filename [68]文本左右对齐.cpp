// 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有
// maxWidth 个字符，且左右两端对齐的文本。
//
//  你应该使用 “贪心算法”
//  来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' '
//  填充，使得每行恰好有 maxWidth 个字符。
//
//
//  要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
//
//  文本的最后一行应为左对齐，且单词之间不插入额外的空格。
//
//  注意:
//
//
//  单词是指由非空格字符组成的字符序列。
//  每个单词的长度大于 0，小于等于 maxWidth。
//  输入单词数组 words 至少包含一个单词。
//
//
//
//
//  示例 1:
//
//
// 输入: words = ["This", "is", "an", "example", "of", "text",
// "justification."], maxWidth = 16 输出:
//[
//    "This    is    an",
//    "example  of text",
//    "justification.  "
//]
//
//
//  示例 2:
//
//
// 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth =
// 16 输出:
//[
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
//]
// 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
//      因为最后一行应为左对齐，而不是左右两端对齐。
//      第二行同样为左对齐，这是因为这行只包含一个单词。
//
//
//  示例 3:
//
//
// 输入:words = ["Science","is","what","we","understand","well","enough","to",
//"explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth
//= 2
// 0
// 输出:
//[
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
//]
//
//
//
//
//  提示:
//
//
//  1 <= words.length <= 300
//  1 <= words[i].length <= 20
//  words[i] 由小写英文字母和符号组成
//  1 <= maxWidth <= 100
//  words[i].length <= maxWidth
//
//
//  Related Topics 数组 字符串 模拟 👍 334 👎 0

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
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ans;
    string row;
    row.reserve(maxWidth);
    vector<const string *> stk;
    int row_space_needed = 0;
    for (const string &w : words) {
      int nxt_w = row_space_needed + w.length();
      if (nxt_w + stk.size() > maxWidth) {
        int blank_space = maxWidth - row_space_needed;
        if (stk.size() < 2)
          ans.emplace_back(*(stk.front()) + string(blank_space, ' '));
        else {
          int i = 0;
          int q = blank_space / (stk.size() - 1);
          int r = blank_space % (stk.size() - 1);
          for (auto pw : stk) {
            if (i != 0)
              row += string(q + (i - 1 < r), ' ');
            row += *pw;
            i++;
          }
          ans.emplace_back(row);
          row.clear();
        }
        stk.clear();
        row_space_needed = w.length();
      }
      else row_space_needed = nxt_w;
//      row_space_needed += w.;
      stk.push_back(&w);
    }
    int i = 0;
    for (auto pw : stk) {
      if (i != 0)
        row.push_back(' ');
      row += *pw;
      i++;
    }
    row += string(maxWidth - row.length(), ' ');
    ans.emplace_back(row);
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
