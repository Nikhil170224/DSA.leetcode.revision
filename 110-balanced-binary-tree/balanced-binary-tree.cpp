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
//     int findHt(TreeNode* root){
//         if(!root) return 0;

//         int lh = findHt(root->left);
//         int rh = findHt(root->right);

//         return max(lh,rh) + 1;
//     }
//     bool helper(TreeNode* root){
//         //base case
//       if(!root) return true;

//       int lh = findHt(root->left);
//       int rh = findHt(root->right);
//       if(abs(lh-rh) > 1) return false;

//       bool left = helper(root->left);
//       bool right = helper(root->right);

//       if(!left || !right) return false;
//       return true;

//     }
//     bool isBalanced(TreeNode* root) {
//         return helper(root); 
//     }
// };
// #OPTIMISED T.C. = O(N) AND S.C = O(N)
class Solution {
public:
    int findHt(TreeNode* root){
        //Base case
        if(!root) return 0;

        //ek case khud solve kardo
        int lh = findHt(root->left);
        if(lh == -1) return -1;
        int rh = findHt(root->right);
        if(rh == -1) return -1;

        if(abs(lh-rh) > 1) return -1;
        return max(lh,rh) +1;
    }
    bool isBalanced(TreeNode* root) {
        return findHt(root) != -1;
    }
};