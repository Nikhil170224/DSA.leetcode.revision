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
    void inOrderTrav(TreeNode* root,vector<int>&inorder){
        if(root == NULL){
            return;
        }
        //ek case khud solve kardo
        inOrderTrav(root->left,inorder);
        inorder.push_back(root->val);
        inOrderTrav(root->right,inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        inOrderTrav(root,inorder);
        return inorder;
    }
};