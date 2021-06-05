class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> s;
        int ans = 0;
        string start = "0000";
        
        for(auto x : deadends)
        {
            s.insert(x);
        }
        
        if(s.find(start) != s.end())
        {
            return -1;
        }
        
        queue<string> q;
        unordered_map<string,bool> visited;
        q.push(start);
        visited[start] = true;
        string check = "";
        
        while(!q.empty())
        {
                    
            int size_ = q.size();

            while(size_--)
            {
                check = q.front();
                q.pop();

                if(check == target)
                {
                    return ans;
                }
                
                for(int i=0;i<check.length();i++)
                {
                    string temp = check;
                    char ch = check[i];
                    int val = ch - '0';

                    if(val == 0)
                    {
                        val = 9;
                    }
                    else
                    {
                        val--;
                    }

                    ch = val + '0';
                    temp[i] = ch;

                    if(s.find(temp) == s.end() and visited[temp] == false)
                    {
                        q.push(temp);
                        visited[temp] = true;
                    }
                }

                for(int i=0;i<check.length();i++)
                {
                    string temp = check;
                    char ch = check[i];
                    int val = ch - '0';
                    
                    if(val == 9)
                    {
                        val = 0;
                    }
                    else
                    {
                        val++;
                    }
                    
                    ch = val + '0';
                    temp[i] = ch;

                    if(s.find(temp) == s.end() and visited[temp] == false)
                    {
                        q.push(temp);
                        visited[temp] = true;
                    }
                }
                
                
            }
            
            ans++;
            
        }
        
        return -1;
    }
};