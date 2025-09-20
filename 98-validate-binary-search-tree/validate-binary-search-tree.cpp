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
    bool checkBST(TreeNode* root,long long minval,long long maxval){
        if(root == NULL) return true;
        if(root->val <= minval || root->val >= maxval) return false;

        //if left is invalid return false without going to right subtree
        if(!checkBST(root->left,minval,root->val))
        return false;

        if(!checkBST(root->right,root->val,maxval))
        return false;

        return true;

        // //recursive calls
        // // left RC
        // // maxval = min(maxval,root->val);
        // bool left = checkBST(root->left,minval,min(maxval,root->val));

        // //right RC
        // // minval = max(minval,root->val);
        // bool right = checkBST(root->right,max(minval,root->val),maxval);

        // return left && right;
        
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root,LLONG_MIN,LLONG_MAX);
    }
};

