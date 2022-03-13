//Ref: https://www.youtube.com/watch?v=elADMOC_hDI
//Method - 1
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    if(n == 0){
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            A[i][j] += A[i][j-1];
        }
    }
    
    int count = 0;
    
    for(int c1 = 0; c1 < m; c1++){
        for(int c2 = c1; c2 < m; c2++){
            
            unordered_map<int,int> umap;
            umap[0] = 1;
            
            int sum = 0;
            
            for(int row = 0; row < n; row++){
                sum += A[row][c2] - (c1 > 0 ? A[row][c1-1] : 0);
                count += umap[sum];
                umap[sum]++;
            }
        }
    }
    
    return count;
}

//Method - 2
//TC - O(n*n*m)
//SC - O(n*m)
void countSubarrays(vector<int> &v, int &count){

    int sum = 0;
    unordered_map<int,int> umap;

    for(int i = 0; i < v.size(); i++){

        sum += v[i];

        if(sum == 0){
            count++;
        }
        
        if(umap.find(sum) != umap.end()){
            count += umap[sum];
        }
        umap[sum]++;
    }
}
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    
    if(n == 0){
        return 0;
    }
    int m = A[0].size();
    int prefix[n+1][m];

    for(int j = 0; j < m; j++){
        prefix[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            prefix[i][j] = A[i-1][j] + prefix[i-1][j];
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            vector<int> temp;
            for(int k = 0; k < m; k++){
                temp.push_back(prefix[j][k] - prefix[i-1][k]);
            }
            countSubarrays(temp,count);
        }
    }
    return count;
}
