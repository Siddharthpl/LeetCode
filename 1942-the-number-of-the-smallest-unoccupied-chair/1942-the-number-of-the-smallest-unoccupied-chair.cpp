class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> occupied;
        priority_queue<int,vector<int>,greater<int>> free;
        // for(int i=0;i<n;i++){
        //     chairs.push({-1,i});
        // }
        int attf = times[targetFriend][0];
        int chairNo = 0;
        sort(times.begin(),times.end());
        for(int i=0;i<times.size();i++){
            int atime = times[i][0];
            int dtime = times[i][1];

            while(!occupied.empty() && occupied.top().first<=atime ){
                int chairNum = occupied.top().second;
                free.push(chairNum);
                occupied.pop();
            }
            if(free.empty()){
                occupied.push({dtime,chairNo});
                if(attf==atime) return chairNo;

                chairNo++;
            }else{
                int leastChairAvailable = free.top();
                free.pop();
                if(attf==atime) return leastChairAvailable;
                occupied.push({dtime,leastChairAvailable});

            }
        }
        return -1;
        
    }
};