class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node] = 1;
        for(int j=0;j<adj[node].size();j++){
            if(!vis[adj[node][j]]){
                dfs(adj[node][j],vis,adj);
            }
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<int> adj[isConnected.size()];
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        
        vector<int> vis(n,0);
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);

            }
        }

        return count;
    }
};