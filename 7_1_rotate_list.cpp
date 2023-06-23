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
    ListNode* rotateRight(ListNode* head, int k) {
        //brute force->T= O(k*N), S= O(1)
        // if(head == NULL && head->next == NULL) return head;

        // for(int i=0;i<k;i++){
        //     ListNode* t= head;
        //     while(t->next!= NULL && t->next->next != NULL){
        //         t= t->next;
        //     }
        //     ListNode* end= t->next;
        //     t->next= NULL;
        //     end->next= head;
        //     head= end;
        // }
        // return head;

        //optimal->T= O(N), S=O(1)
        //compute the len
        //make it a circular ll by pointing the last node to head
        //k=k%len
        //end= len-k
        //traverse till end th node, and make the next as head,and then point its next to null
        if(!head || !head->next || k==0) return head;
        ListNode* t= head;
        int l=1;
        while(t->next != NULL){
            l++;
            t= t->next;
        }
        t->next= head;
        k= k%l;
        int end=l-k;
        while(end--){
            t=t->next;
        }
        head= t->next;
        t->next= NULL;
        return head;
    }
};