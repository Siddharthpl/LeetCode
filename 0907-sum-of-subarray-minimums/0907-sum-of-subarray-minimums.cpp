class Solution {
public:

    void nextSmaller(vector<int>& arr,vector<int>& nextIndex){
        int n=arr.size();
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()!=-1 && arr[s.top()]> arr[i]){
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
            
            while(!s.empty() && s.top()!=-1 && arr[s.top()]>= arr[i]){
                s.pop();
            }
            prevIndex.push_back(s.top());
            s.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nextansIndex;
        vector<int> prevansIndex;
        const int mod = 1e9 + 7;

        prevSmaller(arr,prevansIndex);
        nextSmaller(arr,nextansIndex);
        reverse(nextansIndex.begin(),nextansIndex.end());

        vector<int> ans(n);
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(nextansIndex[i] == -1){
                nextansIndex[i] = n;
            }
            
            prevansIndex[i] = i-prevansIndex[i];
            cout<<prevansIndex[i]<<" ";
    
            nextansIndex[i] = nextansIndex[i] -i;
            cout<<nextansIndex[i]<<" ";
        
            long long no = (nextansIndex[i]%mod * prevansIndex[i]%mod) % mod;
            long long total = (no*arr[i]) % mod;
            sum = (sum + total) % mod;
        }  
    
        return sum;


    }
};