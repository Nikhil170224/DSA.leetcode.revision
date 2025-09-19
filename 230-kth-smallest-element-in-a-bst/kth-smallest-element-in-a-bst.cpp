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
    void findkSmallest(vector<int>&ans,TreeNode* root,int k){
        if(k == 0 || root == NULL) return;

        findkSmallest(ans,root->left,k);
        ans.push_back(root->val);
        k--;
        findkSmallest(ans,root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        findkSmallest(ans,root,k);
        return ans[k-1];
    }
};