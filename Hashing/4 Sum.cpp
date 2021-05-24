vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    set<vector<int>> s;
    
    vector<vector<int>> res;
    
    if(A.size() < 4){
        return res;
    }
    sort(A.begin(),A.end());
    
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    
    while(p1 <= A.size() - 4){
        
        p2 = p1 + 1;
        
        while(p2 <= A.size() - 3){
            
            p3 = p2 + 1;
            p4 = A.size() - 1;
            
            while(p3 < p4){
                
                int sum = A[p1] + A[p2] + A[p3] + A[p4];
                
                if(sum == B){
                    
                    vector<int> temp;
                    temp.push_back(A[p1]);
                    temp.push_back(A[p2]);
                    temp.push_back(A[p3]);
                    temp.push_back(A[p4]);
                    s.insert(temp);
                    
                    p3++;
                    p4--;
                }
                else if(sum < B){
                    p3++;
                }
                else{
                    p4--;
                }
            }
            
            p2++;
        }
        p1++;
    }
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it != s.end(); it++){
        res.push_back(*it);
    }
    return res;
}
