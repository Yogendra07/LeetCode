class Solution {
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) 
    {
        unordered_map<string,int>m;
        
        for(int i=0;i<w.size();i++)
        {
            m[w[i]]++;
        }
        if(m.find(b)!=m.end())
        {
            m.erase(b);
        }
        vector<vector<string>> ans;
       // return ans;
        if(m.find(e)==m.end())
        {
            return ans;
        }
        queue<vector<string>> q;
        q.push({b});
        vector<string>visited;

        int f=0;
    
        while(!q.empty())
        {
            int n=q.size();
          //  int f=0;
            while(n--)
            {
                vector<string>v=q.front();
                q.pop();
                string s=v.back();
                if(s==e)
                {
                    ans.push_back(v);
                    f=1;                   
                }
                for(int i=0;i<s.size();i++)
                {
                    string k=s;
                    for(char ch='a';ch<='z';ch++)
                    {
                        k[i]=ch;
                        if(m.find(k)!=m.end() &&  k!=s)
                        {
                            
                            visited.push_back(k);
                           
                            v.push_back(k);
                            q.push(v);                       
                            v.pop_back();                        
                        }                    
                    }
                }           
            }
            if(f==1)
            {
                return ans;
            }
            for(int i=0;i<visited.size();i++)
            {
                m.erase(visited[i]);
            }
            visited.clear();

            
           
        }
        return ans;
        
        
    }
};
