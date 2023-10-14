// Range模块是跟踪数字范围的模块。设计一个数据结构来跟踪表示为 半开区间
// 的范围并查询它们。
//
//  半开区间 [left, right) 表示所有 left <= x < right 的实数 x 。
//
//  实现 RangeModule 类:
//
//
//  RangeModule() 初始化数据结构的对象。
//  void addRange(int left, int right) 添加 半开区间 [left,
//  right)，跟踪该区间中的每个实数。添加与当前跟踪的
// 数字部分重叠的区间时，应当添加在区间 [left, right)
// 中尚未跟踪的任何数字到该区间中。
//  boolean queryRange(int left, int right) 只有在当前正在跟踪区间 [left, right)
//  中的每一个实数时，才返
// 回 true ，否则返回 false 。
//  void removeRange(int left, int right) 停止跟踪 半开区间 [left, right)
//  中当前正在跟踪的每个实数。
//
//
//
//
//  示例 1：
//
//
// 输入
//["RangeModule", "addRange", "removeRange", "queryRange", "queryRange",
//"queryRange"]
//[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
// 输出
//[null, null, null, true, false, true]
//
// 解释
// RangeModule rangeModule = new RangeModule();
// rangeModule.addRange(10, 20);
// rangeModule.removeRange(14, 16);
// rangeModule.queryRange(10, 14); 返回 true （区间 [10, 14)
// 中的每个数都正在被跟踪） rangeModule.queryRange(13, 15); 返回
// false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样 的数字）
// rangeModule.queryRange(16, 17); 返回 true （尽管执行了删除操作，区间 [16, 17)
// 中的数字 16 仍然会被跟踪）
//
//
//
//
//
//  提示：
//
//
//  1 <= left < right <= 10⁹
//  在单个测试用例中，对 addRange 、 queryRange 和 removeRange 的调用总数不超过
//  10⁴ 次
//
//
//  Related Topics 设计 线段树 有序集合 👍 216 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

//
// Created by wwww on 2023/9/24.
//
#include "iostream"
#include "set"
using namespace std;
class RangeModule {
public:
  set<pair<int, int>> st;
  RangeModule() : st{} {}

  void addRange(int left, int right) {
    auto iter = st.upper_bound(make_pair(left, numeric_limits<int>::max()));
    if (iter != st.begin() && prev(iter)->second > left) {
      iter = prev(iter);
      left = iter->first;
      iter = st.erase(iter);
    }
    while (iter != st.end() && iter->first <= right) {
      right = max(right, iter->second);
      iter = st.erase(iter);
    }
    st.emplace(left, right);
//            for (auto& r: st)
//              cout << r.first << ", " << r.second << endl;cout << endl;
  }

  void removeRange(int left, int right) {
    auto iter = st.upper_bound(make_pair(left, numeric_limits<int>::max()));
    if (iter != st.begin()) {
      auto oit = prev(iter);
      auto [il, ir] = *oit;
      //          cout << il << ":" << ir << endl;
      if (right <= ir) {
        st.erase(oit);
        st.emplace(il, left);
        if (right < ir)
        st.emplace(right, ir);
//        for (auto& r: st)
//        cout << r.first << ", " << r.second << endl;
//        cout << endl;
        return;
      }
    }
    while (iter != st.end() && iter->second <= right) {
      iter = st.erase(iter);
    }
    auto prev_r = iter == st.begin() ? left : prev(iter)->second;
    auto prev_l = iter == st.begin() ? left : prev(iter)->first;
    auto next_l = iter == st.end() ? right : iter->first;
    auto next_r = iter == st.end() ? right : iter->second;
    if (prev_r > left)
      iter = st.erase(prev(iter));
    if (next_l < right)
      st.erase(iter);
    if (prev_r > left && prev_l < left)
      st.emplace(prev_l, left);
    if (next_l < right )
      st.emplace(right, next_r);

  }
  bool queryRange(int left, int right) {
//    for (auto& r: st)
//      cout << r.first << ", " << r.second << endl;
//    cout << endl;
    auto iter = st.upper_bound(make_pair(left, numeric_limits<int>::max()));
//    cout << "@" << iter->first << endl;
    if (iter == st.begin())
      return false;
//    cout
//        << (iter==st.end()) << ":" << right << endl;
    return prev(iter)->second >= right;
  }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// leetcode submit region end(Prohibit modification and deletion)
