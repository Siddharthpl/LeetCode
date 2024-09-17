class Solution {
public:
    long long int MOD = 1000000007;
    int solveReccursion(int n, int k, int target){
        if(target == 0 && n==0){
            
            return 1;
        }
        if(target!=0 && n==0){
            return 0;
        }
        if(target==0 && n!=0){
            return 0;
        }
        int ans = 0;
        for(int j=1;j<=k;j++){
            ans = ans + solveReccursion(n-1,k,target-j);

        }
        return ans;

    }


    int solveMemo(int n, int k, int target,vector<vector<int>>& dp){
        if(target == 0 && n==0){ 
            return 1;
        }
        if(target!=0 && n==0){
            return 0;
        }
        if(target==0 && n!=0){
            return 0;
        }
        if(dp[n][target]!= -1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            int recAns=0;
            if(target-i>=0)
            recAns = (solveMemo(n-1,k,target-i,dp))%MOD;
            ans = (ans%MOD + recAns%MOD)%MOD;
        }
        dp[n][target] = ans;

        return dp[n][target];

    }

    int numRollsToTarget(int n, int k, int target) {
        // int ans = solveReccursion(n,k,target);

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        int ans = solveMemo(n,k,target,dp);

        return ans;
    }
};