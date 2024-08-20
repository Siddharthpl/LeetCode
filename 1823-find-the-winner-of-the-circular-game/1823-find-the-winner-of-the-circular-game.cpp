class Solution {
public:

    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        int count =k;
        while(q.size()>1){
            if(count==1){
                q.pop();
                count =k+1;
            }else{
                q.push(q.front());
                q.pop();
            }
            count--;
        }
        
        return q.front();
    }
};