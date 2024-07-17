class Solution {
public:
    string removeOccurrences(string full, string pattern) {
        // int n1 = s.length();
        // int n2 = part.length(); 
        // string ans;

        // for(int i=0;i<n1;i++){
        //     char currchar = s[i];
        //     if(i<n2){
        //         ans.push_back(currchar);
        //     }
        //     else{
        //         if(ans.compare(ans.size()-n2,n2,part,part.begin(),n2 == 0)){
        //             for(int j=0;j<n2;j++){
        //                 ans.pop_back();
        //             }
        //         }
        //         else{
        //             ans.push_baack(currchar);
        //         }

        //     }
        // }
        // return ans;

        int findKaIndex = full.find(pattern);
        while(findKaIndex != -1){
            full.erase(findKaIndex,pattern.length());
            findKaIndex = full.find(pattern);
        }
        return full;

    }
};