//Method - 1
int Solution::solve(int A) {

    vector<int> bits;

    while(A){
        int bit = A % 2;
        bits.push_back(1 - bit);
        A /= 2;
    }
    reverse(bits.begin(), bits.end());
    
    int ans = 0, i = 0;
    
    while(i < bits.size() && bits[i] == 0) i++;

    while(i < bits.size()){
        if(bits[i]) ans += (1 << (bits.size() - i - 1));
        i++;
    }
    return ans;
}

//Method - 2
int Solution::solve(int A) {

    int x = 1;
    while(x <= A){
        x <<= 1;
    }
    x--;
    return (x ^ A);
}

//Method - 3
int Solution::solve(int A) {
    
    int i = 0, ans = 0;
    
    while(A){
        int bit = (A % 2);
        if(bit == 0){
            ans += (1 << i);
        }
        i++;
        A /= 2;
    }
    return ans;
}
