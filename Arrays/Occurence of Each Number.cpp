vector<int> Solution::findOccurences(vector<int> &A) {

    map<int,int> mp;

    for(int x: A){
        mp[x]++;
    }

    vector<int> res;
    for(auto x: mp){
        res.push_back(x.second);
    }
    return res;
}
