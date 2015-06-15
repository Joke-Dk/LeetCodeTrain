class Solution {
public:
    string getId( string str)
    {
        string sort_str = str;
        sort(sort_str.begin(), sort_str.end());
        return sort_str;
    }
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ret;
        unordered_map< string, pair<string, bool>> umap;
        for( int i=0; i<strs.size(); ++i)
        {
            string id = getId( strs[i]);
            if(umap.find(id)!=umap.end())
            {
                if(umap[id].second)
                {
                    ret.push_back(umap[id].first);
                    umap[id].second = 0;
                }
                ret.push_back(strs[i]);
            }
            else
            {
                umap[id] = make_pair(strs[i], true);
            }
        }
        return ret;
    }
};