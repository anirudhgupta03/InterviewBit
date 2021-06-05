//Optimal Approach
//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=DMeCURTi-iw
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
Cases

start = newInterval.start
end = newInterval.end

1) if end point of an interval is lesser than start then we have to just push.
2) if start point of an interval is greater than end then we have to push that interval but only after newInterval is pushed
3) else start = min(intervals[i].start, start)
        end = max(intervals[i].end, end)
4) Consider the case in which newInterval is completely out of all the intervals.
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
                flag = 1;
            }
            v.push_back(intervals[i]);
            
        }
        else{
            begin = min(begin,intervals[i].start);
            finish = max(finish,intervals[i].end);
        }
    }
    if(flag == 0){                      //If newInterval is completely out of the intervals of the array
        v.push_back({begin,finish});    
    }
    return v;
}
