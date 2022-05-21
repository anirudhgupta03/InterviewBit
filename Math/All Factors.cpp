vector<int> Solution::allFactors(int A) {

    vector<int> res;
    int i;
    for(i = 1; i * i < A; i++){
        if(A % i == 0){
            res.push_back(i);
        }
    }
    if(i * i == A) res.push_back(i);

    for(int i = res.size() - 1; i >= 0; i--){
        if(A % res[i] == 0 && A / res[i] != res[i]){
            res.push_back(A/res[i]);
        }
    }
    return res;
}
