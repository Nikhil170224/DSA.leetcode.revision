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
// class Solution {
// public:
//         void postOrderTraversal(TreeNode* root,vector<int>&postorder){
//         if(root == NULL){
//             return;
//         }
//         //ek case khud solve kardo
//         postOrderTraversal(root->left,postorder);
//         postOrderTraversal(root->right,postorder);
//         postorder.push_back(root->val);
//         }
//         vector<int> postorderTraversal(TreeNode* root) {
//             vector<int>postorder;
//             postOrderTraversal(root,postorder);
//             return postorder;
//         }
// };

// ITERATIVE SOLUTION :
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        while(!st2.empty()){
            TreeNode* curr = st2.top();
            res.push_back(curr->val);
            st2.pop();
        }
        return res;
    }
};