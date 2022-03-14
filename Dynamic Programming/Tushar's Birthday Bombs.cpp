//Ref: https://www.interviewbit.com/problems/tushars-birthday-bombs/discussion/p/approaching-the-problem-without-dp/66172/1070
vector<int> Solution::solve(int A, vector<int> &B) {

    int n = B.size();

    int minEle = INT_MAX, minInd = -1;

    for(int i = 0; i < n; i++){
        if(B[i] < minEle){
            minEle = B[i];
            minInd = i;
        }
    }

    int maxHits = A/minEle;
    int remStrength = A%minEle;

    vector<int> res(maxHits, minInd);
    int i = 0, j = 0;

    while(remStrength > 0 && i < minInd && j < maxHits){
        int diff = B[i] - minEle;
        if(remStrength - diff >= 0){
            remStrength -= diff;
            res[j] = i;
            j++;
        }
        else{
            i++;
        }
    }
    return res;
}
