int Solution::highestScore(vector<vector<string> > &A) {

    unordered_map<string,int> umap1, umap2;

    for(int i = 0; i < A.size(); i++){
        umap1[A[i][0]] += stoi(A[i][1]);
        umap2[A[i][0]]++;
    } 

    int maxAvg = 0;

    for(auto x: umap1){
        maxAvg = max(maxAvg, (x.second)/umap2[x.first]);
    }
    return maxAvg;
}
