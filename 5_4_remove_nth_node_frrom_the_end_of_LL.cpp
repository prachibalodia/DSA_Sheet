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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //brute force-> T= O(N)+O(N), S= O(1)
        // ListNode* temp= head;
        // int l=0;
        // while(temp != NULL){
        //     l++;
        //     temp= temp->next;
        // }
        // if(l==0) return NULL;
        // if(l==n) return head->next;
        // int end= l-n;
        // l=0;
        // temp=head;
        // while(temp != NULL){
        //     l++;
        //     if(l== end){
        //         temp->next= temp->next->next;
        //     }
        //     temp= temp->next;
        // }
        // return head;
        
        //optimal-> O(N)
        //using two pointer method-> slow and fast pointer

        ListNode* start=new ListNode();
        start->next= head;
        ListNode* slow= start, *fast=start;
        for(int i=1;i<=n;i++){
            fast= fast->next;
        }
        while(fast->next != NULL){
            slow= slow->next;
            fast= fast->next;
        }
        slow->next= slow->next->next;
        return start->next;
    }
};