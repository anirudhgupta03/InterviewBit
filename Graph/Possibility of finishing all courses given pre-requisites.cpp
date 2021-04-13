/*Topological Sorting
B is basically source
C is your destination.
C nodes are dependent on B nodes correspondingly.
*/
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    vector<int> al[A+1];
    vector<int> in(A+1,0);
   
    
    for(int i = 0; i < C.size(); i++){
        al[B[i]].push_back(C[i]);
        in[C[i]]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= A; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    vector<int> res;
    
    while(!q.empty()){
        int curr = q.front();
        res.push_back(curr);
        
        q.pop();
        for(int i = 0; i < al[curr].size(); i++){
            int node = al[curr][i];
            
            in[node]--;
            if(in[node] == 0) q.push(node);
        }
    }
    
    if(res.size() == A) return 1;
    return 0;
}
