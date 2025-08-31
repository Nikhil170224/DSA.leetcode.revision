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
//     void helper(TreeNode* root,int targetSum,bool& ans){
//         if(!root) return;
//         if(root->left== NULL && root->right==NULL){
//           if(ans == false){
//             ans = (targetSum-root->val == 0) ? true : false;
//           }
//           return;
//         }
//         helper(root->left,targetSum-(root->val),ans);
//         helper(root->right,targetSum-(root->val),ans);
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         bool ans = false;
//         helper(root,targetSum,ans);
//         return ans;
//     }
// };

// ✅ Improvements:

// Removed the extra helper function and bool& ans.

// Used direct recursion with return values instead of reference flag tracking.

// Clear base case handling for leaf nodes.

// Shorter and more readable.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf node, check if the path sum equals target
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recursively check left and right subtrees
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};