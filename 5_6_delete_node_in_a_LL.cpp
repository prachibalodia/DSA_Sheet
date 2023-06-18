/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //since it is mentioned that the node wont be
        //a tail node
        //in case the given node can be a tail node, we can put up the below
        if(node->next == NULL){
            node->val = NULL;
        }
        else{
        node->val = node->next->val;
        node->next= node->next->next;
        }
         
        
    }
};