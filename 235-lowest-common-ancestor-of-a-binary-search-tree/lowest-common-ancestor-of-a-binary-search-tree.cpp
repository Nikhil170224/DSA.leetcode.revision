/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) return NULL;
       int rootVal = root->val;
       if(p->val > rootVal && q->val > rootVal)
       return lowestCommonAncestor(root->right,p,q);
       if(p->val < rootVal && q->val < rootVal)
       return lowestCommonAncestor(root->left,p,q);
       return root; 
    }
};

// there are three cases possible :
// 1. p,q both are greater than root
// 2. p,q both are less than root
// 3. p,q are inorder with root
// we will traverse the BST and if we get a root inorder then we gona store the root as lca, else we move to right or left subtree
// class Solution {
// public:
//     void findLCA(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& lca){
//         // Now here p is less than q
//         if(root==NULL) return;
//         if(p->val <= root->val && q->val >= root->val){
//             lca = root;
//             return;
//         }
//         else{
//             if(q->val < root->val && p->val < root->val) 
//             root = root->left;
//             else root = root->right;
//             findLCA(root,p,q,lca);
//         }
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         TreeNode* lca = NULL;
//         TreeNode* a = (p->val < q->val) ? p : q;
//         TreeNode* b = (q->val > p->val) ? q : p;
//         findLCA(root,a,b,lca);
//         return lca;
//     }
// };