class Solution {
public:

    bool checkPallindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        bool ans1,ans2;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                ans1 = checkPallindrome(s,i+1,j);
                ans2 = checkPallindrome(s,i,j-1);
                bool finalAns = ans1 || ans2;
                return finalAns;
            }
        }
        return true;
    }
};