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
    void createBST(vector<int>& preorder,int& i,int n,TreeNode* root,int min,int max){
       if(i>=n) return;
       int rootVal = root->val;
       if(preorder[i] <= min ||  preorder[i] >= max) return;

       // root->val must be in range of min and max
       if(preorder[i] < rootVal){
       root->left = new TreeNode(preorder[i++]);
       createBST(preorder,i,n,root->left,min,rootVal); 
       }
       if(i>=n) return;
       if(preorder[i] <= min || preorder[i] >= max) return;
       root->right = new TreeNode(preorder[i++]);
       createBST(preorder,i,n,root->right,rootVal,max);

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int i = 1;
        TreeNode* root = new TreeNode(preorder[0]);
        createBST(preorder,i,n,root,0,1001);
        return root;
    }
};