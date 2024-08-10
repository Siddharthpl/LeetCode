class Solution {
public:

    void solve(int n, int k,vector<int>& output,vector<vector<int>>& ans,int i){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }

        for(int x=i;x<=n;x++){
            output.push_back(x);
            
            solve(n,k,output,ans,x+1);
            
            output.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(n,k,output,ans,1 );
        return ans;
    }
};