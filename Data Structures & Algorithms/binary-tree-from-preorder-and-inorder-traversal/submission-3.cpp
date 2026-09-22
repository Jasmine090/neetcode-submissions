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
    int InMap[2001];
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            InMap[inorder[i]+1000] = i;
        }
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd,
                    int inStart, int inEnd){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode* re = new TreeNode(preorder[preStart]);
        int root_idx = InMap[preorder[preStart]+1000];
        int left_size = root_idx - inStart;
        int right_size = inEnd - root_idx;
        re->left = build(preorder, inorder,
                         preStart+1, preStart+left_size,
                         inStart, inStart+left_size-1);
        re->right = build(preorder, inorder,
                         preStart+1+left_size, preEnd,
                         inStart+1+left_size, inEnd);
        return re;

    }
};
