//Method - 1
vector<int> Solution::solve(vector<int> &A) {
    
    unordered_map<int,vector<int>> umap;  //Unordered Map to store the indexes where an element is present
    
    vector<int> res;
    
    for(int i = 0; i < A.size(); i++){
        
        res.push_back(A[i]);
      
        if(umap.find(A[i]) == umap.end()){  //check whether that number previously occurred or not
            umap[A[i]].push_back(i);
        }
        else{
            int ind1 = INT_MAX, ind2;
            
            vector<int> v = umap[A[i]];
            
            for(int j = 0; j < v.size(); j++){  //number occurred, so taking minimum index of that number
                if(ind1 > v[j]){
                    ind1 = v[j];
                    ind2 = j;
                }
            }
            v.erase(v.begin()+ind2);  //deleting the minimum index from v
            
            v.push_back(i);   //inserting the new current index pf the number
            
            umap[A[i]+1].push_back(ind1); //inserting the minimum index
            
            res[ind1]++;    //incrementing the value at minimum index in res vector
            
            umap[A[i]] = v; //Assigning updated vector of indexes 
        }
    }
    return res;
}

//Method - 2
//Optimal
vector<int> Solution::solve(vector<int> &A) {
    
    unordered_map<int,int> umap;
    vector<int> res(A.size());
    
    for(int i = 0; i < A.size(); i++){
        if(umap.find(A[i]) != umap.end()){
            int ind = umap[A[i]];
            res[ind]++;
            if(umap.find(res[ind]) == umap.end() || ind < umap[res[ind]]){
                umap[res[ind]] = ind;
            }
        }
        umap[A[i]] = i;
        res[i] = A[i];
    }
    return res;
}
