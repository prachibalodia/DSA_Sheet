/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //recursive-> T= O(N), S= O(1), apart from the stack space no other space is used
        // if(head== NULL || head->next == NULL){
        //     return head;
        // }
        // ListNode* newHead= reverseList(head->next);
        // head->next->next=head;
        // head->next= NULL;
        // return newHead;

        //iterative->T= O(N), S= O(1)
        ListNode* curr=head;
        ListNode* prev= NULL;
        ListNode* nextptr;
        while(curr != NULL){
            nextptr= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextptr;
        }
        return prev;
    }
};