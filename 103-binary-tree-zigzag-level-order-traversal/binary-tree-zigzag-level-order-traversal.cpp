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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>ans(size); 
            for(int i = flag ? 0 : size-1; flag ? i < size : i >= 0;
             flag ? i++ : i--){
                TreeNode* curr = q.front();
                q.pop();
                ans[i] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            flag = !flag;
            res.push_back(ans);
        }
        return res;
    }
};