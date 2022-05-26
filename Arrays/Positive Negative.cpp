vector<int> Solution::solve(vector<int> &A) {

    vector<int> res;
    int pos = 0, neg = 0;

    for(int x: A){
        if(x < 0) neg++;
        else if(x > 0) pos++;
    }
    res.push_back(pos);
    res.push_back(neg);
    return res;
}
