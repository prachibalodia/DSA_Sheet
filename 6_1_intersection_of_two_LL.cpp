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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //brute force-> T= O(m*n), S= O(1)
        //iterating through all the nodes of one ll and then comparing it w each node of the other ll
        // while(headB!= NULL){
        //     ListNode* temp= headA;
        //     while(temp != NULL){
        //         if(temp == headB)return headB;
        //         temp= temp->next;
        //     }
        //     headB= headB->next;
        // }
        // return NULL;

        //better-> O(n+m), S= O(n) or O(m)
        //using sets to store the nodes and checking in the 2nd LL
        // set<ListNode*>s;
        // while(headA != NULL){
        //     s.insert(headA);
        //     headA= headA->next;
        // }
        // while(headB){
        //     if(s.find(headB) != s.end()) return headB;
        //     headB= headB->next;
        // }
        // return NULL;

        //optimal-> T=(2*max(l1,l2)),S=O(1)
        //using an algorithm where two dummy nodes traverse both the LL
        //uses concept of difference in lengths of two LL

        ListNode* d1= headA, *d2=headB;
        while(d1 != d2){
            d1= (d1==NULL)? headB:d1->next;
            d2= (d2==NULL)? headA:d2->next;
        }
        return d1;
    }
};