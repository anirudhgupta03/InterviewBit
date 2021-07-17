int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void solve(int ind,int x, int y, vector<string> &board, bool &flag, string &word){
        
    if(ind == word.size()){
        flag = true;
        return;
    }
    for(int i = 0; i < 4; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo >= 0 && xo < board.size() && yo >= 0 && yo < board[0].size() && board[xo][yo] == word[ind]){
            solve(ind+1,xo,yo,board,flag,word);
        }
    }
}
int Solution::exist(vector<string> &board, string word) {

    int m = board.size(), n = board[0].size();
        
    for(int i = 0; i < board.size(); i++){
         for(int j = 0; j < board[0].size(); j++){
            
             if(word[0] == board[i][j]){
                 bool flag = false;
                 solve(1,i,j,board,flag,word);
                 if(flag){
                     return true;
                 }
             }
         }
     }
     return false;
}
