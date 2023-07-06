//某实验室计算机待处理任务以 `[start,end,period]` 格式记于二维数组 `tasks`，表示完成该任务的时间范围为起始时间 `start` 
//至结束时间 `end` 之间，需要计算机投入 `period` 的时长，注意：
//1. `period` 可为不连续时间
//2. 首尾时间均包含在内
//
//处于开机状态的计算机可同时处理任意多个任务，请返回电脑最少开机多久，可处理完所有任务。
//
//**示例 1：**
//
//> 输入：`tasks = [[1,3,2],[2,5,3],[5,6,2]]`
//>
//> 输出：`4`
//>
//> 解释：
//> tasks[0] 选择时间点 2、3；
//> tasks[1] 选择时间点 2、3、5；
//> tasks[2] 选择时间点 5、6；
//> 因此计算机仅需在时间点 2、3、5、6 四个时刻保持开机即可完成任务。
//
//**示例 2：**
//
//> 输入：`tasks = [[2,3,1],[5,5,1],[5,6,2]]`
//>
//> 输出：`3`
//>
//> 解释：
//> tasks[0] 选择时间点 2 或 3；
//> tasks[1] 选择时间点 5；
//> tasks[2] 选择时间点 5、6；
//> 因此计算机仅需在时间点 2、5、6 或 3、5、6 三个时刻保持开机即可完成任务。
//
//**提示：**
//- `2 <= tasks.length <= 10^5`
//- `tasks[i].length == 3`
//- `0 <= tasks[i][0] <= tasks[i][1] <= 10^9`
//- `1 <= tasks[i][2] <= tasks[i][1]-tasks[i][0] + 1`
//
// Related Topics 贪心 数组 堆（优先队列） 👍 42 👎 0


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

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int processTasks(vector<vector<int>>& tasks) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)




