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
Time complexity : O(nlogn)

Other than the sort invocation, we do a simple linear scan of the list, so the runtime is dominated by the O(n\log{}n)O(nlogn) complexity of sorting.

Space complexity : O(logN) (or O(n))

If we can sort intervals in place, we do not need more than constant additional space, although the sorting itself takes O(\log n)O(logn) space. 
Otherwise, we must allocate linear space to store a copy of intervals and sort that.
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
