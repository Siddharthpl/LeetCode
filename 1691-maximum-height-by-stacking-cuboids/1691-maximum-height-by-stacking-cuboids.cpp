class Solution {
public:

    bool check(vector<int>& curr,vector<int>& prev){
        if(curr[0]>=prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2] ){
            return true;
        }else{
            return false;
        }
    }

    int usingTabulationSO(vector<vector<int>>& cuboids){
        
        int n= cuboids.size();
       
        vector<int> curRow(n+1,0);
        vector<int> nextRow(n+1,0);

        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1|| check(cuboids[curr],cuboids[prev]) ){
                    int heighttoadd = cuboids[curr][2];
                    include = cuboids[curr][2] + nextRow[curr+1];
                }
                int exclude = 0 + nextRow[prev+1];
                curRow[prev+1] = max(include,exclude);
            }
            nextRow = curRow;
        }
        
        
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());

        int ans = usingTabulationSO(cuboids);

        return ans;
    }
};