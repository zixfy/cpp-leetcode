//给你一个 rows x cols 大小的矩形披萨和一个整数 k ，矩形包含两种字符： 'A' （表示苹果）和 '.' （表示空白格子）。你需要切披萨 k-1
// 次，得到 k 块披萨并送给别人。 
//
// 切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平
//地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。 
//
// 请你返回确保每一块披萨包含 至少 一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：pizza = ["A..","AAA","..."], k = 3
//输出：3 
//解释：上图展示了三种切披萨的方案。注意每一块披萨都至少包含一个苹果。
// 
//
// 示例 2： 
//
// 输入：pizza = ["A..","AA.","..."], k = 3
//输出：1
// 
//
// 示例 3： 
//
// 输入：pizza = ["A..","A..","..."], k = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= rows, cols <= 50 
// rows == pizza.length 
// cols == pizza[i].length 
// 1 <= k <= 10 
// pizza 只包含字符 'A' 和 '.' 。 
// 
//
// Related Topics 记忆化搜索 数组 动态规划 矩阵 👍 85 👎 0
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
template<typename T, std::size_t N>
class Array {
public:
  template<typename... Args>
  T& operator()(Args... args) {
    return data_[index(std::make_tuple(args...))];
  }
  template<typename... Args>
  const T& operator()(Args... args) const {
    return data_[index(std::make_tuple(args...))];
  }
public:
  Array(const std::array<std::size_t, N>& dims)
      : dims_(dims) {
    std::size_t size = 1;
    for (std::size_t i = 0; i < N; ++i) {
      size *= dims[i];
    }
    data_.resize(size);
  }
private:
  std::array<std::size_t, N> dims_;
  std::vector<T> data_;
private:
  template<typename Tuple, std::size_t... Is>
  std::size_t index_impl(const Tuple& t, std::index_sequence<Is...>) const {
    std::size_t result = (std::get<Is>(t) * ... * dims_[N - 1 - Is]);
    return result;
  }
public:
  template<typename Tuple>
  std::size_t index(const Tuple& t) const {
    return index_impl(t, std::make_index_sequence<N>{});
  }
};
//int main() {
//  Array<int, 2> a{{3, 4}};
//  for (int i = 0; i < 3; ++i) {
//    for (int j = 0; j < 4; ++j) {
//      a(i, j) = i * 4 + j;
//    }
//  }
//  for (int i = 0; i < 3; ++i) {
//    for (int j = 0; j < 4; ++j) {
//      std::cout << a(i, j) << " ";
//    }
//    std::cout << "\n";
//  }
//  return 0;
//}

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int ways(vector<string>& pizza, int k) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
