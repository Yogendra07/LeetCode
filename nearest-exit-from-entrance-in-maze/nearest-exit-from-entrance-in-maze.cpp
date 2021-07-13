class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int m = maze.size();
        int n = maze[0].size();
        
        int steps = 0;
        queue<pair<int,int>> q;
        vector<vector<bool> > visited(m,vector<bool> (n, false));
        
        int or1 = entrance[0];
        int or2 = entrance[1];
        
        q.push({entrance[0],entrance[1]});
        

        while(!q.empty())
        {
            int c1 = 0 , c2 = 0;
    
            int t = q.size();
             
            while(t--)
            {
                c1 = q.front().first;
                c2 = q.front().second;
                
                q.pop();
                visited[c1][c2] = true;
                
                // cout<<c1<<" "<<c2<<" "<<endl;
                
                if(c1 != or1 or c2 != or2)
                {
                    
                    if(c1 == 0 or c2 == 0 or c1 == m-1 or c2 == n-1)
                    {
                        return steps;
                    }
                }
            

                if((c1 - 1) >= 0 and maze[c1-1][c2] != '+' and visited[c1-1][c2] == false)
                {
                    
                    if((c1 - 1 == 0  or c2 == n-1) and ((c1 - 1) != or1 or c2 != or2))
                    {
                        steps++;
                        return steps;
                    }
                    else
                    {
                        q.push({c1-1,c2});
                        visited[c1-1][c2] = true;
                    }
                }

                if((c2 - 1) >= 0 and maze[c1][c2-1] != '+' and visited[c1][c2-1] == false)
                {
                    if((c2 - 1 == 0 or c1 == m-1)  and (c1 != or1 or (c2 - 1) != or2))
                    {
                        steps++;
                        return steps;
                    }
                    else
                    {
                        q.push({c1,c2-1});
                        visited[c1][c2-1] = true;
                    }
                }

                if((c1 + 1) < m and maze[c1+1][c2] != '+' and visited[c1+1][c2] == false)
                {
                    if(((c1+1) == m-1 or c2 == 0) and ((c1 + 1) != or1 or c2 != or2))
                    {
                        steps++;
                        return steps;
                    }
                    else
                    {
                        q.push({c1+1,c2});
                        visited[c1+1][c2] = true;
                    }
                }
                

                if((c2 + 1) < n and maze[c1][c2+1] != '+' and visited[c1][c2+1] == false)
                {
                    if(((c2+1) == n-1 or c1 == 0) and (c1 != or1 or (c2 + 1) != or2))
                    {
                        steps++;
                        return steps;
                    }
                    else
                    {
                        q.push({c1,c2+1});   
                        visited[c1][c2+1] = true;
                    }
                    
                }
                
                if(q.size() == 0)
                {
                    return -1;
                }
                
            }
            
            steps++;
        }
        

        return steps;
    
    }
};