class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret( n, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<int> dis = {n, n-1};
        int idx = 0;
        int ir = 0, ic = -1;
        int count = 1;
        while(dis[idx%2])
        {
            for(int i=0; i<dis[idx%2]; ++i)
            {
                ir+=dirs[idx][0];
                ic+=dirs[idx][1];
                ret[ir][ic] = count++;
            }
            dis[idx%2]--;
            idx = (idx+1)%4;
        }
        return ret;
        
    }
};