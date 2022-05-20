//Ref: https://www.youtube.com/watch?v=rxwoWYJqaNc
vector<string> Solution::fullJustify(vector<string> &A, int B) {

    vector<string> ans;

    int i = 0;

    while(i < A.size()){

        int j = i;
        int totalLen = A[j].size(), spaces = 0;
        j++;

        while(j < A.size() && totalLen + A[j].size() + spaces + 1 <= B){
            totalLen += A[j].size();
            spaces++;
            j++;
        }   
        
        int spaceRemaining = B - totalLen;

        int atleast = spaces == 0 ? 0 : spaceRemaining / spaces;
        int extra = spaces == 0 ? 0 : spaceRemaining % spaces;

        if(j == A.size()){
            atleast = 1;
            extra = 0;
        }

        string res;
        for(int p = i; p < j; p++){
            res += A[p];
            if(p == j - 1) break;
            for(int k = 0; k < atleast; k++) res.push_back(' ');
            if(extra){
                res.push_back(' ');
                extra--;
            }
        }
        
        while(res.size() < B) res.push_back(' ');
        ans.push_back(res);
        i = j;
    }
    return ans;
}
