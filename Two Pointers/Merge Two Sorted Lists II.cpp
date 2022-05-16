//Method - 1
//Time Complexity - O(min(m,n))
//Space Complexity - O(m+n)
void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> C = A;
    A.clear();
    int p1 = 0 , p2 = 0;
    while(true){
        if(p1 == C.size() || p2 == B.size())
            break;
        if(C[p1] < B[p2]){
            A.push_back(C[p1]);
            p1++;
        }
        else if(C[p1] > B[p2]){
            A.push_back(B[p2]);
            p2++;
        }else if(C[p1] == B[p2]){
            A.push_back(C[p1]);
            A.push_back(B[p2]);
            p1++;
            p2++;
        }
    }
    if(p1 == C.size() && p2 < B.size()){
        while(p2 < B.size()){
            A.push_back(B[p2]);
            p2++;
        }
    }
    if(p2 == B.size() && p1 < C.size()){
        while(p1 < C.size()){
            A.push_back(C[p1]);
            p1++;
        }
    }
}

//Method - 2
//Time Complexity - O(NlogN + MlogM)
//Space Complexity - O(1)
void Solution::merge(vector<int> &A, vector<int> &B) {
    
    int n = A.size(), m = B.size();
    
    int p1 = n - 1, p2 = 0;
    
    while(p1 >= 0 && p2 < m){
        
        if(A[p1] > B[p2]){
            swap(A[p1],B[p2]);
        }
        p1--;
        p2++;
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    for(int i = 0; i < m; i++){
        A.push_back(B[i]);
    }
}

//Method - 3
//TC - O(m + n)
//SC - O(1)
void Solution::merge(vector<int> &A, vector<int> &B) {
    
    int m = A.size(), n = B.size();

    int i = m - 1, j = n - 1, k = n + m - 1;

    A.resize(m + n);
    
    while(i >= 0 && j >= 0){
        if(A[i] > B[j]){
            A[k] = A[i];
            k--;
            i--;
        }
        else{
            A[k] = B[j];
            k--;
            j--;
        }
    }

    while(i >= 0){
        A[k] = A[i];
        k--;
        i--;
    }
    while(j >= 0){
        A[k] = B[j];
        k--;
        j--;
    }
}
