class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int ans = 0;
        
        if(height.size() <= 2)
        {
            return 0;
        }
        
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        
        int maxi = INT_MIN;
        
        for(int i=0;i<height.size();i++)
        {
            if(height[i] > maxi)
            {
                maxi = height[i];
            }
            
            left[i] = maxi;
        }
        
        maxi = INT_MIN;
        
        for(int i=height.size()-1;i>=0;i--)
        {
            if(height[i] > maxi)
            {
                maxi = height[i];
            }
            
            right[i] = maxi;
        }
        
        for(int i=1;i<height.size()-1;i++)
        {
            ans += min(left[i],right[i]) - height[i];
        }
        
        return ans;
    }
    
    
};