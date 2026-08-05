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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr||dfs(root,subRoot)) return true;
        if(root==nullptr){
            return false;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
private:
    bool dfs(TreeNode* p,TreeNode* q){
        if(p==nullptr&&q==nullptr){
            return true;
        }
        if(p&&q&&p->val==q->val){
            return (dfs(p->left,q->left)&&dfs(p->right,q->right));
        }
        return false;
    }
};
