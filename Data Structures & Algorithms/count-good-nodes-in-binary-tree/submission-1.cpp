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

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int max_v){
        if(node==nullptr) return 0;
        int re = 0;
        if(node->val >= max_v){
            max_v = node->val;
            re++;
            //cout << node->val << endl;
        } 
        re += dfs(node->right, max_v);
        re += dfs(node->left, max_v);
        return re;
    }
};
