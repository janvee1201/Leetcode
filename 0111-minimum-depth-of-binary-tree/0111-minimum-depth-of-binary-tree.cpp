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
int dfs(TreeNode*root){
    if(!root) return 0;
    
            int l = dfs(root->left);
            int r= dfs(root->right);
           if(root->left==nullptr)
           return 1+r;
           if(root->right==nullptr)
           return 1+l;
           
        
         return 1+min(l,r);
}
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};