class Solution {
public:

int checkPallindrome(string s , int i,int j){
    int count =0;
    while(i>=0 && j<s.length() && s[i]==s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}

    int countSubstrings(string s) {
        int i,j;
        int totalP = 0;
        int ans=0;
        for(int center = 0;center<s.length();center++){
            i=center;
            j=center;
            int oddP = checkPallindrome(s,i,j);
            i=center;
            j=center+1;;
            int evenP = checkPallindrome(s,i,j);
            int totalP =oddP+evenP ;
            ans = ans+totalP;
        }
        return ans;
        
    }
};