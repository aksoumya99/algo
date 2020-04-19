/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // FROM TUSHAR ROY VIDEO
vector<int> Solution::inorderTraversal(TreeNode* root) 
{
    stack<TreeNode* > stk;
    vector<int > va;
    TreeNode *curr=root;
    while(1){
        if(curr!=NULL){
            stk.push(curr);
            curr=curr->left;
        }
        else{
            if(stk.empty()){
                break;
            }
            curr=stk.top();
            stk.pop();
            va.push_back(curr->val);
            curr=curr->right;
        }
    }
    return va;
}
