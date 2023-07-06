// 在英语中，有一个叫做 词根(root)
// 的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为
// 继承词(successor)。例如，词根an，跟 随着单词 other(其他)，可以形成新的单词
// another(另一个)。
//
//  现在，给定一个由许多词根组成的词典和一个句子，需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
//
//  需要输出替换之后的句子。
//
//
//
//  示例 1：
//
//
// 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by
// the battery"
// 输出："the cat was rat by the bat"
//
//
//  示例 2：
//
//
// 输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// 输出："a a b c"
//
//
//  示例 3：
//
//
// 输入：dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa
// aaa aaa aaaaaa bbb baba ababa" 输出："a a a a a a a a bbb baba a"
//
//
//  示例 4：
//
//
// 输入：dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was
// rattled by the battery"
// 输出："the cat was rat by the bat"
//
//
//  示例 5：
//
//
// 输入：dictionary = ["ac","ab"], sentence = "it is abnormal that this solution
// is accepted" 输出："it is ab that this solution is ac"
//
//
//
//
//  提示：
//
//
//  1 <= dictionary.length <= 1000
//  1 <= dictionary[i].length <= 100
//  dictionary[i] 仅由小写字母组成。
//  1 <= sentence.length <= 10^6
//  sentence 仅由小写字母和空格组成。
//  sentence 中单词的总量在范围 [1, 1000] 内。
//  sentence 中每个单词的长度在范围 [1, 1000] 内。
//  sentence 中单词之间由一个空格隔开。
//  sentence 没有前导或尾随空格。
//
//
//
//
//
//  注意：本题与主站 648 题相同：
//  https://leetcode-cn.com/problems/replace-words/
//
//  Related Topics 字典树 数组 哈希表 字符串 👍 38 👎 0
#include "bits/stdc++.h"
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}
class Trie {
private:
  static vector<char> _gen_charset(char a, char z) {
    vector<char> ans;
    while (a <= z)
      ans.push_back(a++);
    return ans;
  }
  static vector<char> a2z_charset;
  struct TrieNode {
    int cnt = 0;
    vector<TrieNode *> child;
    explicit TrieNode(int k) { child.resize(k, nullptr); }
    ~TrieNode() {
      for (auto c : child)
        delete c;
    }
  };
  const vector<char> &_cset;
  TrieNode *_root;

public:
  Trie(const vector<char> &cset) : _cset(cset) {
    _root = new TrieNode(_cset.size());
  };
  Trie() : Trie(a2z_charset){};
  ~Trie() { delete _root; }
  void print() {
    string a{};
    _print(_root, a);
  }
  void add(const string_view &s) {
    auto p = _root;
    for (auto c : s) {
      auto &nxt = p->child[c - _cset.front()];
      if (nxt == nullptr)
        nxt = new TrieNode(_cset.size());
      p = nxt;
    }
    p->cnt++;
  }
  void _print(TrieNode *cur, string &ostr) {
    if (cur->cnt > 0)
      cout << ostr << ": " << cur->cnt << endl;
    int idx = -1;
    for (auto c : cur->child) {
      idx++;
      if (c == nullptr)
        continue;
      ostr += _cset[idx];
      _print(c, ostr);
      ostr.pop_back();
    }
  }
  int shortest_prefix_length(const string_view &s) {
    auto p = _root;
    int ans = 0;
    for (auto c : s) {
      const auto &nxt = p->child[c - _cset.front()];
      if (nxt == nullptr)
        return s.length();
      p = nxt;
      ++ans;
      if (p->cnt > 0)
        return ans;
    }
    return s.length();
  }
};
auto Trie::a2z_charset = Trie::_gen_charset('a', 'z');
auto split(const string_view &s, const char sep = ' ') {
  std::vector<std::string_view> tokens;
  size_t start = 0;
  size_t end = s.find(sep);
  while (end != std::string_view::npos) {
    tokens.push_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find(sep, start);
  }
  if (start < s.length()) {
    tokens.emplace_back(s.begin() + start, s.length() - start);
  }
  return tokens;
}
class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {

    auto ss = split(sentence);
    auto t = Trie();
    for (const auto &w : dictionary)
      t.add(w);
    int i = 0;
    string ans;
    for (const auto &w : ss) {
      if (i)
        ans += ' ';
      ans += w.substr(0, t.shortest_prefix_length(w));
      ++i;
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
