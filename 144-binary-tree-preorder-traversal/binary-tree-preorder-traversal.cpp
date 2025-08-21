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
//     void preOrderTrav(TreeNode* root,vector<int>&preorder){
//         if(root == NULL){
//             return;
//         }
//         //ek case khud solve kardo
//         preorder.push_back(root->val);
//         preOrderTrav(root->left,preorder);
//         preOrderTrav(root->right,preorder);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>preorder;
//         preOrderTrav(root,preorder);
//         return preorder;
//     }
// };

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        vector<int>ans;
        if(root==NULL) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode* currNode = st.top();
            st.pop();
            ans.push_back(currNode->val);
            if(currNode->right) st.push(currNode->right);
            if(currNode->left) st.push(currNode->left);
        }
        return ans;
    }
};