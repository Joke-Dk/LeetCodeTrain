class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return 1;
        vector<int> vec;
        while( x!=0)
        {
            vec.push_back( x%10);
            x /= 10;
        }
        
        //judge
        for( int i=0; i<vec.size()/2; ++i)
        {
            if( vec[i]!= vec[vec.size()-1-i])
                return false;
        }
        return 1;
    }
};