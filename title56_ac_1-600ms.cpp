/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp( const Interval& i1, const Interval& i2)
{
    if(i1.start==i2.start)
    {
        return i1.end<i2.end;
    }
    return i1.start<i2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size()==0) return ret;
        sort( intervals.begin(), intervals.end(), cmp);
        //Interval;
        ret.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i)
        {
            Interval& pre = *(ret.end()-1);
            if(pre.end>=intervals[i].start)
            {
                pre.end = max( pre.end, intervals[i].end);
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};