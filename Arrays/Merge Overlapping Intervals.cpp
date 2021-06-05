/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//Brute Force Approach
//A simple approach is to start from the first interval and compare it with all other intervals for overlapping, if it overlaps with any other interval, 
//then remove the other interval from the list and merge the other into the first interval. Repeat the same steps for remaining intervals after first. 
//This approach cannot be implemented in better than O(N^2) time.

//Optimal Approach
//Time complexity : O(NlogN)
//Other than the sort invocation, we do a simple linear scan of the list, so the runtime is dominated by the O(nlogn) complexity of sorting.
//Space complexity : O(1)

// If we can sort intervals in place, we do not need more than constant additional space, although the sorting itself takes O(\log n)O(logn) space. 
// Otherwise, we must allocate linear space to store a copy of intervals and sort that.

bool cmp(Interval i1,Interval i2){
    return i1.start < i2.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    
    sort(A.begin(),A.end(),cmp);
    
    vector<Interval> v;
    
    Interval newInterval;
    
    newInterval.start = A[0].start;
    newInterval.end = A[0].end;
  
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
