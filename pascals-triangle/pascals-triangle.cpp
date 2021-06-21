class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> v;
        vector<int> help;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int> helper;
            
            for(int j=0;j<=i;j++)
            {
                if(i == 0)
                {
                    helper.push_back(1); 
                    help.push_back(1);
                }
                else
                {
                    if(j == 0 || j == i)
                    {
                        helper.push_back(1);
                        help.push_back(1);
                    }
                    else
                    {
                        int ans = help[j-1] + help[j];
                        helper.push_back(ans);
                    }
                }
            }
            
            v.push_back(helper);
            help.clear();
            help = helper;
        }
        
        return v;
    }
};