/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root,vector<TreeNode*>& inorder,vector<int>&v){
        if(root==NULL) return;

        inOrder(root->left,inorder,v);
        inorder.push_back(root);
        v.push_back(root->val);
        inOrder(root->right,inorder,v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inorder;
        vector<int>correctOrder;
        inOrder(root,inorder,correctOrder);
        sort(correctOrder.begin(),correctOrder.end());
        int n = inorder.size();
        TreeNode* temp1 = NULL;
        int flag = false;
        TreeNode* temp2 = NULL;

        for(int i = 0; i < n; i++){
            if(inorder[i]->val != correctOrder[i]){
                if(!flag){
                 temp1 = inorder[i];
                 flag = !flag;
                }
                else{
                    temp2 = inorder[i];
                    break;
                } 
            }
        }
        if(temp1 && temp2){
            int temp1Val = temp1->val;
            temp1->val = temp2->val;
            temp2->val = temp1Val;
        }
    }
};


// class Solution {
// public:
//     void helper(TreeNode* root,TreeNode* mini,TreeNode* maxi){
//         if(root == NULL) return;
//         int rootVal = root->val;
//         if(rootVal < mini->val ){
//             // the mini and root are swaped
//             root->val = mini->val;
//             mini->val = rootVal;
//             return;
//         }
//         else if(rootVal > maxi->val){
//             root->val = maxi->val;
//             maxi->val = rootVal;
//             return;
//         }

//         helper(root->left,mini,root);
//         helper(root->right,root,maxi);
//     }
//     void recoverTree(TreeNode* root) {
//         TreeNode* mini = new TreeNode(INT_MIN);
//         TreeNode* maxi = new TreeNode(INT_MAX);
//         helper(root,mini,maxi);
//     }
// };