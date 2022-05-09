void solve(int ind, string &A, string &temp, vector<string> &res, unordered_map<char,string> &umap){
    if(ind == A.size()){
        res.push_back(temp);
        return;
    }
    for(int i = 0; i < umap[A[ind]].size(); i++){
        temp.push_back(umap[A[ind]][i]);
        solve(ind + 1, A, temp, res, umap);
        temp.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) {
    unordered_map<char,string> umap;
    umap['0'] = "0";
    umap['1'] = "1";
    umap['2'] = "abc";
    umap['3'] = "def";
    umap['4'] = "ghi";
    umap['5'] = "jkl";
    umap['6'] = "mno";
    umap['7'] = "pqrs";
    umap['8'] = "tuv";
    umap['9'] = "wxyz";
    vector<string> res;
    string temp;
    solve(0, A, temp, res, umap);
    return res;
}
