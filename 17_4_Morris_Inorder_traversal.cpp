class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //Morris Traversal-> T=O(N), S= O(1)
        //The idea is based on two intuitions:
        //1. if the left subtree is NULL, print the root and move to root->right
        //2. if the left subtree exists, create a thread bw the root and rightmost node of the left subtree, so that we can backtrack
        //3. the idea is that in recursion we can easily backtrack using backtracking, but here iteratively, we need to create the threads

        TreeNode* curr= root;
        vector<int>v;
        while(curr != NULL){
            if(curr->left == NULL){ //left part of the tree doesnt exist
                v.push_back(curr->val);
                curr= curr->right;
            }

            else{ //left subtree exists
                TreeNode* prev= curr->left;
                while(prev-> right && prev->right != curr){
                    prev= prev->right;
                }

                if(prev->right == NULL){ //we reach at the rightmost leaf node, creating the thread
                    prev->right= curr;
                    curr= curr->left;
                }

                else{ //the right most leaf node already points to the curr, so we need to break the thread
                    prev->right= NULL;
                    v.push_back(curr->val);
                    curr= curr->right;
                }
            }
        }
        return v;
    }
};