class Solution 
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        stations.push_back({target,0});
        
        if(startFuel >= target)
        {
            return 0;
        }
        
        priority_queue<int> pq;
        
        int curr = startFuel;
        int ans = 0;
        int prev = 0;
        
        for(int i=0;i<stations.size();i++)
        {
            int currLoc = stations[i][0];
            int fuel = stations[i][1];
            
            int need = currLoc - prev;
            prev = currLoc;

            if(curr >= need)
            {
                curr -= need;
                pq.push(fuel);
            }
            else
            {
                
                if(pq.size() == 0)
                {
                    return -1;
                }
                
                while(!pq.empty() and curr < need)
                {
                    curr += pq.top();
                    pq.pop();
                    ans++;
                }
                
                if(pq.size() == 0 and curr < need)
                {
                    return -1;
                }
                
                curr -= need;                
                pq.push(fuel);
                
            }
        }
        
        return ans;
    }
};
