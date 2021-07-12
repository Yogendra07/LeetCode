class Solution 
{
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> foccur(26,0);
        vector<int> loccur(26,0);
        
        for(char ch='a';ch<='z';ch++)
        {
            for(int i = 0;i<s.length();i++)
            {
                if(s[i] == ch)
                {
                    foccur[ch-'a'] = i;
                    break;
                }
            }
        }
        
        for(char ch='a';ch<='z';ch++)
        {
            for(int i = 0;i<s.length();i++)
            {
                if(s[i] == ch)
                {
                    loccur[ch-'a'] = i;
                }
            }
        }
        
        int ans = 0;
        
        for(char ch='a';ch<='z';ch++)
        {
            int first = foccur[ch-'a'];
            int last = loccur[ch-'a'];
            
            if(first != last)
            {
                unordered_set<char> u;
                
                for(int i=first+1;i<last;i++)
                {
                    if(u.find(s[i]) == u.end())
                    {
                        u.insert(s[i]);
                    }
                }
                
                ans += u.size();
                u.clear();
            }
        }
        
        return ans;
    }
};