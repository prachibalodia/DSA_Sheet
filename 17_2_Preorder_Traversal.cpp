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
        //Preorder -> NLR-> Node Left Right
        if(root == NULL) return;

        v.push_back(root->val);
        help(root->left,v);
        help(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
    
    //T= O(N), S=O(N)
    vector<int>v;
    help(root, v);
    return v;
        
    //(OR)

    //     vector<int> v;
    //     stack<TreeNode*> st;
    //     if(root == NULL){
    //         return v;
    //     }
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* temp = st.top();
    //         v.push_back(temp->val);
    //         st.pop();
    //         if(temp->right != NULL){
    //             st.push(temp->right);
    //         }
    //         if(temp->left != NULL){
    //             st.push(temp->left);
    //         }

    //     }
    // return v;
    }
};