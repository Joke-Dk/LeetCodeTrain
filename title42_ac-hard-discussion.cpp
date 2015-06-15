class Solution {
public:
	int trap(vector<int>& height) {
        int pre = 0, next = height.size()-1;
        int total = 0;
        while( pre<next)
        {
            int minHeight = min( height[pre], height[next]);
            while( pre<next && height[pre]<=minHeight)
            {
                total += minHeight-height[pre];
                pre++;
            }
            while( pre<next && height[next]<=minHeight)
            {
                total += minHeight-height[next];
                next--;
            }
        }
        return total;
	}
};
