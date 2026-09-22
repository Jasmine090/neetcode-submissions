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
        string s = "";
        string ss = "";
        tree2str(root, s);
        tree2str(subRoot, ss);
        cout << "s:" << s << endl;
        cout << "ss:"  << ss << endl;
        if(s.find(ss)!=string::npos) return true;
        
        return false;
    }
    string tree2str(TreeNode* root, string &s){
        if(!root){
            s += ",&";
            return s;
        }
        s += ",";
        s += to_string(root->val);
        tree2str(root->left, s);
        tree2str(root->right, s);
        return s;
    }
};
