// 实现一个 MyCalendar
// 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。
//
//  MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end
//  时间内增加一个日程安排，注意，这里
// 的时间是半开区间，即 [start, end), 实数 x 的范围为， start <= x < end。
//
//  当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。
//
//  每次调用
//  MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回
//  true。否则，返回 false 并且不要将该
// 日程安排添加到日历中。
//
//  请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar();
//  MyCalendar.book(
// start, end)
//
//
//
//  示例：
//
//  MyCalendar();
// MyCalendar.book(10, 20); // returns true
// MyCalendar.book(50, 60); // returns true
// MyCalendar.book(10, 40); // returns true
// MyCalendar.book(5, 15); // returns false
// MyCalendar.book(5, 10); // returns true
// MyCalendar.book(25, 55); // returns true
// 解释：
// 前两个日程安排可以添加至日历中。
// 第三个日程安排会导致双重预订，但可以添加至日历中。
// 第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
// 第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
// 第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40]
// 将和第三个日程安排双重预订； 时间 [40,50] 将单独预订，时间
// [50,55）将和第二个日程安排双重预订。
//
//
//
//
//  提示：
//
//
//  每个测试用例，调用 MyCalendar.book 函数最多不超过 1000次。
//  调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0,
//  10^9]。
//
//
//  Related Topics 设计 线段树 二分查找 有序集合 👍 223 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

//
// Created by wwww on 2023/9/24.
//

#ifndef CPP_ADVANCED_CONTAINER_TEMPLATE_DYNAMIC_SEGMENT_TREE_HPP
#define CPP_ADVANCED_CONTAINER_TEMPLATE_DYNAMIC_SEGMENT_TREE_HPP
#include <memory>
#include <vector>
template <typename T> class DynamicSegmentTree {
  struct Node {
    std::size_t range_left, range_right;
    T lazy_base, max;
    Node *left_child, *right_child;
  };
  std::vector<std::unique_ptr<Node>> _tree;

  inline void _update(Node *cur, T lazy) {
    cur->lazy_base += lazy;
    cur->max += lazy;
  }

  void _touch(Node *cur) {
    if (cur->left_child == nullptr) {
      auto middle =
          cur->range_left + ((cur->range_right - cur->range_left) >> 1);
      cur->left_child =
          new Node{cur->range_left, middle, T{}, cur->max, nullptr, nullptr};
      cur->right_child =
          new Node{middle, cur->range_right, T{}, cur->max, nullptr, nullptr};
      _tree.emplace_back(cur->left_child);
      _tree.emplace_back(cur->right_child);
      cur->lazy_base = {};
    }
    else  if (cur->lazy_base) {
      _update(cur->left_child, cur->lazy_base);
      _update(cur->right_child, cur->lazy_base);
      cur->lazy_base = {};
    }
  }

  void _range_add(Node *cur, std::size_t left, std::size_t right, T increment) {
    auto r = std::min(right, cur->range_right);
    auto l = std::max(left, cur->range_left);
    if (l >= r)
      ;
    else if (r == cur->range_right && l == cur->range_left) {
      _update(cur, increment);
    } else {
      _touch(cur);
      _range_add(cur->left_child, left, right, increment);
      _range_add(cur->right_child, left, right, increment);
      cur->max = std::max(cur->left_child->max, cur->right_child->max);
    }
  }

  T _range_max(Node *cur, std::size_t left, std::size_t right) {
    auto r = std::min(right, cur->range_right);
    auto l = std::max(left, cur->range_left);
    if (l >= r)
      return std::numeric_limits<T>::min();
    else if (r == cur->range_right && l == cur->range_left)
      return cur->max;
    _touch(cur);
    return std::max(_range_max(cur->left_child, left, right),
                    _range_max(cur->right_child, left, right));
  }

public:
  DynamicSegmentTree(std::size_t from, std::size_t to) : _tree{} {
    _tree.emplace_back(new Node{from, to, T{}, T{}, nullptr, nullptr});
  }

  inline void range_add(std::size_t left, std::size_t right, T increment) {
    _range_add(_tree.front().get(), left, right, increment);
  }

  inline T range_max(std::size_t left, std::size_t right) {
    return _range_max(_tree.front().get(), left, right);
  }
};
#endif // CPP_ADVANCED_CONTAINER_TEMPLATE_DYNAMIC_SEGMENT_TREE_HPP
using namespace std;
class MyCalendarTwo {
  DynamicSegmentTree<std::int16_t> sg;

public:
  MyCalendarTwo() : sg(0, 1e9 + 7) {}

  bool book(int start, int end) {
    auto maxi = sg.range_max(start, end);
//    cout << maxi << endl;
    if (maxi >= 2)
      return false;
    sg.range_add(start, end, 1);
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// leetcode submit region end(Prohibit modification and deletion)
