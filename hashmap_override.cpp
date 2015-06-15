#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<string> anagrams(vector<string>& strs){
        unordered_map<string, int, Hash, Pred> table;
        vector<string > res;

        for (auto e : strs){
            auto it = table.find(e);
            if (it == table.end()){
                table[e] = 1;
            }
            else{
                it->second++;
                res.push_back(e);
            }
        }

        for (auto i : table){
            if (i.second > 1) res.push_back(i.first);
        }
        return res;
    }
private:
    struct Hash{
        size_t operator ()(string s)const{
            size_t res = 0;
            for (auto c : s){
                res += c*c;
            }
            return res;
        }
    };
    struct Pred{
        bool operator()(const string& x, const string& y)const{
            string x_ = x, y_ = y;
            sort(x_.begin(), x_.end());
            sort(y_.begin(), y_.end());
            return x_ == y_;
        }
    };
};