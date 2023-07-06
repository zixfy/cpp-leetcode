//
// Created by wwww on 2023/3/6.
//
#include <bits/stdc++.h>
using namespace std;
template<typename T>
using matrix = vector<vector<T>>;
class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    const int n = nums.size();
    unordered_map<int, vector<int>> idxs;
    matrix<int> dp(n, vector<int> (n, 2));
    int ans = 0;
    if (n < 2)
      return -1;
    for (int i = 0; i < n; ++i) {
      idxs[nums[i]].emplace_back(i);
    }
    for (auto &p : idxs)
      ans = max(ans, (int) p.second.size());
    //dp[0][1] = 2;
    for (int i = 0; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] != nums[j]) {
          int d = nums[j] - nums[i];
          int nxt = nums[j] + d;
          for (const int &k : idxs[nxt])
            if (k > j) {
              dp[j][k] = max(dp[j][k], dp[i][j] + 1);
            }
        }
        ans = max(ans, dp[i][j]);
      }

    return ans;
  }
};

//runtime:520 ms
//memory:103.5 MB
