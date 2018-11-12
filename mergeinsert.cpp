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
    
    bool intersection(Interval& l, Interval& r)
    {
        if (l.end>=r.start && l.end<=r.end) return true;
        if (r.end>=l.start && r.end<=l.end) return true;
        return false;
    }
    
    Interval merge(Interval& l, Interval& r)
    {
        return Interval(min(l.start,r.start),max(l.end,r.end));
    }
    
    void InsertVector (vector<Interval>& intervals, Interval& newInterval)
    {
        size_t vsize = intervals.size();
        if (vsize==0) intervals.push_back(newInterval);
        else {
            if (intersection(intervals[vsize-1],newInterval))
                intervals[vsize-1]=std::move(merge(intervals[vsize-1],newInterval));
            else
                intervals.push_back(newInterval);
        }
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        Interval& NowInterval=newInterval;
        for (auto& i : intervals)
        {
            if (i.start<NowInterval.start) InsertVector(ret,i);
            else{
                swap(i,NowInterval);
                InsertVector(ret,i);
            }
        }
        InsertVector(ret,NowInterval);
        return ret;
    }
};
