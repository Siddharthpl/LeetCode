class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num1 = start;
        vector<int> num1b;
        while(num1!=0){
            num1b.push_back(num1%2);
            num1 = num1/2;
        }
        int n1 = num1b.size();
        int num2 = goal;
        vector<int> num2b;
        while(num2!=0){
            num2b.push_back(num2%2);
            num2 = num2/2;
        }
        int n2 = num2b.size();

        int n = max(n1,n2);
        int k=0;
        for(int i=0;i<n;i++){
            if(i>=n1){
                num1b.push_back(0);
            }else if(i>=n2){
                num2b.push_back(0);
            }
            if(num1b[i]!=num2b[i]){
                k++;
            }
        }
        return k;

        


        return 0;

    }
};