class Solution {
public:
    int count;
    int K, N;
    bool visits[10];
    string str;
    bool found;
    void recusive( int idx)
    {
        if(found) return;
        if(idx==N)
        {
            count++;
            if(count==K)
            {
                found = 1;
            }
            return;
        }
        for(int i=0; i<N; ++i)
        {
            if(visits[i]) continue;
            visits[i] = 1;
            str.push_back('1'+i);
            recusive( idx+1);
            if(found) return;
            str.pop_back();
            visits[i] = 0;
        }
        
    }
    string getPermutation(int n, int k) {
        count = 0, found = 0;
        fill( visits, visits+10, false);
        N = n; K = k;
        recusive( 0);
        return str;
    }
    
};