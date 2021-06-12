class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue <int, vector<int>, greater<int>> pq;
        
        int ans = 0;
        int k = 0;
        
        if(ladders == 0 and bricks != 0)
        {
            for(int i=0;i<heights.size()-1;i++)
            {
                if(heights[i] - heights[i+1] > 0)
                {
                    ans++;
                }
                else
                {
                    int diff = heights[i+1] - heights[i];
                    
                    if(bricks >= diff)
                    {
                        ans++;
                        bricks -= diff;
                    }
                    else
                    {
                        return ans;
                    }
                }
            }
        }
        else if(bricks == 0 and ladders != 0)
        {
            for(int i=0;i<heights.size()-1;i++)
            {
                if(heights[i] - heights[i+1] > 0)
                {
                    ans++;
                }
                else
                {
                    if(ladders > 0)
                    {
                        ans++;
                    }
                    else
                    {
                        return ans;
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<heights.size()-1;i++)
            {
                if(heights[i] - heights[i+1] >= 0)
                {
                    ans++;
                }
                else if(heights[i] - heights[i+1] < 0 and k < ladders)
                {
                    ans++;
                    k++;
                    pq.push(abs(heights[i] - heights[i+1]));
                }
                else if(heights[i] - heights[i+1] < 0 and k == ladders and bricks != 0)
                {
                    int diff = heights[i+1] - heights[i];

                    int p = pq.top();

                    if(diff <= p)
                    {
                        if(bricks < diff)
                        {
                            return ans;
                        }
                        else
                        {
                            bricks -= diff;
                            ans++;
                        }
                    }
                    else
                    {
                        int val = pq.top();
                        pq.pop();
                        
                        if(bricks < val)
                        {
                            return ans;
                        }
                        else
                        {
                            bricks -= val;
                            ans++;
                        }

                        pq.push(diff);

                    }
                }
                else
                {
                    return ans;
                }
            }
        }
                
        return ans;
        
    }
};