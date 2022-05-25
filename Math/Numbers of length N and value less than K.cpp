//Ref: https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
int Solution::solve(vector<int> &A, int B, int C) {

    int n = A.size();

    if(n == 0) return 0;

    int temp = C, count = 0, ans = 0;

    while(temp){
        count++;
        temp /= 10;
    }

    if(count < B){
        return 0;
    }

    if(count > B){
        if(A[0] == 0){
            ans = (n - 1)*pow(n, B - 1);
        }
        else{
            ans = pow(n, B);
        }
        if(B == 1 && A[0] == 0){
            ans++;
        }
        return ans;
    }

    if(B == 1){
        for(int i = 0; i < A.size(); i++){
            if(A[i] < C) ans++;
        }
        return ans;
    }

    vector<int> v(B);

    for(int i = B - 1; i >= 0; i--){
        v[i] = C % 10;
        C /= 10;
    }

    count = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 0) continue;
        if(A[i] > v[0]) break;
        count++;
    }

    ans += (count)*pow(A.size(), B - 1);    //this ans contains extra values

    int j = 0, flag = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == v[0]){
            flag = 1;
        }
    }
    j++;
    while(flag && j <= B - 1){
        flag = 0;
        int countx = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] > v[j]){
                countx++;
            }
            if(A[i] == v[j]){
                flag = 1;
            }
        }
        ans -= countx*(pow(A.size(), B - j - 1));
        j++;
    }
    if(j == B && flag == 1) ans--;

    return ans;
}
