// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) {
            return 0;
        };

        int buyIndex = 0; 
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++) {
            if(prices[buyIndex] > prices[i]) {
                buyIndex = i;
            }

            if(prices[i] - prices[buyIndex] > maxProfit) {
                maxProfit = prices[i] - prices[buyIndex];
            }
        }

        return maxProfit;
    }
};