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
vector<int> Solution::solve(TreeNode* A, int B) {
    
    queue<pair<int,pair<TreeNode*,TreeNode*>>> q;
    
    unordered_map<int,pair<TreeNode*,int>> mymap;
    
    q.push({0,{A,NULL}});
    
    while(!q.empty()){
        
        int currd = q.front().first;
        TreeNode* par = q.front().second.second;
        TreeNode* curr = q.front().second.first;
        
        mymap[curr->val] = {par,currd};
        
        q.pop();
        
        if(curr -> left != NULL){
            q.push({currd+1,{curr->left,curr}});
        }
        
        if(curr ->right != NULL){
            q.push({currd+1,{curr->right,curr}});
        }
    }
    
    int reqd = mymap[B].second;
    TreeNode* reqpar = mymap[B].first;
    
    unordered_map<int,pair<TreeNode*,int>> :: iterator it;
    
    vector<int> res;
    
    for(it = mymap.begin(); it != mymap.end(); it++){
        
        if(it->first == B){
            continue;
        }
        
        if(it->second.second == reqd && it->second.first != reqpar){
            res.push_back(it->first);
        }
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
vector<int> Solution::solve(TreeNode* A, int B) {

    queue<pair<int,pair<TreeNode*,TreeNode*>>> q;

    unordered_map<int,vector<pair<TreeNode*,int>>> myumap;

    q.push({0,{A,NULL}});

    int reqd;
    TreeNode* reqpar;

    while(!q.empty()){

        int currd = q.front().first;
        TreeNode* curr = q.front().second.first;
        TreeNode* par = q.front().second.second;

        if(curr -> val == B){
            reqd = currd;
            reqpar = par;
        }

        myumap[currd].push_back({par,curr->val});

        q.pop();

        if(curr -> left != NULL){
            q.push({currd+1,{curr->left,curr}});
        }

        if(curr -> right != NULL){
            q.push({currd+1,{curr->right,curr}});
        }
    }

    vector<pair<TreeNode*,int>> v = myumap[reqd];

    vector<int> res;

    for(auto x: v){
        if(x.first != reqpar){
            res.push_back(x.second);
        }
    }
    return res;
}

//Method - 3
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {

    unordered_map<int,vector<pair<TreeNode*,TreeNode*>>> umap;

    queue<pair<TreeNode*,TreeNode*>> q;

    q.push({NULL,A});

    int level = 0;

    int reql;
    TreeNode* reqp;

    while(!q.empty()){

        int sz = q.size();
        while(sz--){

            TreeNode* par = q.front().first, *curr = q.front().second;
            q.pop();

            if(curr->val == B){
                reql = level;
                reqp = par;
            }
            umap[level].push_back({par,curr});

            if(curr -> left) q.push({curr,curr->left});
            if(curr -> right) q.push({curr,curr->right});
        }
        level++;
    }

    vector<pair<TreeNode*,TreeNode*>> v = umap[reql];

    vector<int> res;

    for(int i = 0; i < v.size(); i++){
        TreeNode* par = v[i].first;
        if(par != reqp){
            res.push_back(v[i].second -> val);
        }
    }

    return res;
}

//Method - 4
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPar(TreeNode* parent, TreeNode* A, int B, TreeNode* &par){
    if(A == NULL){
        return false;
    }
    if(A -> val == B){
        par = parent;
        return true;
    }
    bool flag = false;
    flag = findPar(A, A -> left, B, par);
    if(flag) return true;
    flag = findPar(A, A -> right, B, par);
    return flag;
}
vector<int> Solution::solve(TreeNode* A, int B) {
     
     TreeNode* par;
     findPar(NULL, A, B, par);

     queue<TreeNode*> q;
     q.push(A);

     while(!q.empty()){
         int sz = q.size();
         bool flag = false;
         while(sz--){
             TreeNode* curr = q.front();
             q.pop();
             if(curr == par){
                 flag = true;
                 continue;
             }
             if(curr -> left) q.push(curr -> left);
             if(curr -> right) q.push(curr -> right);
         }
         if(flag) break;
     }
     vector<int> cousins;
     int sz = q.size();
     while(sz--){
        TreeNode* curr = q.front();
        q.pop();
        cousins.push_back(curr -> val);
     }
     return cousins;
}

//Method - 5
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> res;
    if(A -> val == B){
        return res;
    }
    
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        int sz = q.size();
        bool flag = false;
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr -> left && curr -> left -> val == B || curr -> right && curr -> right -> val == B){
                flag = true;
            }
            else{
                if(curr -> left) res.push_back(curr -> left -> val);
                if(curr -> right) res.push_back(curr -> right -> val);
            }
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
        if(flag) break;
        res.clear();
    }
    return res;
}
