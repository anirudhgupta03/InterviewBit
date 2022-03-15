//Ref: https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/discussion/p/the-only-solution-you-need-to-solve-this-with-comments-and-explanation/61595/1073
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int rows = B.size();
    int cols = B[0].size();
    // take a cell, check out only its left, right, top, bottom, and itself. Pick the 
    // max of them all and replace the said current element in a new matrix. Do this
    //for all elements, and then replace this entire matrix with the newly calculated one
    // and repeat for K-1 times.
    
    // diagonal elements are not considered manhattan for an ele. U can only traverse 90 deg
    // in any direction at each iteration
    
    int maxDist = A;
    vector<vector<int>> currDistMatrix = B;
    vector<vector<int>> nextDistMatrix = B;
    
    while(A--){
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                int fin = -1;
                int currEle = currDistMatrix[i][j]; fin = max(fin, currEle);
                int top = (i == 0) ? -1:currDistMatrix[i-1][j]; fin = max(fin, top);
                int down = (i == rows-1) ? -1:currDistMatrix[i+1][j]; fin = max(fin, down);
                int left = (j == 0) ? -1:currDistMatrix[i][j-1]; fin = max(fin, left);
                int right = (j == cols-1) ? -1:currDistMatrix[i][j+1]; fin = max(fin, right);
                //pq.push(currEle); pq.push(top); pq.push(down); pq.push(left); pq.push(right);
                //nextDistMatrix[i][j] = pq.top(); // get the max element
                nextDistMatrix[i][j] = fin; // get the max element
            }
        }
        currDistMatrix = nextDistMatrix;
    }
    return currDistMatrix;
}
