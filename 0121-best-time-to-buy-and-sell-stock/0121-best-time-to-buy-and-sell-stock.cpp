class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        while(i<prices.size()-1 && j<prices.size()){
            if(prices[j] < prices[i]){
                i=j;
            }
            maxi = max(maxi,prices[j] - prices[i]);
            j++;
        }

        return maxi;
    }
};