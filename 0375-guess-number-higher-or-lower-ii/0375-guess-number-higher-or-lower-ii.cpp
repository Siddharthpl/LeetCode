class Solution {
public:

    int usingReccursion(int start,int end){
        if(start>=end){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans,i+max(usingReccursion(start,i-1),usingReccursion(i+1,end)));
        }
        return ans;
    }


    int usingMemo(int start,int end,vector<vector<int>>& dp){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=-1) return dp[start][end];
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans,i+max(usingMemo(start,i-1,dp),usingMemo(i+1,end,dp)));
            dp[start][end] = ans;
        }
        return dp[start][end];
    }

    int usingTabulation(int n){
        

        vector<vector<int>> dp(n+2,vector<int>(n+1,0));


        for(int start = n-1;start>=1;start--){
            for(int end = start+1;end<=n;end++){
                int ans = INT_MAX;
                for(int i=start;i<=end;i++){
                    ans = min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                    dp[start][end] = ans;
                }
            }
        }


        
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // int start = 1;
        // int end = n;
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // int ans = usingMemo(start,end,dp);


        int ans = usingTabulation(n);

        return ans;
    }
};