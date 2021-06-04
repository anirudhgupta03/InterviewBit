//Ref: https://www.youtube.com/watch?v=Oop18EH4T28
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
