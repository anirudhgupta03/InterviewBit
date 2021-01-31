bool cmp(int a, int b){
    string s1,s2,s3,s4;
    s1 = to_string(a);
    s2 = to_string(b);
    s3 = s1 + s2;
    s4 = s2 + s1;
    return s3 > s4;
}
string Solution::largestNumber(const vector<int> &A) {
    
    vector<int> arr(A.size());
    for(int i = 0; i < A.size(); i++){
        arr[i] = A[i];
    }
    if(A.size()==0)
    return " ";
    sort(arr.begin(),arr.end(),cmp);
    
    string s;
    for(int i = 0; i < A.size(); i++){
        s += to_string(arr[i]);
    }
    if(s[0]=='0') return "0";
    return s;
}
