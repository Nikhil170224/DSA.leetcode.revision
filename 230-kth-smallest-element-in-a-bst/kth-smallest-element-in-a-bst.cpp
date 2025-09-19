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
    void findkSmallest(int& ans,TreeNode* root,int& k){
        if(root == NULL) return;

        findkSmallest(ans,root->left,k);
        if(k > 0){
            k--;
            if(k == 0){
            ans = root->val;
            return;
          }
        }
        findkSmallest(ans,root->right,k);        
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>ans;
        int ans = -1;
        findkSmallest(ans,root,k);
        return ans;
    }
};