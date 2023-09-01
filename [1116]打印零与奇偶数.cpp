// 现有函数 printNumber 可以用一个整数参数调用，并输出该整数到控制台。
//
//
//  例如，调用 printNumber(7) 将会输出 7 到控制台。
//
//
//  给你类 ZeroEvenOdd 的一个实例，该类中有三个函数：zero、even 和 odd
//  。ZeroEvenOdd 的相同实例将会传递给三个不同线程：
//
//
//
//  线程 A：调用 zero() ，只输出 0
//  线程 B：调用 even() ，只输出偶数
//  线程 C：调用 odd() ，只输出奇数
//
//
//  修改给出的类，以输出序列 "010203040506..." ，其中序列的长度必须为 2n 。
//
//  实现 ZeroEvenOdd 类：
//
//
//  ZeroEvenOdd(int n) 用数字 n 初始化对象，表示需要输出的数。
//  void zero(printNumber) 调用 printNumber 以输出一个 0 。
//  void even(printNumber) 调用printNumber 以输出偶数。
//  void odd(printNumber) 调用 printNumber 以输出奇数。
//
//
//
//
//  示例 1：
//
//
// 输入：n = 2
// 输出："0102"
// 解释：三条线程异步执行，其中一个调用 zero()，另一个线程调用
// even()，最后一个线程调用odd()。正确的输出为 "0102"。
//
//
//  示例 2：
//
//
// 输入：n = 5
// 输出："0102030405"
//
//
//
//
//  提示：
//
//
//  1 <= n <= 1000
//
//
//  Related Topics 多线程 👍 149 👎 0

#include <bits/stdc++.h>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
// leetcode submit region begin(Prohibit modification and deletion)
using std::function;

class ZeroEvenOdd {
private:
  int n;
  int cur;
  std::mutex mut;
  std::condition_variable cv;

public:
  ZeroEvenOdd(int n) : n{n}, cur{0} {}

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; ++i) {
      std::unique_lock l(mut);
      cv.wait(l, [this] { return cur % 2 == 0; });
      printNumber(0);
      ++cur;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 0; i < n / 2; ++i) {
      std::unique_lock l(mut);
      cv.wait(l, [this] { return (cur + 1) % 4 == 0; });
      printNumber((cur + 1) / 2);
      ++cur;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 0; i < (n + 1) / 2; ++i) {
      std::unique_lock l(mut);
      cv.wait(l, [this] { return (cur + 3) % 4 == 0; });
      printNumber((cur + 1) / 2);
      ++cur;
      cv.notify_all();
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
