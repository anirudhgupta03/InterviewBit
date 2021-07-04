int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    if(n == 0){
        return 0;
    }
    map<double,int> points;
    int maxpoints = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if(i == j) continue;
            double slope;
            if(A[i] == A[j]) slope = 1e9;
            else slope = ((double)(B[j]-B[i])/(A[j]-A[i]));
            
            points[slope]++;
            maxpoints = max(maxpoints,points[slope]);
        }
        points.clear();
    }
    return maxpoints + 1;
}
