// 当 k 个日程安排有一些时间上的交叉时（例如 k
// 个日程安排都在同一时间内），就会产生 k 次预订。
//
//  给你一些日程安排 [start, end) ，请你在每个日程安排添加后，返回一个整数 k
//  ，表示所有先前日程安排会产生的最大 k 次预订。
//
//  实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。
//
//
//  MyCalendarThree() 初始化对象。
//  int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k
//  次预订的最大值。
//
//
//
//
//  示例：
//
//
// 输入：
//["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
//[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
// 输出：
//[null, 1, 1, 2, 3, 3, 3]
//
// 解释：
// MyCalendarThree myCalendarThree = new MyCalendarThree();
// myCalendarThree.book(10, 20); // 返回 1
// ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
// myCalendarThree.book(50, 60); // 返回 1
// ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
// myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40)
// 与第一个日程安排相交，所以最大 k 次预订是
//  2 次预订。
// myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3
// 次预订。 myCalendarThree.book(5, 10); // 返回 3 myCalendarThree.book(25, 55);
// // 返回 3
//
//
//
//
//  提示：
//
//
//  0 <= start < end <= 10⁹
//  每个测试用例，调用 book 函数最多不超过 400次
//
//
//  Related Topics 设计 线段树 二分查找 有序集合 👍 205 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)

using namespace std;

class SegTree {
private:
  unordered_map<int, int> tree, lazy;
  int mini, maxi;

public:
  SegTree(int m1, int m2) : mini(m1), maxi(m2) {}
  void update(int ql, int qr, int val) { _update(ql, qr, val, mini, maxi, 1); }
  int query(int ql, int qr) { return _query(ql, qr, mini, maxi, 1); }

private:
  void _update(int ql, int qr, int val, int cl, int cr, int node) {
    if (ql > cr || qr < cl) {
      return;
    } else if (ql <= cl && cr <= qr) {

      tree[node] += val;
      lazy[node] += val;
    } else {
      int left_node = node * 2, right_node = node * 2 + 1;
      int mid = (cl + cr) >> 1;
      _update(ql, qr, val, cl, mid, left_node);
      _update(ql, qr, val, mid + 1, cr, right_node);
      tree[node] = lazy[node] + max(tree[left_node], tree[right_node]);
    }
  }

  int _query(int ql, int qr, int cl, int cr, int node) {
    auto overlap = (min(qr, cr) - max(ql, cl) + 1);
    if (overlap <= 0) {
      return 0;
    } else if (overlap == cr - cl + 1) {
      return tree[node];
    }
    int left_node = node * 2, right_node = node * 2 + 1;
    int mid = (cl + cr) >> 1;
    return lazy[node] + max(_query(ql, qr, cl, mid, left_node),
                            _query(ql, qr, mid + 1, cr, right_node));
  }
};

class MyCalendarThree {
  SegTree t;

public:
  MyCalendarThree() : t(0, 1e9) {}

  int book(int startTime, int endTime) {
    t.update(startTime, endTime - 1, 1);
    return t.query(0, 1e9);
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// leetcode submit region end(Prohibit modification and deletion)
