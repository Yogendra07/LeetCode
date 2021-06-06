class Solution 
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        
        int rows = box.size();
        int cols = box[0].size();
        vector<vector<char>> ans(cols,vector<char> (rows,' '));
    
        for(int i=0;i<rows;i++)
        {
            vector<char> v = box[i];
            
            for(int j=v.size()-1;j>=0;j--)  
            {
                if(v[j] == '*' or v[j] == '.')
                {
                    continue;
                }
                else
                {
                    int k = 0;
                    if(j + 1 <= v.size()-1 and v[j+1] == '.')
                    {
                        k = j + 1; 
                        while(k <= v.size()-1 and v[k] == '.')
                        {
                            k++;
                        }

                        if(k != j and k != j + 1)
                        {
                            box[i][k-1] = '#'; 
                            v[k-1] = '#';
                            box[i][j] = '.';
                            v[j] = '.';
                        }
                        else if(k == j+1)
                        {
                            box[i][k] = '#';
                            v[k] = '#';
                            box[i][j] = '.';
                            v[j] = '.';
                        }
                    } 
                }
            }
        }
    
        int y = 0;
        
        for(int i=0;i<cols;i++)
        {
            int x = rows - 1;
            
            for(int j=0;j<rows;j++)
            {
                ans[i][j] = box[x][y];
                x--;
            }
            y++;
        }
        
        return ans;
        
    }
};