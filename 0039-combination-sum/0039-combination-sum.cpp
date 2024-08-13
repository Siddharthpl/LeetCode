class Solution {
public:

    void solve(vector<int>& candidates, int target,int index,vector<int>& output,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(output);
            return;
        }else if(target<0){
            return;
        }

        for(int i=index;i<candidates.size();i++){
            output.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,output,ans);
            output.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
       

        solve(candidates,target,0,output,ans);

        return ans;
        
    }
};