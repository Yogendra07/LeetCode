class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        int ans = 1;
        unordered_map<string,int> m;
        
        for(auto x : wordList)
        {
            m[x]++;
        }
        
        if(m.find(endWord) == m.end())
        {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty())
        {
            int n = q.size();
            
            while(n--)
            {
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                {
                    return ans;
                }
                
                for(int i=0;i<word.length();i++)
                {
                    char ch = word[i];
                    
                    for(int j=0;j<26;j++)
                    {
                        string temp = word;
                        ch = 'a' + j;
                        temp[i] = ch;
                        
                        if(m.find(temp) != m.end() and temp != beginWord)
                        {
                            q.push(temp);
                            m.erase(temp);
                        }
                    }
                    
                }
            }
            
            ans++;
        }
        
        return 0;
    }

};