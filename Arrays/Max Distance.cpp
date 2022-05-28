//Method - 1
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
int Solution::maximumGap(const vector<int> &A) {
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i < A.size(); i++){
        v.push_back(make_pair(A[i],i));
    }
    
    sort(v.begin(),v.end());
    
    int i = v[v.size()-1].second ,ans = 0;
    for(int j = v.size()-2; j >= 0; j--){
        ans = max(ans,i - v[j].second);
        i = max(v[j].second,i);
    }
    return ans;
}

//Method - 2
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
int Solution::maximumGap(const vector<int> &A) {

    int n = A.size();

    vector<pair<int,int>> v(n);

    for(int i = 0; i < n; i++){
        v[i] = {A[i], i};
    }

    sort(v.begin(), v.end());

    int ind = INT_MAX, maxDist = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i].second < ind){
            ind = v[i].second;
        }
        maxDist = max(maxDist, v[i].second - ind);
    }
    return maxDist;
}

//Method - 3
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    int right[n];
    
    right[n-1] = A[n-1];
    
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1],A[i]);
    }
    
    int ans = 0, j = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        while(A[i] <= right[j] && j < A.size()){
            j++;
        }
        ans = max(ans,j-i-1);
    }
    return ans;
}

//Method - 4
//Time Complexity - O(N)
//Space Complexity - O(N)
//Ref: https://www.youtube.com/watch?v=NBJiITBj52M
int Solution::maximumGap(const vector<int> &A) {

    int n = A.size();

    vector<int> suffix(n);
    suffix[n - 1] = A[n - 1];

    for(int i = n - 2; i >= 0; i--){
        suffix[i] = max(suffix[i + 1], A[i]);
    }

    int i = 0, j = 0, ans = 0;

    while(i < n && j < n){

        if(A[i] <= suffix[j]){
            ans = max(ans, j - i);
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}
