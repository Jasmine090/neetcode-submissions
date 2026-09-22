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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k).second;
    }
    pair<int, int> inorder(TreeNode* node, int k){
        int ct = 0;
        if(node==nullptr) return {0, -1};
        //visit left tree
        pair<int, int> left;
        if(node->left){
            left = inorder(node->left, k);
            if(left.second>=0) return left;
            ct += left.first;
        }
        //cout << node->val << " " << ct << endl;
        //visit this node
        ct++;
        if(ct==k) return {ct, node->val};
        //visit right tree
        pair<int, int> right;
        if(node->right){
            right = inorder(node->right, k-ct);
            if(right.second>=0) return right;
            ct += right.first;
        }
        return {ct, -2};
    }
};
