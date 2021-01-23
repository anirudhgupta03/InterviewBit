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
    
    if(intervals.empty()){
        v.push_back(newInterval);
        return v;
    }
    Interval newinterval;
    
    int i = 0;
    
    while(i < intervals.size()){
        
        if(i == 0 && (newInterval.start < intervals[i].start)){
            
            newinterval.start = newInterval.start;
            
            while(i < intervals.size()){
                
                if(newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end){
                    
                    newinterval.end = intervals[i].end;
                    
                    v.push_back(newinterval);
                    
                    i++;
                    
                    break;
                }
                else if(i==0 && newInterval.end < intervals[i+1].start){
                    
                    newinterval.end = newInterval.end;
                    
                    v.push_back(newinterval);
                    
                    v.push_back(intervals[i]);
                    
                    i++;
                    
                    break;
                }
                else if(i == intervals.size() -1 && (newInterval.end > intervals[i].end)|| newInterval.end > intervals[i].end && newInterval.end < intervals[i+1].start){
                    
                    newinterval.end = newInterval.end;
                    
                    v.push_back(newinterval);
                    
                    i++;
                    
                    break;
                }
                i++;
            }
        }
        else if(newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end){
            
            newinterval.start = intervals[i].start;
            
            while(i < intervals.size()){
                
                if(newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end){
                    
                    newinterval.end = intervals[i].end;
                    
                    i++;
                    
                    break;
                }
                else if(i == intervals.size() -1 && (newInterval.end > intervals[i].end) || newInterval.end > intervals[i].end && newInterval.end < intervals[i+1].start){
                    
                    newinterval.end = newInterval.end;
                    
                    i++;
                    
                    break;
                }
                i++;
            }
            v.push_back(newinterval);
        }
        else if(i == intervals.size() -1 && (newInterval.start > intervals[i].end) || newInterval.start > intervals[i].end && newInterval.start < intervals[i+1].start ){
            
            v.push_back(intervals[i]);
            
            newinterval.start = newInterval.start;
            
            while(i < intervals.size()){
                
                if(newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end){
                    
                    newinterval.end = intervals[i].end;
                    
                    i++;
                    
                    break;
                }
                else if(i == intervals.size() -1 && (newInterval.end > intervals[i].end) || newInterval.end > intervals[i].end && newInterval.end < intervals[i+1].start){
                    
                    newinterval.end = newInterval.end;
                    
                    i++;
                    
                    break;
                }
                i++;
            }
            v.push_back(newinterval);
        }
        else{
            v.push_back(intervals[i]);
            i++;
        }
    }
    
    return v;
}
