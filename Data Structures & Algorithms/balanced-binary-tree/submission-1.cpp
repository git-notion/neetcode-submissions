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
    bool ans=true;
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        dfs(root);
        if(ans){
            return true;
        }else{
            return false;
        }
    }
private:
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(abs(l-r)>1) ans=false;
        return 1+max(l,r);
    }
};
