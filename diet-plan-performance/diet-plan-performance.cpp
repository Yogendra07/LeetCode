class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) 
    {
        int ans = 0;
        int sum = 0;
        vector<int> prefix(calories.size(),0);
        
        for(int i=0;i<calories.size();i++)
        {
            sum += calories[i];
            prefix[i] += sum;
        }
        
        int j = k-1;

        for(int i=0;i<=calories.size()-k;i++)
        {
            if(i == 0)
            {
                if(prefix[j] > upper)
                {
                    ans++;
                } 
                else if(prefix[j] < lower)
                {
                    ans--;
                }
                j++;
            }
            else
            {
                int val = prefix[j] - prefix[i-1];
                // cout<<prefix[j]<<" "<<prefix[i-1]<<endl;
                if(val > upper)
                {
                    ans++;
                }
                else if(val < lower)
                {
                    ans--;
                }
                j++;
            }
        }
                
        return ans;
    }
};