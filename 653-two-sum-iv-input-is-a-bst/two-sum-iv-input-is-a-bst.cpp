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
    void inOrder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inOrder(root,inorder);
        // we got all elements in an increasing sorted order
        int s = 0, e = inorder.size()-1;
        while(s<e){
            int sum = inorder[s] + inorder[e];
            if(sum == k) return true;
            if(sum < k) s++;
            else e--;
        }
        return false;
    }
};