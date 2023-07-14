//在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你
//会得到一张含有有效单词的列表。映射如下图所示： 
//
// 
//
// 示例 1: 
//
// 输入: num = "8733", words = ["tree", "used"]
//输出: ["tree", "used"]
// 
//
// 示例 2: 
//
// 输入: num = "2", words = ["a", "b", "c", "d"]
//输出: ["a", "b", "c"] 
//
// 提示： 
//
// 
// num.length <= 1000 
// words.length <= 500 
// words[i].length == num.length 
// num中不会出现 0, 1 这两个数字 
// 
//
// Related Topics 数组 哈希表 字符串 👍 37 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




