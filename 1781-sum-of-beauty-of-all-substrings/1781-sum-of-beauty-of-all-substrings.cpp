class Solution {
public:
    int beautySum(string s) {
        map<char,int> map;
        int sum =0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                map[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(auto it:map){
                    maxi = max(maxi,it.second);
                    mini = min(mini,it.second);
                }
                sum = sum + (maxi-mini);

            }
            map.clear();
        }
        return sum;
    }
};