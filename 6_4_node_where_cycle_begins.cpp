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
    ListNode *detectCycle(ListNode *head) {
        //brute force->T= O(N), S= O(N)
        // unordered_set<ListNode*> s;
        // ListNode* curr= head;
        // while(curr != NULL){
        //     if(s.find(curr) != s.end()){
        //         return curr;
        //     }
        //     else{
        //         s.insert(curr);
        //         curr= curr-> next;
        //     }
        // }
        // return NULL;

        //optimal->T= O(N), S=O(1)
        if(!head || !head->next)return NULL;
        ListNode*s= head, *f= head, *entry=head;
        while(f->next && f->next->next){
            s= s->next;
            f=f->next->next;
            if(s==f) {
                while(entry != s){
                    s=s->next;
                    entry=entry->next;
                }
                return s;
            }
        }
        return NULL;
    }
};