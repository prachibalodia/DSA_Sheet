class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //Morris Traversal Method-> T= O(N)->armortized, S= O(1)
        //PreOrder Traversal -> Node Left Right
        //The idea here is to traverse the tree iteratively and not recursively, and also keeping a track of the root nodes, in order to backtrack

        //1. Check if left node is NULL, if yes, print curr and move towards the right subtree
        //2. Else, find the rightmost node of the left subtree and store its next as the curr(to backtrack)
        TreeNode* curr= root;
        vector<int>v;        

        while(curr != NULL){
            if(curr->left == NULL){
                v.push_back(curr->val);
                curr= curr->right;
            }

            else{
                TreeNode* prev= curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev= prev->right;
                }

                if(prev->right == NULL){ //if thread not marked
                    prev->right= curr;
                    v.push_back(curr->val);
                    curr= curr->left;
                }

                else{ //if thread already marked then break the thread
                    prev->right= NULL;
                    curr= curr->right;
                }
            }
        }
        return v;
    }
};