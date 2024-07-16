class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        /*sort(nums.begin(),nums.end());
        int count = 0;

        for(int i=0;i<nums.size();i++){
            int s=i;
            int e = nums.size()-1;
            int m;
            

            while(s<=e){
                m= s + (e-s)/2;
                if(i>0 && nums[i]==nums[i-1]) continue;

                if(nums[m] == nums[i]+k &&  m!=i){
                    count++;
                    break;
                }
                else if(nums[m] >= nums[i] +k){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
                m= s + (e-s)/2;

            }
        }
        return count;*/

        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;
        
        int n = nums.size();
        int i=0,j=1;

        while(i<n && j<n){
            if(abs(nums[j]-nums[i])==k  ){
                ans.insert({nums[i],nums[j]});
                
                i++;
                j++;
            }
            else if(abs(nums[j]-nums[i])<k){
                j++;
            }
            else{
                i++;
            }
            if(i==j) j++;

        }
        return ans.size();



    }
};