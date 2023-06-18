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
    ListNode* middleNode(ListNode* head) {
        //brute force-> T= O(n), S= O(n)
        //using a vector to store all the nodes, and the returning the mid
        // vector<ListNode*> v;
        // while(head != NULL){
        //     v.push_back(head);
        //     head= head->next;
        // }
        // int n= v.size();
        // int mid= (n-1)/2;
        // if((n-1)%2 != 0){
        //     mid= mid+1;
        // }
        // ListNode* ans;
        // ans= v[mid];
        // return ans;

        //better-> T= O(n)+O(n/2), S= O(1)
        //traversing to the end of the ll to compute n
        //now compute n/2 and return
        // ListNode* temp= head;
        // int n=0;
        // while(temp != NULL){
        //     n++;
        //     temp= temp->next;
        // }
        // temp= head;
        // for(int i=0;i<n/2;i++){
        //     temp= temp->next;
        // }
        // return temp;

        //optimal-> T= O(n/2), S= O(1)
        //tortoise method-> maintaining a slow and a fast pointer
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast != NULL && fast-> next!= NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};