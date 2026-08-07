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
    int preI=0,inI=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,INT_MAX);
    }
private:
    TreeNode* dfs(vector<int>&preorder,vector<int>&inorder,int limit){
        if(preI>=preorder.size()) return nullptr;
        if(inorder[inI]==limit){
            inI++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preI++]);
        root->left=dfs(preorder,inorder,root->val);
        root->right=dfs(preorder,inorder,limit);
        return root;
    }
};
