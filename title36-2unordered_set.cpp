class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for( int i=0; i<9; ++i)
        {
            for( int j=0; j<9; ++j)
            {
                char ch = board[i][j];
                if(ch!='.')
                {
                    if( row[i].find(ch)==row[i].end() && col[j].find(ch)==col[j].end() && grid[i/3][j/3].find(ch)==grid[i/3][j/3].end())
                    {
                        row[i].insert(ch);
                        col[j].insert(ch);
                        grid[i/3][j/3].insert(ch);
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    unordered_set<char> row[9];
    unordered_set<char> col[9];
    unordered_set<char> grid[3][3];
};