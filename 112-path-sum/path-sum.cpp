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
    void helper(TreeNode* root,int targetSum,bool& ans){
        if(!root) return;
        if(root->left== NULL && root->right==NULL){
          if(ans == false){
            ans = (targetSum-root->val == 0) ? true : false;
          }
          return;
        }
        helper(root->left,targetSum-(root->val),ans);
        helper(root->right,targetSum-(root->val),ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        helper(root,targetSum,ans);
        return ans;
    }
};