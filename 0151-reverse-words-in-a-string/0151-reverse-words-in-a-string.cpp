class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n= s.size();
        int start = 0;
        int end = 0;

        for(int i=0;i<n;i++){
            while(s[i]==' ' && i<n){
                i++;
            }
            if(i==n) break;
            while(s[i]!=' ' && i<n){
                s[end++] = s[i++];
            }

            reverse(s.begin()+start,s.begin()+end);
            s[end++] = ' ';
            start = end;
        }
        s.resize(end-1);
        return s;
    }
};