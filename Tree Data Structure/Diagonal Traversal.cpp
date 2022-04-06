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
void diagonalTraverse(TreeNode* A, map<int,vector<int>> &mymap, int d){
    
    if(A == NULL){
        return;
    }
    
    mymap[d].push_back(A->val);
    diagonalTraverse(A->left,mymap,d+1);
    diagonalTraverse(A->right,mymap,d);
}
vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> res;
    if(A == NULL){
        return res;
    }
    
    map<int,vector<int>> mymap;
    
    diagonalTraverse(A,mymap,0);
    
    vector<int> temp;
    for(auto x : mymap){
        temp = x.second;
        for(int i = 0; i < temp.size(); i++)
            res.push_back(temp[i]);
    }
    return res;
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
vector<int> Solution::solve(TreeNode* A) {
    deque<TreeNode*> dq;
    dq.push_front(A);
    vector<int> res;
    
    while(!dq.empty()){
        TreeNode* curr = dq.front();
        dq.pop_front();
        res.push_back(curr -> val);
        if(curr -> right) dq.push_front(curr -> right);
        if(curr -> left) dq.push_back(curr -> left);
    }
    return res;
}
