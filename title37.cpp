class Solution {
public:
    void update( int i, int j, char ch)
    {
        row[i].insert(ch);
        col[j].insert(ch);
        grid[i/3][j/3].insert(ch);
    }
    void erase( int i, int j, char ch)
    {
        row[i].erase(ch);
        col[j].erase(ch);
        grid[i/3][j/3].erase(ch);
    }
    void recusive( int i, int j)
    {
        bool hasempty = 0;
        //find the first empty cell
        while(i<9&&j<9)
        {
            if(data[i][j]=='.')
            {
                hasempty = 1;
                break;
            }
            i++;
            if(i==9)
            {
                i=0;
                j++;
            }
        }
        
        if(!hasempty) 
        {
            finish = 1;
            return;
        }
        for( int k=0; k<9; ++k)
        {
            char ch = '1'+k;
            if( row[i].find(ch)==row[i].end() && col[j].find(ch)==col[j].end() && grid[i/3][j/3].find(ch)==grid[i/3][j/3].end())
            {
                data[i][j] = ch;
                update(i, j, ch);
                recusive(i, j);
                if(finish) return;
                erase(i, j, ch);
                data[i][j] = '.';
            }
        }
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        data = board;
        //update the hash_set
        for( int i=0; i<9; ++i)
        {
            for (int j=0; j<9; ++j)
            {
                char ch = board[i][j];
                if( ch!='.')
                {
                    update(i, j, ch);
                }
            }
        }
        finish = 0;
        recusive(0, 0);
        board = data;
    }
    bool finish;
    vector<vector<char>> data;
    unordered_set<char> row[9];
    unordered_set<char> col[9];
    unordered_set<char> grid[3][3];
};