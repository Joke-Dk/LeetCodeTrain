class Solution {
public:
    int N;
    void rotateCell( vector<vector<int>>& matrix, int row, int col)
    {
        int preVal = matrix[row][col];
        for( int i=0; i<4; ++i)
        {
            //next postion
            int rowNext = col;
            int colNext = N-1-row;
            swap( matrix[rowNext][colNext], preVal);
            row = rowNext;
            col = colNext;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        N = matrix.size();
        bool isEven = (matrix.size()%2==0);
        int rowLimit = isEven?matrix.size()/2-1: matrix.size()/2;
        int colLimit = isEven?matrix.size()/2-1: matrix.size()/2-1;
        for( int i=0; i<=rowLimit; ++i)
        {
            for( int j=0; j<=colLimit; ++j)
            {
                rotateCell(matrix, i, j);
            }
        }
    }
};