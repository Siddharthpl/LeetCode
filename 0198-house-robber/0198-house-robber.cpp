class Solution {
public:
    // int solve(vector<int>& nums, int n, int i){
    //     if(i>=n){
    //         return 0;
    //     }
    //     int includeAns = nums[i] + solve(nums,n,i+2);
    //     int excludeAns = 0 + solve(nums,n,i+1);
    //     int finalans = max(includeAns,excludeAns);
    //     return finalans;

    // }

    int usingMemo(vector<int>& nums, int n, int i,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int includeAns = nums[i] + usingMemo(nums,n,i+2,dp);
        int excludeAns = 0 + usingMemo(nums,n,i+1,dp);
        dp[i] = max(includeAns,excludeAns);
        return dp[i];

    }

    int usingTabulation(vector<int>& nums){
        vector<int> dp(nums.size(),-1);
        int n=nums.size();
        dp[n-1] = nums[n-1];

        for(int i = n-2;i>=0;--i){
            int tempAns = 0;
            if(i+2<n){
                tempAns = dp[i+2];
            }
            int includeAns = nums[i] + tempAns;
            int excludeAns = 0 + dp[i+1];
            dp[i] = max(includeAns,excludeAns);
        }

        return dp[0];

    }

    int rob(vector<int>& nums) {
        // Reccursive approach
        // int index = 0;
        // int ans = solve(nums,nums.size(),index);
        // return ans;
        
        // top down or memoization
        // int i = 0;
        // vector<int> dp(nums.size()+1,-1);
        // int ans = usingMemo(nums,nums.size(),i,dp);
        // return ans;


        // Bottom up or tabulation
        int ans = usingTabulation(nums);
        return ans;
    }
};