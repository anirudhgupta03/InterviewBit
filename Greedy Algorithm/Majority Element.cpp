//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(1)
// The brute force algorithm iterates over the array, and then iterates again for each number to count its occurrences. 
// As soon as a number is found to have appeared more than any other can possibly have appeared, return it.


//Method - 2
//Using Hashmap
//Time Complexity - O(N)
//Space Complexity - O(N)
// We can use a HashMap that maps elements to counts in order to count occurrences in linear time by looping over nums. 
// Then, we simply return the key with maximum value.


//Method - 3
//Optimal Approach
//Boyer Moore Voting Algorithm
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::majorityElement(const vector<int> &A) {
    
    int ele = A[0], count = 1;
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i] != ele){
            count--;
        }
        else{
            count++;
        }
        
        if(count == 0){
            ele = A[i];
            count = 1;
        }
    }
    return ele;
}
