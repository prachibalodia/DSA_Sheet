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
            //Postorder-> LRN-> Left, Right , Node
            if(root == NULL) return;

            help(root->left,v);
            help(root->right,v);
            v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        //T= O(N), S=O(N)
        vector<int>v;
        help(root,v);
        return v;
    }
};