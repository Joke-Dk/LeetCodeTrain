class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> vec(9, 0);
        //row
        for( int i=0; i<9; ++i)
        {
            fill( vec.begin(), vec.end(), 0);
            for( int j=0; j<9; ++j)
            {
                if(board[i][j]!='.')
                {
                    int idx = board[i][j] - '1';
                    if( vec[idx]) return false;
                    vec[idx] = 1;
                }
            }
        }
        
        //col
        for( int i=0; i<9; ++i)
        {
            fill( vec.begin(), vec.end(), 0);
            for( int j=0; j<9; ++j)
            {
                if(board[j][i]!='.')
                {
                    int idx = board[j][i] - '1';
                    if( vec[idx]) return false;
                    vec[idx] = 1;
                }
            }
        }
        
        //grid
        for(int i=0; i<9; ++i)
        {
            int row0 = (i/3)*3;
            int col0 = (i%3)*3;
            fill( vec.begin(), vec.end(), 0);
            for( int j=0; j<9; ++j)
            {
                int row1 = (j/3);
                int col1 = (j%3);
                char ch = board[row0+row1][col0+col1];
                if( ch!='.')
                {
                    int idx = ch - '1';
                    if( vec[idx]) return false;
                    vec[idx] = 1;
                }
            }
        }
        return 1;
    }
};