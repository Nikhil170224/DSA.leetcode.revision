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
//     int findHt(TreeNode* root){
//         if(!root) return 0;

//         int lh = findHt(root->left);
//         int rh = findHt(root->right);
//         return max(lh,rh) +1;
//     }
//     void findDiameter(TreeNode* root,int& diameter){
//         //Base case
//         if(!root) return;

//         //ek case khud solve kardo
//         int lh = findHt(root->left);
//         int rh = findHt(root->right);

//         diameter = max(diameter,lh + rh);
//         findDiameter(root->left,diameter);
//         findDiameter(root->right,diameter);
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         findDiameter(root,diameter);
//         return diameter;
//     }
// };
//OPTIMISED T.C = O(N) S.C = O(N)
class Solution {
public:
    int dia;
    int findDia(TreeNode* root){
        if(!root) return 0;

        int lh = findDia(root->left);
        int rh = findDia(root->right);
        dia = max(dia,rh+lh);
        return max(rh,lh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        findDia(root);
        return dia;
    }
};