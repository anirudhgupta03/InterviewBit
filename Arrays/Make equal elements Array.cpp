//Method - 1
//TC - O(N)
//SC - O(N)
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    int count = 0;

    unordered_map<int,int> umap;

    for(int i = 0; i < A.size(); i++){
        umap[A[i]]++;
    }

    if(umap.size() == 1) return 1;
    if(umap.size() > 3) return 0;

    vector<int> v;
    for(auto x: umap){
        v.push_back(x.first);
    }
    if(umap.size() == 2){
        if(abs(v[1] - v[0]) == B || abs(v[1] - v[0]) == 2*B){
            return 1;
        }
        return 0;
    }
    else{
        sort(v.begin(), v.end());
        if(v[1] - v[0] == B && v[2] - v[1] == B){
            return 1;
        }
        return 0;
    }
}

//Method - 2
//Optimal Approach
//TC - O(N)
//SC - O(1)
int Solution::solve(vector<int> &A, int B) {

    int add = A[0] + B, sub = A[0] - B, same = A[0];

    for(int x: A){
        if(x == add || x + B == add || x - B == add) continue;
        if(x == sub || x + B == sub || x - B == sub) continue;
        if(x == same || x + B == same || x - B == same) continue;
        return 0;
    }
    return 1;
}
