class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int>> dp( m, vector<int>( n, 0));
        dp[0][0] = 1;
        for( int r=0; r<m; ++r)
        {
            for( int c=0; c<n; ++c)
            {
                if(r==0&&c==0) continue;
                int num = 0;
                if(r!=0) num+=dp[r-1][c];
                if(c!=0) num+=dp[r][c-1];
                dp[r][c] = num;
            }
        }
        return dp[m-1][n-1];
    }
};