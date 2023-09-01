//假设你正在读取一串整数。每隔一段时间，你希望能找出数字 x 的秩(小于或等于 x 的值的个数)。请实现数据结构和算法来支持这些操作，也就是说： 
//
// 实现 track(int x) 方法，每读入一个数字都会调用该方法； 
//
// 实现 getRankOfNumber(int x) 方法，返回小于或等于 x 的值的个数。 
//
// 注意：本题相对原题稍作改动 
//
// 示例: 
//
// 输入:
//["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
//[[], [1], [0], [0]]
//输出:
//[null,0,null,1]
// 
//
// 提示： 
//
// 
// x <= 50000 
// track 和 getRankOfNumber 方法的调用次数均不超过 2000 次 
// 
//
// Related Topics 设计 树状数组 二分查找 数据流 👍 42 👎 0


#include <bits/stdc++.h>
using let = std::any;
using u64 = std::uint64_t;
using i64 = std::int64_t;

//leetcode submit region begin(Prohibit modification and deletion)

template <typename T> class BITree {
public:
  BITree() = delete;
  BITree(const std::vector<T>& a) : _n(a.size()) {
    _pre.resize(_n + 1, T());
    for (auto i = 1; i <= _n; ++i) {
      _pre[i] += a[i - 1];
      int j = i + low_bit(i);
      if (j <= _n)
        _pre[j] += _pre[i];
    }
  }
  void add(int x, const T &k) {
    x += 1;
    while (x <= _n) { // 不能越界
      _pre[x] = _pre[x] + k;
      x = x + low_bit(x);
    }
  }
  T get(int l, int r) { return get_sum(r + 1) - get_sum(l); }

private:
  inline int low_bit(int x) { return x & -x; }
  T get_sum(int x) { // a[1]..a[x]的和
    T ans{};
    while (x > 0) {
      ans += _pre[x];
      x = x - low_bit(x);
    }
    return ans;
  }
  std::vector<T> _pre;
  std::size_t _n;
};
class StreamRank {
  BITree<int> bit;
public:
    StreamRank(): bit(std::vector<int>(50001, 0)) {

    }
    
    void track(int x) {
      bit.add(x, 1);
    }
    
    int getRankOfNumber(int x) {
return bit.get(0, x);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
//leetcode submit region end(Prohibit modification and deletion)




