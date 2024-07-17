class Solution {
public:
    string removeDuplicates(string s) {
        string ans  ;
        int n = s.length();
        for(int i=0;i<n;i++){
            char currentCharacter = s[i];
            if(ans.empty()){
                ans.push_back(currentCharacter);
            }
            else if(currentCharacter == ans.back()){
            ans.pop_back();
            }
            else if(currentCharacter != ans.back()){
            ans.push_back(currentCharacter);
        }
        }
        return ans;
    }
};