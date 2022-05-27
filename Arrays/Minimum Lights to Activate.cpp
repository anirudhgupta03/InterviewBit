//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(N)
//Greedy Approach
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    vector<int> temp(n,-1);
    
    for(int i = 0; i < n; i++){
        
        if(A[i] == 1){
            int start = max(0,i-B+1);
            int end = min(i+B-1,n-1);
            
            for(int j = start; j <= end; j++){
                temp[j] = end;
            }
        }
    }
    
    int i = 0;
    int count = 0;
    
    while(i != n){
        i = temp[i];
        count++;
        if(i == -1){
            return -1;
        }
        i++;
    }
    return count;
}
//Method - 2
//Ref: https://www.youtube.com/watch?v=Oop18EH4T28
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::solve(vector<int> &A, int B) {
    
    int curr=0,count=0;
    int n=A.size();
    while(curr<n){
        int prev,next;
        prev=curr-B+1;
        next=curr+B-1;
        
        if(prev<0){
            prev=0;
        }
        
        while(next>=prev){
            if(A[next]) //Finding the right most bulb
            break;
            
            next--;
        }
        
        if(next>=prev){
            curr=next+B;  //Till next+B-1 there will be light 
            count++;
        }
        else
            return -1; //No unfaulty bulb available
    }
    return count;
}

//Method - 3
//Ref: https://www.youtube.com/watch?v=CQ0Tlu3o7Yg
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    int count = 0, curr = 0;

    while(curr < n){

        int pre = max(0, curr - B + 1);
        int next = min(n - 1,curr + B - 1);

        bool flag = false;

        while(next >= pre){
            if(A[next]){
                flag = true;
                break;
            }
            next--;
        }
        if(flag){
            count++;
            curr = next + B;
        }
        else{
            return -1;
        }
    }
    return count;
}
