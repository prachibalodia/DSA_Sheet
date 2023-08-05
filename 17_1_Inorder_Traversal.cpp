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

    void help(TreeNode* root, vector<int>&v){
        //Inorder-> LNR-> Left Node Right
        if(root == NULL)return;

        help(root->left, v);
        v.push_back(root->val);
        help(root->right,v);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //T= O(N), S=O(N)
        vector<int>v;
        help(root, v);
        return v;
    }
};