class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(); if(row==0) return 0;
        int col = grid[0].size(); if(col==0) return 0;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(i==0&&j==0) continue;
                int sum=INT_MAX;
                if(i!=0) sum=min(sum, grid[i-1][j]);
                if(j!=0) sum=min(sum, grid[i][j-1]);
                grid[i][j]+=sum;
            }
        }
        return grid[row-1][col-1];
    }
};