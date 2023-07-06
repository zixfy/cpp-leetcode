//小明的电动车电量充满时可行驶距离为 `cnt`，每行驶 1 单位距离消耗 1 单位电量，且花费 1 单位时间。小明想选择电动车作为代步工具。地图上共有 N 
//个景点，景点编号为 0 ~ N-1。他将地图信息以 `[城市 A 编号,城市 B 编号,两城市间距离]` 格式整理在在二维数组 `paths`，表示城市 A、
//B 间存在双向通路。初始状态，电动车电量为 0。每个城市都设有充电桩，`charge[i]` 表示第 i 个城市每充 1 单位电量需要花费的单位时间。请返回小明最
//少需要花费多少单位时间从起点城市 `start` 抵达终点城市 `end`。
//
//**示例 1：**
//
//> 输入：`paths = [[1,3,3],[3,2,1],[2,1,3],[0,1,4],[3,0,5]], cnt = 6, start = 1, 
//end = 0, charge = [2,10,4,1]`
//>
//> 输出：`43`
//>
//> 解释：最佳路线为：1->3->0。
//> 在城市 1 仅充 3 单位电至城市 3，然后在城市 3 充 5 单位电，行驶至城市 5。
//> 充电用时共 3\*10 + 5\*1= 35
//> 行驶用时 3 + 5 = 8，此时总用时最短 43。
//> ![image.png](https://pic.leetcode-cn.com/1616125304-mzVxIV-image.png)
//
//**示例 2：**
//
//> 输入：`paths = [[0,4,2],[4,3,5],[3,0,5],[0,1,5],[3,2,4],[1,2,8]], cnt = 8, 
//start = 0, end = 2, charge = [4,1,1,3,2]`
//>
//> 输出：`38`
//>
//> 解释：最佳路线为：0->4->3->2。
//> 城市 0 充电 2 单位，行驶至城市 4 充电 8 单位，行驶至城市 3 充电 1 单位，最终行驶至城市 2。
//> 充电用时 4\*2+2\*8+3\*1 = 27
//> 行驶用时 2+5+4 = 11，总用时最短 38。
//
//**提示：**
//- `1 <= paths.length <= 200`
//- `paths[i].length == 3`
//- `2 <= charge.length == n <= 100`
//- `0 <= path[i][0],path[i][1],start,end < n`
//- `1 <= cnt <= 100`
//- `1 <= path[i][2] <= cnt`
//- `1 <= charge[i] <= 100`
//- 题目保证所有城市相互可以到达
//
// Related Topics 图 最短路 堆（优先队列） 👍 36 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
