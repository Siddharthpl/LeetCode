class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        vector<int> ans;
       
        for(int i=0;i<k;i++){
            if(i-q.front())

           

            while(!q.empty() && nums[q.back()]< nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }

        int index = q.front();
        int element = nums[index];
        ans.push_back(element);

        for(int i=k;i<n;i++){
            if(i-q.front()>=k) q.pop_front();

            int element = nums[i];

            while(!q.empty() && nums[q.back()]<element){
                q.pop_back();
            }
            q.push_back(i);

            int index = q.front();
            int elementans = nums[index];
            ans.push_back(elementans);
            
        }

        return ans;
        


    }
};