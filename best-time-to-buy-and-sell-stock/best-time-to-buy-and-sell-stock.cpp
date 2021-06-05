class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_value = INT_MAX;
        int max_value = 0;
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i] < min_value)
            {
                min_value = prices[i];
            }
            else if(prices[i] - min_value > max_value)
            {
                max_value = prices[i] - min_value;
            }
        }
        
        return max_value;
    }
    
    
};