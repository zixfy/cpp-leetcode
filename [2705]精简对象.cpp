//现给定一个对象或数组 obj，返回一个 精简对象 。精简对象 与原始对象相同，只是将包含 假 值的键移除。该操作适用于对象及其嵌套对象。数组被视为索引作为键
//的对象。当 Boolean(value) 返回 false 时，值被视为 假 值。 
//
// 你可以假设 obj 是 JSON.parse 的输出结果。换句话说，它是有效的 JSON。 
//
// 
//
// 示例 1： 
//
// 
//输入：obj = [null, 0, false, 1]
//输出：[1]
//解释：数组中的所有假值已被移除。
// 
//
// 示例 2： 
//
// 
//输入：obj = {"a": null, "b": [false, 1]}
//输出：{"b": [1]}
//解释：obj["a"] 和 obj["b"][0] 包含假值，因此被移除。 
//
// 示例 3： 
//
// 
//输入：obj = [null, 0, 5, [0], [false, 16]]
//输出：[5, [], [16]]
//解释：obj[0], obj[1], obj[3][0], 和 obj[4][0] 包含假值，因此被移除。
// 
//
// 
//
// 提示： 
//
// 
// obj 是一个有效的 JSON 对象 
// 2 <= JSON.stringify(obj).length <= 10⁶ 
// 
//
// 👍 0 👎 0


#include <bits/stdc++.h>

//There is no code of C++ type for this problem



