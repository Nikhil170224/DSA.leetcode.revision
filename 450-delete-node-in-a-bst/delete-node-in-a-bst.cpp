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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        else if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
                
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastChild = findLastNode(root->left);
        lastChild->right = rightChild;
        return root->left;
    }
    TreeNode* findLastNode(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findLastNode(root->right);
    }
};


// class Solution {
// public:
//     void helper(TreeNode* root, int key){
//         // step 1. search the required node
//         TreeNode* temp1 = root;
//         if(root->val < key) root = root->right;
//         else root = root->left;
//         while(root != NULL){
//             if(root->val == key){
//                 TreeNode* lnode = root->left;
//                 TreeNode* rnode = root->right;
//                 if(lnode == NULL && rnode == NULL){
//                     delete(root);
//                     return;
//                 }
//                 if(temp1->left->val == root->val){
//                     delete(root);
//                     temp1->left = lnode;
//                     temp1 = lnode;
//                     while(temp1->right != NULL){
//                         temp1 = temp1->right;
//                     }
//                     temp1->right = rnode;
//                 }
//                 else{
//                     delete(root);
//                     temp1->right = rnode;
//                     temp1 = rnode;
//                     while(temp1->left != NULL){
//                         temp1 = temp1->left;
//                     }
//                     temp1->left = lnode;
//                 }
//                 return;
//             } // key found
//             else if(root->val < key){
//                 temp1 = root;
//                 root = root->right;
//             } 
//             else{
//                 temp1 = root;
//                 root = root->left;
//             }
//         }
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) return NULL;
//         if(root->val != key && root->left == NULL && root->right == NULL) return root;
//         if(root->left == NULL && root->right == NULL) return NULL;
//          if(root->val == key){
//             TreeNode* rnode = root->right;
//             TreeNode* temp1 = root->left;
//             TreeNode* newRoot = temp1;
//             delete(root);
//             while(temp1->right != NULL){
//                 temp1 = temp1->right;
//             }
//             temp1->right = rnode;
//             return newRoot;
//         }
//         helper(root,key);
//         return root;
//     }
// };