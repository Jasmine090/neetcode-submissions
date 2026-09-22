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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
    bool isValid(TreeNode* root, long long mn, long long mx) {
        if(root==nullptr) return true;
        if(!isValid(root->left, mn, root->val)) return false;
        if(!isValid(root->right, root->val, mx)) return false;
        // if(root->left && root->val <= root->left->val)
        //     return false;
        // if(root->right && root->val >= root->right->val)
        //     return false;
        if((root->val < mx) && (root->val > mn)) return true;
        else return false;

    }
};
