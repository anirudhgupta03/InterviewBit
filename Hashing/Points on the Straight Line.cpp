//Method - 1
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

//Method - 2
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int maxPoints = 2;
        
    for(int i = 0; i < n; i++){
        
        unordered_map<double,int> umap;
        int x1 = A[i], y1 = B[i];  
        double slope;
          
        for(int j = 0; j < n; j++){
            
            if(j == i) continue;
            
            int x2 = A[j], y2 = B[j];
            
            if(x1 == x2) slope = INT_MAX;
            else slope = (double)(y2 - y1)/(x2 - x1);
            
            if(umap.find(slope) != umap.end()){
                umap[slope]++;
                maxPoints = max(maxPoints, umap[slope]);
            }
            else{
                umap[slope] = 2;
            }
        }
    }
    return maxPoints;
}
