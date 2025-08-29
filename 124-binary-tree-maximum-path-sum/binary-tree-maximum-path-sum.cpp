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
    int findPathSum(TreeNode* root, int& pathSum){
        //Base Case
        if(!root) return 0;

        //ek case khud solve kardo
        int leftSum = max(0,findPathSum(root->left,pathSum));
        int rightSum = max(0,findPathSum(root->right,pathSum));
        pathSum = max(pathSum,(leftSum+rightSum+root->val));

        return max(leftSum,rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        findPathSum(root,pathSum);
        return pathSum;
    }
};