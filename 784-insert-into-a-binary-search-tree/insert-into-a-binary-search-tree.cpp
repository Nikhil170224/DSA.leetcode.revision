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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* temp = root;
        if(root == NULL){
          return newNode;
        }
        while(temp != NULL){
            if(temp->val < val){
                if(temp->right == NULL){
                    temp->right = newNode;
                    return root;
                }
                else{
                 temp = temp->right;
                }
            }
            else{
                if(temp->left == NULL){
                    temp->left = newNode;
                    return root;
                }
                else{
                    temp = temp->left;
                }
            }
        }
        return root;
    }
};