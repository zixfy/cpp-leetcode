#include<vector>
using namespace std;
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    const int N = nums.size();
    const int BASE = 1000;
    int (*dp)[2007] = new int[N + 1][2007]{};
    dp[0][BASE] = 1;
    for (int i = 1; i <= N; i++) {
      int &c = nums.at(i - 1);
      for (int j = 0; j < 2007; j++) {
        if (j - c >= 0) {
          dp[i][j] += dp[i - 1][j - c];
        }
        if (j + c < 2007) {
          dp[i][j] += dp[i - 1][j + c];
        }
      }
            

    }
    return dp[N][target + BASE];
  }
};