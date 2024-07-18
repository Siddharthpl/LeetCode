string orderCopy;
class Solution {
public:

    static bool cmp(char a,char b){
        return (orderCopy.find(a)<orderCopy.find(b));
    }

    // int Index(string order, char Curr){
    //     for(int j=0;j<order.length();j++){
    //         if(order[j] == Curr){
    //             return j;
    //         }
    //     }
    //     return -1;
    // }

    string customSortString(string order, string s) {
        // string ans;
        
        // for(int i=0;i<s.length();i++){
        //     char Curr = s[i];
        //     int IndexCurrChar = Index(order,Curr);
        //     if(IndexCurrChar>=0){
        //         ans[IndexCurrChar] =Curr;
        //     }
        // }
        // return ans;
         
         orderCopy = order;

        sort(s.begin(),s.end(), cmp);
        return s;

    }
};