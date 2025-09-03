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
    void findPathSum(vector<vector<int>>&res,TreeNode* root,int targetSum,vector<int>path){
        if(!root) return;
        // if(targetSum < root->val) return;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val){
                //ans found
                path.push_back(root->val);
                res.push_back(path);
            }
            return;
        }
        // left call
        path.push_back(root->val);
        findPathSum(res,root->left,targetSum-root->val,path);

        // right call
        findPathSum(res,root->right,targetSum-root->val,path);        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> >res;
        vector<int>path;
        findPathSum(res,root,targetSum,path);
        return res;
    }
};