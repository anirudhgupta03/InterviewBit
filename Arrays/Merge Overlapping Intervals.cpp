/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval i1,Interval i2){
    return i1.start < i2.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    
    
    sort(A.begin(),A.end(),cmp);
    
    vector<Interval> v;
    
    Interval newInterval;
    
    newInterval.start = A[0].start;
    newInterval.end = A[0].end;
    
    int flag = 0;
    for(int i = 1; i < A.size(); i++){
        
        if(A[i].start <= newInterval.end){
            newInterval.end = max(newInterval.end,A[i].end);
        }
        else{
            v.push_back(newInterval);
            newInterval.start = A[i].start;
            newInterval.end = A[i].end;
        }
    }
    v.push_back(newInterval);
    return v;
}
