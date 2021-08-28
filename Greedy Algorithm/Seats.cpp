//Ref: https://www.youtube.com/watch?v=SK2ypa7poKg
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::seats(string A) {
    
    int n = 0;
    
    for(auto x : A){
        
        if(x == 'x'){
            n++;
        }
    }
    int arr[n],j=0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == 'x'){
            arr[j] = i;
            j++;
        }
    }
    
    int mid = n/2;
    
    int jumps = 0;
    
    for(int i = 0; i < n; i++){
        
        int start = arr[i];
        int end = arr[mid] - mid + i;
        
        jumps = (jumps + abs(start - end))%10000003;
    }
    return jumps%10000003;
}

int Solution::seats(string A) {

    vector<int> pos;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == 'x'){
            pos.push_back(i);
        }
    }

    if(pos.size() <= 1){
        return 0;
    }
    int mid = pos.size()/2;

    int jumps = 0, mod = 10000003;

    int p1 = pos[mid], p2 = mid;
    
    while(p1 >= 0 && p2 >= 0){
        jumps = (jumps + (p1 - pos[p2]))%mod;
        p1--;
        p2--;
    }

    p1 = pos[mid] + 1, p2 = mid + 1;

    while(p1 < A.size() && p2 < pos.size()){
        jumps = (jumps + (pos[p2] - p1))%mod;
        p2++;
        p1++;
    }

    return jumps;
}
