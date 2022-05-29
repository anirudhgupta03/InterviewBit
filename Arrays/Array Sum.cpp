vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {

    int carry = 0, i = A.size() - 1, j = B.size() - 1;

    vector<int> res;

    while(i >= 0 && j >= 0){   
        int sum = A[i] + B[j] + carry;
        res.push_back(sum % 10);
        carry = sum/10;
        i--;
        j--;
    }
    while(i >= 0){
        int sum = A[i] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        i--;
    }
    while(j >= 0){
        int sum = B[j] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        j--;
    }
    if(carry) res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
}
