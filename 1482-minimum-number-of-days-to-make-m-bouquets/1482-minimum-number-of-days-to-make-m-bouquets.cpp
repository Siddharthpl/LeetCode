class Solution {
public:

    bool makeBouquet(vector<int>& bloomDay,int mid, int m, int k){
        int counter = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                counter++;
            }
            if(counter==k){
                m--;
                counter = 0;
                if(m==0){
                    break;
                }
            }
            if(bloomDay[i]>mid){
                counter = 0;
            }
        }
        return m==0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long int requirement = (long long int)m * (long long int)k;
        if (bloomDay.size() < requirement)
            return -1;

        int s = *min_element(bloomDay.begin(),bloomDay.end());
        int e = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = 0;
    while(s<=e){
        int mid = s+(e-s)/2;
        

        if(makeBouquet(bloomDay,mid,m,k)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;

        
    }
};