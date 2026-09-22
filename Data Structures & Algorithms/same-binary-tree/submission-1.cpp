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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pp;
        pp.push(p);
        queue<TreeNode*> qq;
        qq.push(q);
        while(!pp.empty() || !qq.empty()){
            TreeNode* pn = pp.front();
            pp.pop();
            TreeNode* qn = qq.front();
            qq.pop();
            if(pn==NULL ^ qn==NULL) return false;
            if(pn==NULL) continue;
            if(pn->val != qn->val) return false;
            pp.push(pn->left);
            pp.push(pn->right);
            qq.push(qn->left);
            qq.push(qn->right);
        }
        return true;
    }
};
