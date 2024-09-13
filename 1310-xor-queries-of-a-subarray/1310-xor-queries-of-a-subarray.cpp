class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cumXOR(n,0);
        cumXOR[0]=arr[0];
        for(int i=1;i<n;i++){
            cumXOR[i] = arr[i]^cumXOR[i-1];
        }

        vector<int> ans(queries.size(),0);

        
        for(int i = 0;i<queries.size();i++){
            if(queries[i][0]==0){
                ans[i] = cumXOR[queries[i][1]];
            }else{
            ans[i] = cumXOR[queries[i][0]-1]^cumXOR[queries[i][1]];
            }
        }

        return ans;

    }
};