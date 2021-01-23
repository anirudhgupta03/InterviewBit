/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<Interval> v;
    
    int begin = newInterval.start, finish = newInterval.end, flag=0;
    
    for(int i = 0; i < intervals.size(); i++){
        
        if(intervals[i].end < begin){
            v.push_back(intervals[i]);
        }
        else if(intervals[i].start > finish){
            
            if(flag == 0){
                v.push_back({begin,finish});
            }
            v.push_back(intervals[i]);
            flag = 1;
        }
        else{
            begin = min(begin,intervals[i].start);
            finish = max(finish,intervals[i].end);
        }
    }
    if(flag == 0){
        v.push_back({begin,finish});    
    }
    return v;
}
