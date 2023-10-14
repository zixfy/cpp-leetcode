// 布尔表达式 是计算结果不是 true 就是 false
// 的表达式。有效的表达式需遵循以下约定：
//
//
//  't'，运算结果为 true
//  'f'，运算结果为 false
//  '!(subExpr)'，运算过程为对内部表达式 subExpr 进行 逻辑非（NOT）运算
//  '&(subExpr1, subExpr2, ..., subExprn)'，运算过程为对 2 个或以上内部表达式
//  subExpr1, subExpr2,
//  ..., subExprn 进行 逻辑与（AND）运算
//  '|(subExpr1, subExpr2, ..., subExprn)'，运算过程为对 2 个或以上内部表达式
//  subExpr1, subExpr2,
//  ..., subExprn 进行 逻辑或（OR）运算
//
//
//  给你一个以字符串形式表述的 布尔表达式 expression，返回该式的运算结果。
//
//  题目测试用例所给出的表达式均为有效的布尔表达式，遵循上述约定。
//
//
//
//  示例 1：
//
//
// 输入：expression = "&(|(f))"
// 输出：false
// 解释：
// 首先，计算 |(f) --> f ，表达式变为 "&(f)" 。
// 接着，计算 &(f) --> f ，表达式变为 "f" 。
// 最后，返回 false 。
//
//
//  示例 2：
//
//
// 输入：expression = "|(f,f,f,t)"
// 输出：true
// 解释：计算 (false OR false OR false OR true) ，结果为 true 。
//
//
//  示例 3：
//
//
// 输入：expression = "!(&(f,t))"
// 输出：true
// 解释：
// 首先，计算 &(f,t) --> (false AND true) --> false --> f ，表达式变为 "!(f)" 。
// 接着，计算 !(f) --> NOT false --> true ，返回 true 。
//
//
//
//
//  提示：
//
//
//  1 <= expression.length <= 2 * 10⁴
//  expression[i] 为 '('、')'、'&'、'|'、'!'、't'、'f' 和 ',' 之一
//
//
//  Related Topics 栈 递归 字符串 👍 198 👎 0

#include <algorithm>
#include <array>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
#include "stack"
#include "variant"
using namespace std;
class Solution {
public:
  enum class State { Expr, Not, Or, And };
  bool parseBoolExpr(string expression) {
    auto pivot = 0;
    stack<pair<bool, State>> stack;
    stack.emplace(false, State::Expr);
    while (!stack.empty()) {
      auto &[res, state] = stack.top();
      if (expression[pivot] == ')')
        ++pivot;
      else if (expression[pivot] == 't') {
        ++pivot;
        res = true;
      } else if (expression[pivot] == 'f') {
        ++pivot;
        res = false;
      } else if (expression[pivot] == '!') {
        state = State::Not;
        pivot += 2;
        stack.emplace(false, State::Expr);
        continue;
      } else if (expression[pivot] == '&') {
        state = State::And;
        res = true;
        pivot += 2;
        stack.emplace(false, State::Expr);
        continue;
      } else {
        state = State::Or;
        pivot += 2;
        stack.emplace(false, State::Expr);
        continue;
      }

      //      cout << "pivot= " << pivot;
      //      cout << " res = " << res << ", state =" << int(state) << endl;
      if (stack.size() == 1)
        return res;
      auto tmp = res;

      //?
      stack.pop();
      auto &[lres, lst] = stack.top();
      if (lst == State::Not)
        lres = !tmp;
      else if (lst == State::Or)
        lres |= tmp;
      else if (lst == State::And)
        lres &= tmp;
      if (expression[pivot] == ',') {
        ++pivot;
        stack.emplace(false, State::Expr);
      }
    }
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
