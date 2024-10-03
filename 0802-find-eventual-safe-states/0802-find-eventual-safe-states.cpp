class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        vector<vector<int>> rev(graph.size());
        vector<int> ans;
        vector<int> in(graph.size());
        for(int i=0;i<graph.size();i++){
            for (auto it : graph[i]) {
				rev[it].push_back(i);
				in[i]++;
			}
        }
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(int i=0;i<rev[front].size();i++){
                in[rev[front][i]]--;
                if(in[rev[front][i]]==0){
                    q.push(rev[front][i]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};