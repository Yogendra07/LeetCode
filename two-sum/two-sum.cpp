class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        int flag = 0;
        for(int i=0;i<numbers.size();i++)
        {
            for(int j=1;j<numbers.size();j++)
            {
                if(numbers[i] + numbers[j] == target and i!=j)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 1)
            {
                break;
            }
        }
        
        return ans;
    }
};