vector<int> Solution::powerfulDivisors(vector<int> &A) {

    int maxVal = *max_element(A.begin(), A.end());

    vector<int> v(maxVal + 1, 2);
    v[1] = 1;

    for(int i = 2; i * i <= maxVal; i++){
        for(int j = i * i; j <= maxVal; j += i){
            v[j]++;
            if(j != i * i) v[j]++;
        }
    }

    vector<int> count(maxVal + 1, 0);
    count[1] = 1;
    for(int i = 2; i <= maxVal; i++){
        if((v[i] & (v[i] - 1)) == 0){
            count[i] = count[i - 1] + 1;
        }
        else{
            count[i] = count[i - 1];
        }
    }
    vector<int> res;
    for(int i = 0; i < A.size(); i++){
        res.push_back(count[A[i]]);
    }
    return res;
}
