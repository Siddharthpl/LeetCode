class Solution {
public:
    void solve(vector<int>& prices,int i,int& minPrice,int& profit){
        if(i==prices.size()){
            return;
        }

        
        if(prices[i]<minPrice) minPrice = prices[i];
        int todayp = prices[i]-minPrice;
        if(todayp>profit) profit = todayp;
        
        solve(prices,i+1,minPrice,profit);

    }

    int maxProfit(vector<int>& prices) {
        int i=0;
        
        int profit = 0; 
        int minPrice = INT_MAX;
        
        solve(prices,i,minPrice,profit);

        return profit;
    }
};