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
//  class Solution {
// public:
//     void checkSymmetric(TreeNode* lr, TreeNode* rr, bool& ans){
//         if(!ans) return;
//         if(lr == NULL && rr == NULL) return; 
//         if(lr == NULL  || rr == NULL){
//             ans = false;
//             return;
//         }
//         if(lr->val != rr->val){
//             ans = false;
//             return;
//         }
        
//         checkSymmetric(lr->left,rr->right,ans);
//         checkSymmetric(lr->right,rr->left,ans);

//     }
//     bool isSymmetric(TreeNode* root) {
//         bool ans = true;
//         checkSymmetric(root->left,root->right,ans);
//         return ans;
//     }
// };
class Solution {
public:
    bool helper(TreeNode* lr, TreeNode* rr){
        if(!lr && !rr) return true;
        if(!lr || !rr) return false;
        if(lr->val != rr->val) return false;

        bool h1 = helper(lr->left,rr->right);
        bool h2 = helper(lr->right,rr->left);

        return h1 && h2;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};