//Method - 1
//Time Complexity - O(2*Nlog(2*N))
//Space Complexity - O(N)
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i< arrive.size(); i++){
        v.push_back(make_pair(arrive[i],1));
    }
    for(int i = 0; i< depart.size(); i++){
        v.push_back(make_pair(depart[i],-1));
    }
    
    sort(v.begin(),v.end());
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        count += v[i].second;
        
        if(count > K)
            return false;
    }
    
    return true;
}
//Method - 2
//Greedy Technique
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    int n = arrive.size();
    
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    
    int count = 1;
    
    int p1 = 1, p2 = 0;
    
    while(p1 < n){
        
        if(arrive[p1] >= depart[p2]){
            p1++;
            p2++;
        }
        else{
            count++;
            p1++;
        }
    }
    
    if(count <= K){
        return true;
    }
    return false;
}
