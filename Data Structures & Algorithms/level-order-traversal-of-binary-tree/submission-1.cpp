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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> re;
        if(!root) return re;
        re.push_back({});
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int cur = 0;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(!tmp){
                if(q.empty()) break;
                re.push_back({});
                cur++;
                q.push(nullptr);
                continue;
            }
            re[cur].push_back(tmp->val);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            
        }
        return re;
    }
};
