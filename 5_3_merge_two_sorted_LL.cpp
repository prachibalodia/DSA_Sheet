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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //brute force->T= O(N1+N2), s= O(N1+N2)
        //use an external list and then compare both the given lists
        //uses extra space
        //a dummy head with 0 value will be pointing to NULL
        //now two pointers h1 and h2 will compare values of l1 and l2
        //and whichever is smaller, dummy->next will point to it
        //at last dummy->next is returned

        //optimal-> O(N+M), s= O(1)
        //in place, just chaging the links of the nodes
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        
        if(l1->val > l2->val) swap(l1,l2);
        ListNode* ans=l1;
        while(l1 != NULL && l2 != NULL){
            ListNode* temp=NULL;
            while(l1 != NULL && l1->val <= l2->val){
                temp= l1;
                l1= l1->next;
            }
            temp->next= l2;
            swap(l1,l2);
        }
        return ans;

        //using recursion-> in place->T= O(N1+N2), S=O(1)

		//using recursion-> in place
        // if(l1==NULL) return l2;
        // if(l2 == NULL)return l1;

        // if(l1->val <= l2->val){
        //     l1->next= mergeTwoLists(l1->next,l2);
        //     return l1;
        // }
        // else{
        //     l2->next= mergeTwoLists(l1, l2->next);
        //     return l2;
        // }
    }
};