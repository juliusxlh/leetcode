/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval& x, Interval& y)
    {
        return x.start<y.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        for (auto iter = intervals.begin(); iter!=intervals.end();){
            if (iter!=intervals.begin()){
                if (iter->start<=(iter-1)->end){
                    (iter-1)->end = max(iter->end,(iter-1)->end);
                    iter = intervals.erase(iter);
                } else ++iter;
            } else ++iter;
        }
        return intervals;
    }
};
