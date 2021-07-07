class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int l = 0;
        
        priority_queue<int>pq;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(l != k)
                {
                    pq.push(matrix[i][j]);
                    l++;
                }
                else
                {
                    int val = pq.top();
                    
                    if(matrix[i][j] < val)
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return pq.top();
        
    }
};