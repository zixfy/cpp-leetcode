//表： Employee 
//
// 
//+--------------+---------+
//| 列名          | 类型    |
//+--------------+---------+
//| id           | int     |
//| name         | varchar |
//| salary       | int     |
//| departmentId | int     |
//+--------------+---------+
//id是此表的主键列。
//departmentId是Department表中ID的外键。
//此表的每一行都表示员工的ID、姓名和工资。它还包含他们所在部门的ID。
// 
//
// 
//
// 表： Department 
//
// 
//+-------------+---------+
//| 列名         | 类型    |
//+-------------+---------+
//| id          | int     |
//| name        | varchar |
//+-------------+---------+
//id是此表的主键列。
//此表的每一行都表示一个部门的ID及其名称。
// 
//
// 
//
// 编写SQL查询以查找每个部门中薪资最高的员工。 按 任意顺序 返回结果表。 查询结果格式如下例所示。 
//
// 
//
// 示例 1: 
//
// 
//输入：
//Employee 表:
//+----+-------+--------+--------------+
//| id | name  | salary | departmentId |
//+----+-------+--------+--------------+
//| 1  | Joe   | 70000  | 1            |
//| 2  | Jim   | 90000  | 1            |
//| 3  | Henry | 80000  | 2            |
//| 4  | Sam   | 60000  | 2            |
//| 5  | Max   | 90000  | 1            |
//+----+-------+--------+--------------+
//Department 表:
//+----+-------+
//| id | name  |
//+----+-------+
//| 1  | IT    |
//| 2  | Sales |
//+----+-------+
//输出：
//+------------+----------+--------+
//| Department | Employee | Salary |
//+------------+----------+--------+
//| IT         | Jim      | 90000  |
//| Sales      | Henry    | 80000  |
//| IT         | Max      | 90000  |
//+------------+----------+--------+
//解释：Max 和 Jim 在 IT 部门的工资都是最高的，Henry 在销售部的工资最高。 
//
// Related Topics 数据库 👍 643 👎 0


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
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);
template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>);
template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p);
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v);

template <typename T, size_t... I>
void printTupleHelper(const T &tup, std::index_sequence<I...>) {
  ((std::cout << (I == 0 ? "" : ", ") << std::get<I>(tup)), ...);
}

template <typename... Args>
std::ostream &operator<<(std::ostream &o, const std::tuple<Args...> &tup) {
  o << "(";
  printTupleHelper(tup, std::make_index_sequence<sizeof...(Args)>());
  return o << ")" << std::endl;
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, std::unordered_map<U, V> p) {
  o << "map {";
  for (const auto &a : p)
    o << a.first << " : " << a.second << ", ";
  return o << "}\n";
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
  o << "vector [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
  o << "array [";
  for (const auto &a : v)
    cout << a << ", ";
  return o << "]";
}

//There is no code of C++ type for this problem



