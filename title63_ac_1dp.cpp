class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp = obstacleGrid;
        for( int i=0; i<obstacleGrid.size(); ++i)
        {
            for( int j=0; j<obstacleGrid[0].size(); ++j)
            {
                if(obstacleGrid[i][j]==1) obstacleGrid[i][j]=0;
                else if(i==0&&j==0) obstacleGrid[i][j]=1;
                else
                {
                    int num = 0;
                    if(i!=0) num+=obstacleGrid[i-1][j];
                    if(j!=0) num+=obstacleGrid[i][j-1];
                    obstacleGrid[i][j] = num;
                }
            }
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};