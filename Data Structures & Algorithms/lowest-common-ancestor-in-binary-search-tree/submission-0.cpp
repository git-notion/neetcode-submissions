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
    vector<int>pp,qq;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
private:
    TreeNode* dfs(TreeNode* root, TreeNode* p,TreeNode* q){
        if(root==nullptr) return NULL;

        if(root->val>max(p->val,q->val)){
            return dfs(root->left,p,q);
        }else if(root->val<min(p->val,q->val)){
            return dfs(root->right,p,q);
        }
        return root;
    }
};
