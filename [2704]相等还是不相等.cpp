//请你编写一个名为 expect 的函数，用于帮助开发人员测试他们的代码。它应该接受任何值 val 并返回一个包含以下两个函数的对象。 
//
// 
// toBe(val) 接受另一个值并在两个值相等（ === ）时返回 true 。如果它们不相等，则应抛出错误 "Not Equal" 。 
// notToBe(val) 接受另一个值并在两个值不相等（ !== ）时返回 true 。如果它们相等，则应抛出错误 "Equal" 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：func = () => expect(5).toBe(5)
//输出：{"value": true}
//解释：5 === 5 因此该表达式返回 true。
// 
//
// 示例 2： 
//
// 
//输入：func = () => expect(5).toBe(null)
//输出：{"error": "Not Equal"}
//解释：5 !== null 因此抛出错误 "Not Equal".
// 
//
// 示例 3： 
//
// 
//输入：func = () => expect(5).notToBe(null)
//输出：{"value": true}
//解释：5 !== null 因此该表达式返回 true.
// 
//
// 👍 3 👎 0


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

//There is no code of C++ type for this problem



