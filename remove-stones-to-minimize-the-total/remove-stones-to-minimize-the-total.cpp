class Solution 
{
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int sum = 0;
        
        for(auto x : piles)
        {
            sum += x;
        }
        
        priority_queue<int> pq;
        
        for(auto x : piles)
        {
            pq.push(x);    
        }
        
        while(!pq.empty() and k--)
        {
            int curr = pq.top();
            pq.pop();
            
            sum -= floor(curr/2);
            curr -= floor(curr/2);
            
            pq.push(curr);
        }
        
        return sum;
    }
};