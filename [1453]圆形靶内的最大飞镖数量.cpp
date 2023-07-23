//Alice 向一面非常大的墙上掷出 n 支飞镖。给你一个数组 darts ，其中 darts[i] = [xi, yi] 表示 Alice 掷出的第 i 支
//飞镖落在墙上的位置。 
//
// Bob 知道墙上所有 n 支飞镖的位置。他想要往墙上放置一个半径为 r 的圆形靶。使 Alice 掷出的飞镖尽可能多地落在靶上。 
//
// 给你整数 r ，请返回能够落在 任意 半径为 r 的圆形靶内或靶上的最大飞镖数。 
//
// 
//
// 示例 1 ： 
// 
// 
//输入：darts = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
//输出：4
//解释：如果圆形靶的圆心为 (0,0) ，半径为 2 ，所有的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 4 。
// 
//
// 示例 2 ： 
// 
// 
//输入：darts = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
//输出：5
//解释：如果圆形靶的圆心为 (0,4) ，半径为 5 ，则除了 (7,8) 之外的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 5 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= darts.length <= 100 
// darts[i].length == 2 
// -10⁴ <= xi, yi <= 10⁴ 
// darts 中的元素互不相同 
// 1 <= r <= 5000 
// 
//
// Related Topics 几何 数组 数学 👍 38 👎 0


#include <bits/stdc++.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)




