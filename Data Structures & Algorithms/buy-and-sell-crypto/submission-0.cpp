class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int best = 0;

        for (int right = 1; right < prices.size(); right++)
        {
            if(prices[right] < prices[left])
            {
                left = right;
            } 
            else
            {
                best = std::max(best, prices[right] - prices[left]);
            }
        }

        return best;
    }
};
