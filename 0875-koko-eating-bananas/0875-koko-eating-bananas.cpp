class Solution {
public:

    bool build(vector<int>& piles, int h, int k){
        long long int totalHoursTakenByKoko = 0;
        for(int i=0;i<piles.size();i++){
             totalHoursTakenByKoko = totalHoursTakenByKoko + ceil(piles[i]/double(k));
        }
        return totalHoursTakenByKoko <=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       /* int s=1;
        int e = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        
        int m= s + (e-s)/2;
        int ans;
         long long int count=0;
        
        while(s<=e){
           
            for(int i=0;i<n-1;i++){
            if(nums[i]<=m){
                count++;
            }else{
                 int value = nums[i]/m;
                 value = value+1;
                 count = count +value;
            }
            }
            if(count==h){
                ans=m;
            }
            else if(count<h){
                
                e=m-1;
            }
            else{
                s = m+1;
            }
            m= s + (e-s)/2;

        }
        return ans;*/

        int s=1;
        int e = *max_element(piles.begin(),piles.end());
        int ans=0;
        while(s<=e){
        int m = s +(e-s)/2;
        int k=m;
        if(build(piles,h,k)){
            ans =k;
            e=m-1;
        }
        else{
            s=m+1;
        }
        }
        return ans;

    }
};