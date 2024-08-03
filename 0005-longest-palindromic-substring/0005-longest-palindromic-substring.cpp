class Solution {
public:
    bool isPallindrome(string& s,int i,int j){
         while(i<j){
            if(s[i]!=s[j]){
                return false;
                }
                i++;
                j--;
                
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string p;
        int maxLength = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(isPallindrome(s,i,j)){
                    int length = (j-i)+1;
                    if(length>maxLength){
                        maxLength = length;
                        p = s.substr(i,maxLength);
                    }

               }

                    

            }
        }
        return p;
    }
};