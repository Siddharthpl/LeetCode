class Solution {
public:
    int getLucky(string s, int k) {
        unordered_map<char,int> map;
        char ch = 'a';
        int num = 0;
        int sum = 0;
        for(int i=1;i<=26;i++){
            map[ch] = i;
            ch++;
        }
        for(int i=0;i<s.length();i++){
            num = map[s[i]];
            if(num/10 !=0){
                int digit = num/10;
                int r = num%10;
                num = digit+r;
            }
            sum = sum + num;
        }
        if(k==1) return sum;
        
        int sum2;
        while(k!=1){
            sum2 = 0;
            while(sum!=0){
                int r = sum%10;
                sum2 = sum2 + r;
                sum = sum/10;
            }
            k--;
            sum = sum2;
        }  
        
        return sum2;
    }
};