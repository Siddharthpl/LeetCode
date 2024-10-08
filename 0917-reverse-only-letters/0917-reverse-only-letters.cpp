class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
                continue;
            }
            else if(!isalpha(s[j])){
                j--;
            }
            else {
                i++;
            }
        }

        return s;

        
    }
};