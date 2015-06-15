class Solution {
public:
    int N;
    vector< string> vec;
    int count;
    
    bool canInsert( int row, int col)
    {
        for( int i=0; i<row; ++i)
        {
            //if(vec[row][i]=='Q')return false;
            if(vec[i][col]=='Q')return false;
            if( col+i-row>=0 && col+i-row<=N-1 && vec[i][col+i-row]=='Q')return false;
            if( col-i+row>=0 && col-i+row<=N-1 && vec[i][col-i+row]=='Q')return false;
        }
        return true;
    }
    void backtracking( int row)
    {
        if(row==N) 
        {
            count++;
            return;
        }
        for( int i=0; i<N; ++i)
        {
            if(canInsert(row, i))
            {
                vec[row][i] = 'Q';
                backtracking(row+1);
                vec[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        count = 0;
        N = n;
        vec = vector<string>(n, string(n, '.'));
        backtracking(0);
        return count;
    }
};