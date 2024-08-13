class Solution {
public:
    void solve(vector<int>& candidates, int target, 
               vector<int>& output, vector<vector<int>>& ans, int index) {
        if (target == 0) {
            ans.push_back(output);
            return;
        } else if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
                output.push_back(candidates[i]);
                solve(candidates, target-candidates[i], output, ans, i+1);
                output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, target, output, ans, 0);

        return ans;
    }
};