//Method - 1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ll long long
long Solution::coveredNodes(TreeNode* A) {

    if(A == NULL){
        return 0;
    }

    queue<TreeNode*> q;
    q.push(A);

    vector<int> boundary;
    ll sum = 0, boundarySum = 0;
    while(!q.empty()){
        int sz = q.size();
        bool flag1 = false, flag2 = false;
        int ele1, ele2;
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();
            sum += curr -> val;
            if(!flag1){
                flag1 = true;
                ele1 = curr -> val;
            }
            else{
                flag2 = true;
                ele2 = curr -> val;
            }
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
        if(flag1){
            boundarySum += ele1;
        }
        if(flag2){
            boundarySum += ele2;
        }
    }
    ll coveredSum = sum - boundarySum;
    return abs(boundarySum - coveredSum);
}

//Method - 2
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long Solution::coveredNodes(TreeNode* A) {
    long totalSum = 0, uncoveredSum = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        int tsz = sz;
        while(tsz--){
            if(tsz == sz - 1 || tsz == 0){
                uncoveredSum += q.front() -> val;
            }
            TreeNode* curr = q.front();
            totalSum += curr -> val;
            q.pop();
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
    }
    long coveredSum = totalSum - uncoveredSum;
    return abs(coveredSum - uncoveredSum);
}
