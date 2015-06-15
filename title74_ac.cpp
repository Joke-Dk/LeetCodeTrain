class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int pre = 0, next = matrix.size()-1, mid = 0;
        while( pre<=next)
        {
            mid = (pre+next)/2;
            if(matrix[mid][0]>target)
            {
                next = mid-1;
            }
            else if(matrix[mid][0]<target)
            {
                pre = mid+1;
            }
            else
            {
                break;
            }
        }
        int row = matrix[mid][0]>target?mid-1:mid;
        if(row==-1) return 0;
        pre = 0; next = matrix[row].size()-1;
        while( pre<=next)
        {
            int mid = (pre+next)/2;
            if(matrix[row][mid]>target)
            {
                next = mid-1;
            }
            else if(matrix[row][mid]<target)
            {
                pre = mid+1;
            }
            else
            {
                return 1;
            }
        }
        return 0;
        
    }
};