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
