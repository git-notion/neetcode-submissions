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
    int ans;
    int maxPathSum(TreeNode* root) {
        ans=root->val;
        dfs(root);
        return ans;
    }
private:
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int leftMax=dfs(root->left);
        int rightMax=dfs(root->right);
        leftMax=max(leftMax,0);
        rightMax=max(rightMax,0);

        ans=max(ans,root->val+leftMax+rightMax);

        return (root->val+max(leftMax,rightMax));

    }
};
