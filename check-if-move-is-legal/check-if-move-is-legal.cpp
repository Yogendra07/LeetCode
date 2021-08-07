class Solution 
{
public:
    bool check(vector<vector<char>>& board,int dr,int dc,int x,int y,char color)
    {
        int R = board.size();
        int C = board[0].size();
        
        char opp = color == 'B' ? 'W' : 'B';
        
        int moves = 0;
        
        while(x >= 0 and y >= 0 and x <= R-1 and y <= C-1 and board[x][y] == opp)
        {
            moves++;
            x += dr;
            y += dc;
        }
        
        if(x < 0  or y < 0 or x >= R or y >= C)
        {
            return false;
        }
        
        if(moves >= 1 and board[x][y] == color)
        {
            return true;
        }
        
        return false;
    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) 
    {
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,0,-1,1};
        
        for(int i=0;i<8;i++)
        {
            if(check(board,dr[i],dc[i],rMove+dr[i],cMove+dc[i],color))
            {
                return true;
            }
        }
        
        return false;
    }
};