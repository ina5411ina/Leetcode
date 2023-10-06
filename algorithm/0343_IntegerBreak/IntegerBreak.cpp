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