class Solution {
public:

    void nextSmaller(vector<int>& arr,vector<int>& nextIndex){
        int n=arr.size();
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int element = arr[i];
            while(s.top()!=-1 && arr[s.top()]>=element){
                s.pop();
            }
            nextIndex.push_back(s.top());
            s.push(i);
        }
    }

    void prevSmaller(vector<int>& arr,vector<int>& prevIndex){
        int n=arr.size();
        stack<int> s;
        s.push(-1);
        
        for(int i=0;i<n;i++){
            int element = arr[i];
            while(s.top()!=-1 && arr[s.top()]>=element){
                s.pop();
            }
            prevIndex.push_back(s.top());
            s.push(i);
        }
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextIndex;
        vector<int> prevIndex;

        nextSmaller(heights,nextIndex);
        reverse(nextIndex.begin(),nextIndex.end());

        for(int i=0;i<nextIndex.size();i++){
            if(nextIndex[i] == -1) nextIndex[i] = nextIndex.size();
        }

        prevSmaller(heights,prevIndex);

        int maxArea = INT_MIN;
        int currArea = 0;

        for(int i=0;i<nextIndex.size();i++){
            int w = nextIndex[i]-prevIndex[i]-1;
            int h = heights[i];
            currArea = w*h;
            if(currArea>maxArea) maxArea = currArea;
        }

        return maxArea;
    }
};