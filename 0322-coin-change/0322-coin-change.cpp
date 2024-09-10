class Solution {
public:
    // include exclude pattern .......................................
    int solve(vector<int>& coins, int amount){
        if(amount == 0){
            return 0;
        }
        int minCoinsAns = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount>=coins[i]){
                int recursionAns = solve(coins,amount-coins[i]);
            
            if(recursionAns!=INT_MAX){

                int coinsUsed = 1+ recursionAns;
                minCoinsAns = min(minCoinsAns,coinsUsed);
            }}
        }
        return minCoinsAns;
    }

    int usingMemoization(vector<int>& coins, int amount,vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(dp[amount]!= -1){
            return dp[amount];
        }
        int minCoinsAns = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount>=coins[i]){
                int recursionAns = usingMemoization(coins,amount-coins[i],dp);
            
            if(recursionAns!=INT_MAX){

                int coinsUsed = 1+ recursionAns;
                minCoinsAns = min(minCoinsAns,coinsUsed);
            }}
        }
        dp[amount] = minCoinsAns;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins,amount);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;
        

        // memoization
        int n = amount;
        vector<int> dp(n+1,-1);
        int ans = usingMemoization(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;

    }
};