 class Solution {
public:
    int longestOnes(vector<int>& v, int k) 
    {
        int c=0;
        int ans=0;
        set<int>s;
        int y=k;
        for(int i=0;i<v.size();i++)
        {

            if(v[i]==1)
            {
                c++;
            }
            else 
            {
                ans=max(ans,c);
                k--;
                if(k>=0)
                {
                    c++;
                    s.insert(i);
                }
                else
                {
                    if(s.empty())
                    {
                        c=0;
                    }
                    else
                    {
                        k++;
                        s.insert(i);
                        int x=*(s.begin());
                        c=i-x;
                        s.erase(x);                             
                    }
                    
                } 
            }
            ans=max(ans,c);

        }
        return ans;
        
    }
};