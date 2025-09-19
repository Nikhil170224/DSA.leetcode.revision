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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){return;}
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
    vector<int>ans;
    inorder(root,ans);
    int k=ans.size();
    for(int i=1;i<k;i++){
        if(ans[i]<=ans[i-1]){
            return false;
        }
    }
    return true;
    }
};

    // //Base case
    // if(root == NULL) return true;
    // // if(root->left != NULL && root->left->val >= root->val) return false;
    // // if(root->right != NULL && root->right->val <= root->val) return false;
    //   // ek case khud solve kardo
    //   bool ans1 = isValidBST(root->left);
    
    //   bool ans2 = isValidBST(root->right);

    //   return (ans1 && ans2);
