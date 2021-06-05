//Brute Force Approach
//Time Complexity - O(N^3)
//Space Complexity - O(1)
//Consider all possible subarrays. -O(N^2)
//Find the sum of all the elements in that particular subarray and update ans. -O(N)

//Better Approach
//Time Complexity - O(N^2)
//Space Complexity - O(N)
//Create a prefix array of sum. Sum of all the elements present in a subarray can be computed in O(1) time using this prefix array
//Or we can take a sum variable initialized with 0 in the beginning of j loop and add to it the element at jth position. So the space complexity - O(1) 

//Optimal Approach
//Time Complexity - O(N)
//Space Complexity - O(1)
//Kadane's Algorithm
//The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array (curr_sum is used for this). 
//And keep track of maximum sum contiguous segment among all positive segments (max_sum is used for this). 
//Each time we get a positive-sum compare it with max_sum and update max_sum if it is greater than max_sum. 
//Ref: https://www.youtube.com/watch?v=w_KEocd__20

int Solution::maxSubArray(const vector<int> &A) {
    
    int curr_sum = 0, max_sum = INT_MIN;
    
    for(int i = 0; i < A.size(); i++){
        
        curr_sum += A[i];
        
        max_sum = max(max_sum,curr_sum);
        
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_sum;
}
