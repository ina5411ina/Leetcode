# [343. Integer Break (Medium)](https://leetcode.com/problems/integer-break/description/)

#### Difficulty: Medium

#### Data: Oct. 6th, 2023


## Solution 1. (Better)
```cpp
// type: DP (Bottom-up)
// time complexity: O(N^2)
// space complexity: O(N)

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1); // 初始化，dp 紀錄已計算過的數字
        
        for(int num=2; num<=n; num++){
            if(num == n) dp[num] = 0; // 確保 n 一定會被分解
            else dp[num] = num; 
            
            // Bottom-up
            for(int i=1; i<num; i++){
                int val = dp[i]*dp[num-i]; 
                dp[num] = max(val, dp[num]);
            }
        }
        
        return dp[n];
    }
};

```


## Solution 2. **Time Limit Exceeded**
```cpp
// type: DFS 
// time complexity: O(N^2)
// space complexity: O(N)

class Solution {
public:
    int dfs(int n, int num, vector<int> &dp){
        if(n <= 3) return n-1;

        if(num == n) dp[num]= 0;
        else dp[num] = num;

        for(int i=1 ; i<num; i++){
            int val = dfs(n, i, dp) * dfs(n, num-i, dp);
            dp[num] = max(val, dp[num]);
        }
        return dp[num];
    }

    int integerBreak(int n) {
        if(n <= 3) return n-1;
        else{
            vector<int> dp(n+1, 1);
            return dfs(n, n, dp);
        }
    }
};
```



