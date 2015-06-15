class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         vector<int> ret;
         unordered_map<string, int> umap;
         int len = words[0].length();
         int k = words.size();
         for( int i=0; i<words.size(); ++i)
         {
             if( umap.find( words[i]) == umap.end())
             {
                umap[words[i]] = 0;    
             }
             umap[words[i]]++;
         }
         int idx = 0;
         while( idx+len*k-1<s.length())
         {
             unordered_map<string, int> copymap = umap;
             int i;
             bool found = 1;
             for(i=0; i<k; ++i)
             {
                 string str = s.substr(idx+i*len, len);
                 if( copymap.find(str) == copymap.end())
                 {
                     found = 0;
                     break;
                 }
                 else
                 {
                     if(copymap[str]==0)
                     {
                         found = 0;
                         break;
                     }
                     copymap[str]--;
                 }
             }
             if( found) ret.push_back( idx);
             idx++;
         }
         return ret;
    }
};