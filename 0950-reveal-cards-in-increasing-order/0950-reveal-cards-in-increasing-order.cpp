class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        queue<int> q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        for(int i=0;i<ans.size();i++){
            ans[q.front()] = deck[i];
            q.pop();
            if(!q.empty()){
            q.push(q.front());
            q.pop();
            }
           
        }
        

        return ans;
    }
};