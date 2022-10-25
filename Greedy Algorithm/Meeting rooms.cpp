//Approach - 1
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
//Ref: https://www.youtube.com/watch?v=dxVcMDI7vyI
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector<int> start(n), end(n);
    
    for(int i = 0; i < A.size(); i++){
        start[i] = A[i][0];
        end[i] = A[i][1];
    }
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int res = 1, count = 1, i = 1, j = 0;
    
    while(i < n){
        if(start[i] < end[j]){
            i++;
            count++;
        }
        else{
            count--;
            j++;
        }
        res = max(res, count);
    }
    return res;
}

//Approach - 2
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
//Ref: https://www.youtube.com/watch?v=qHmAwknX6OY&ab_channel=Pepcoding
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    
    if(n == 0){
        return 0;
    }
    int start[n], end[n];
    
    for(int i = 0; i < A.size(); i++){
        start[i] = A[i][0];
        end[i] = A[i][1];
    }
    sort(start,start+n);
    sort(end,end+n);
    
    int res = 1;
    
    int i = 1, j = 0;
    
    while(i < n && j < n){
        
        if(end[j] <= start[i]){
            i++;
            j++;
        }
        else{
            res++;
            i++;
        }
    }
    return res;
}

//Approach - 3
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
//Ref: https://www.youtube.com/watch?v=NKf1OJhEZj0&t=1631s&ab_channel=Pepcoding
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    sort(A.begin(), A.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(A[0][1]);
    
    for(int i = 1; i < n; i++){
        if(A[i][0] < pq.top()){
            pq.push(A[i][1]);
        }
        else{
            pq.pop();
            pq.push(A[i][1]);
        }
    }
    return pq.size();
}
