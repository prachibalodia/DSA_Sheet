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
    bool hasCycle(ListNode *head) {
        //brute force-> T= O(n), S= O(n)
        // set<ListNode*>s;
        // ListNode*t=head;
        // while(t){
        //     if(s.find(t) == s.end()){
        //         s.insert(t);
        //         t= t->next;
        //     }
        //     else{
        //         return true;
        //         break;
        //     }
        // }
        // return false;

        //optimal-> T= O(n), S=O(1)
        //using the slow and the fast pointer approach
        if(head == NULL || head->next== NULL)return false;
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};