class Solution {
public:
    int usingReccursion(string& word1, string& word2, int i, int j) {
        if (i >= word1.length())
            return word2.length() - j;
        if (j >= word2.length())
            return word1.length() - i;

        int ans;
        if (word1[i] == word2[j]) {
            ans = 0 + usingReccursion(word1, word2, i + 1, j + 1);
        } else {
            int replace = 1 + usingReccursion(word1, word2, i + 1, j + 1);
            int insert = 1 + usingReccursion(word1, word2, i, j + 1);
            int remove = 1 + usingReccursion(word1, word2, i + 1, j);
            ans = min(replace, min(remove, insert));
        }
        return ans;
    }

    int usingMemo(string& word1, string& word2, int i, int j,
                  vector<vector<int>>& dp) {
        if (i >= word1.length())
            return word2.length() - j;
        if (j >= word2.length())
            return word1.length() - i;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans;
        if (word1[i] == word2[j]) {
            ans = 0 + usingMemo(word1, word2, i + 1, j + 1, dp);
        } else {
            int replace = 1 + usingMemo(word1, word2, i + 1, j + 1, dp);
            int insert = 1 + usingMemo(word1, word2, i, j + 1, dp);
            int remove = 1 + usingMemo(word1, word2, i + 1, j, dp);
            ans = min(replace, min(remove, insert));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int usingTabulationSO(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<int> next(word1.length() + 1, 0);
        vector<int> curr(word1.length() + 1, 0);

        for(int i = 0;i<=n1;i++){
            next[i] = word1.length() - i;
        }
        // for(int j = 0;j<=n2;j++){
        //     dp[n1][j] = word2.length() - j;
        // } 

        for (int j = n2 - 1; j >= 0; j--) {
            curr[n1] = word2.length() - j;
            for (int i = n1-1; i >= 0; i--) {
                
                int ans=0;
                if (word1[i] == word2[j]) {
                    ans = 0 + next[i + 1];
                } else {
                    int replace = 1 + next[i + 1];
                    int insert = 1  + next[i];
                    int remove = 1 + curr[i+1];
                    ans = min(replace, min(remove, insert));
                    
                }
                curr[i] = ans;
                
            }
            next = curr;
        }
        return next[0];
    }


    int usingTabulation(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0)); 

        for(int i = 0;i<=n1;i++){
            dp[i][n2] = word1.length() - i;
        }
        for(int j = 0;j<=n2;j++){
            dp[n1][j] = word2.length() - j;
        }       

        for (int j = n2 - 1; j >= 0; j--) {
            for (int i = n1 - 1; i >= 0; i--) {
                int ans;
                if (word1[i] == word2[j]) {
                    ans = 0 + dp[i + 1][j + 1];
                } else {
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][ j];
                    ans = min(replace, min(remove, insert));
                }
                dp[i][j] = ans;
       
            }
            
        }
        return dp[0][0];
    }

    

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // int ans = usingReccursion(word1,word2,i,j);

        // vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1)); 
        // int ans = usingMemo(word1,word2,i,j,dp);

        int ans = usingTabulationSO(word1, word2);
        return ans;
    }
};