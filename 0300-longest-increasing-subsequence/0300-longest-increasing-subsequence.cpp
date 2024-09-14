class Solution {
public:

    int usingMemo(vector<int>& nums,int prev,int curr,vector<vector<int>>& dp){
        if(curr>=nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int include = 0;
        if(prev == -1|| nums[curr]>nums[prev] ){
            include = 1 + usingMemo(nums,curr,curr+1,dp);
        }
        int exclude = 0 + usingMemo(nums,prev,curr+1,dp);
        dp[curr][prev+1] = max(include,exclude);
        
        return dp[curr][prev+1];
    }

    int usingTabulation(vector<int>& nums,int prev,int curr){
        if(curr>=nums.size()) return 0;
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1|| nums[curr]>nums[prev] ){
                include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include,exclude);
            }
        }
        
        
        return dp[0][0];
    }


    int usingTabulationSO(vector<int>& nums,int prev,int curr){
        
        int n= nums.size();
       
        vector<int> curRow(n+1,0);
        vector<int> nextRow(n+1,0);

        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1|| nums[curr]>nums[prev] ){
                include = 1 + nextRow[curr+1];
                }
                int exclude = 0 + nextRow[prev+1];
                curRow[prev+1] = max(include,exclude);
            }
            nextRow = curRow;
        }
        
        
        return nextRow[0];
    }


    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        // int ans = usingReccursion(nums,prev,curr);

        int n=nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // int ans = usingMemo(nums,prev,curr,dp);


        int ans = usingTabulationSO(nums,prev,curr);

        return ans;
    }
};