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
