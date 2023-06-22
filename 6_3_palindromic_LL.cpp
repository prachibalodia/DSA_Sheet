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
    // ListNode* reverse(ListNode* head){
    //     if(head == NULL || head->next == NULL){
    //         return head;
    //     }
    //     ListNode* newHead= reverse(head->next);
    //     head->next->next=head;
    //     head->next=NULL;
    //     return newHead;
    // }
    ListNode* reverse(ListNode* head){
        ListNode*prev= NULL, *nextptr= NULL;
        while(head != NULL){
            nextptr= head->next;
            head->next= prev;
            prev= head;
            head= nextptr;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //brute force->T= O(N), S= O(N)
        // vector<int> v;
        // while(head!=NULL){
        //     v.push_back(head->val);
        //     head= head->next;
        // }
        // for(int i=0;i<v.size()/2;i++){
        //     if(v[i] != v[v.size()-1-i]){
        //         return false;
        //         break;
        //     }
        // }
        // return true;

        //optimal->T= O(n/2)+O(n/2)+O(n/2), S= O(1)
        //by first finding the middle of the LL
        //then reversing the second half of the LL
        //now comparing the nodes from the start node and next of the middle node
        
        if(!head || !head->next) return true;
        //finding middle
        ListNode* slow= head, *fast= head;
        while(fast-> next && fast->next->next){
            slow= slow->next;
            fast=fast->next->next;
        }
        //reversing the node next of the middle node
        slow->next= reverse(slow->next);
        slow= slow->next;

        while(slow){
            if(head->val != slow->val)return false;
            slow= slow->next;
            head=head->next;
        }
        return true;
    }
};