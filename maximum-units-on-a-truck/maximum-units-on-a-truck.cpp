class Solution 
{
public:
    static bool comp(vector<int> v1,vector<int> v2)
    {
        return v1[1] > v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int ans = 0;
        sort(boxTypes.begin(),boxTypes.end(),comp);  
        
        for(int i=0;i<boxTypes.size();i++)
        {
            vector<int> helper = boxTypes[i];
            int val1 = helper[0];
            int val2 = helper[1];
            
            if(val1 <= truckSize)
            {
                ans += val1 * val2;
                truckSize -= val1;
            }
            else
            {
                ans += truckSize * val2;
                break;
            }
        }
        
        return ans;
    }
};