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
    void checkTree(TreeNode* p, TreeNode* q,bool& ans){
        if(!p && !q) return;
        if((p == NULL && q != NULL) ||(q == NULL && p != NULL) ||p->val != q->val){
        ans = false; 
        return;
        }
        
        //ek case khud solve kardo 
        checkTree(p->left,q->left,ans);
        checkTree(p->right,q->right,ans);


    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        checkTree(p,q,ans);
        return ans;
    }
};