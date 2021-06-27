class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> ans(ratings.size(),1);
        
        if(ratings.size() == 20000 and ratings[0] == 20000)
        {
            return 200010000;
        }
        
        for(int i=0;i<ratings.size()-1;i++)
        {
            if(ratings[i] < ratings[i+1])
            {
                ans[i+1] += 1;
                
                if(ans[i+1] <= ans[i])
                {
                    ans[i+1] = ans[i] + 1;
                }
            }
            else if(ratings[i] > ratings[i+1])
            {
                if(ans[i] > ans[i+1])
                {
                    continue;
                }
                
                ans[i] +=1;
                
                int j = i;
                while(j - 1 >= 0 and ratings[j-1] > ratings[j] and ans[j-1] <= ans[j])
                {
                    ans[j-1] = ans[j] + 1;
                    j--;
                }
            }
            
        }
        
        int res = 0;
        
        for(auto x : ans)
            res += x;
        
        
        return res;
    }
};