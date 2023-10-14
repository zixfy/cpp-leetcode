//现给定一个函数 fn ，一个参数数组 args 和一个以毫秒为单位的超时时间 t ，返回一个取消函数 cancelFn 。 
//
// 在经过 t 毫秒的延迟后，应该调用 fn 函数，并将 args 作为参数传递。除非 在 t 毫秒的延迟过程中，在 cancelT 毫秒时调用了 
//cancelFn。并且在这种情况下，fn 函数不应该被调用。 
//
// 示例 1: 
//
// 
//输入：fn = (x) => x * 5, args = [2], t = 20, cancelT = 50
//输出：[{"time": 20, "returned": 10}]
//解释：
//const cancel = cancellable((x) => x * 5, [2], 20); // fn(2) 在 t=20ms 时被调用
//setTimeout(cancel, 50);
//
//取消操作被安排在延迟了 cancelT（50毫秒）后进行，这发生在 fn(2) 在20毫秒时执行之后。 
//
// 示例 2： 
//
// 
//输入：fn = (x) => x**2, args = [2], t = 100, cancelT = 50
//输出：[]
//解释：
//const cancel = cancellable((x) => x**2, [2], 100); // fn(2) 没被调用
//setTimeout(cancel, 50);
//
//取消操作被安排在延迟了 cancelT（50毫秒）后进行，这发生在 fn(2) 在100毫秒时执行之前，导致 fn(2) 从未被调用。
// 
//
// 示例 3： 
//
// 
//输入：fn = (x1, x2) => x1 * x2, args = [2,4], t = 30, cancelTime = 100
//输出：[{"time": 30, "returned": 8}]
//解释：
//const cancel = cancellable((x1, x2) => x1 * x2, [2,4], 30); // fn(2,4) 在 t=30
//ms 时被调用
//setTimeout(cancel, 100);
//
//取消操作被安排在延迟了 cancelT（100毫秒）后进行，这发生在 fn(2,4) 在30毫秒时执行之后。
// 
//
// 
//
// 提示： 
//
// 
// fn 是一个函数 
// args 是一个有效的 JSON 数组 
// 1 <= args.length <= 10 
// 20 <= t <= 1000 
// 10 <= cancelT <= 1000 
// 
//
// 👍 3 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//There is no code of C++ type for this problem



