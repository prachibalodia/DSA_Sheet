/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //brute force-> T= O(N)+O(N), S= O(N)

        // Node* temp= head;
        // map<Node*, Node*>m;
        // while(temp != NULL){
        //     Node* newNode= new Node(temp->val);
        //     m[temp]= newNode;
        //     temp= temp->next;
        // }

        // temp = head;
        // while(temp != NULL){
        //     Node * node= m[temp];
        //     node->next= (temp->next==NULL)? NULL:m[temp->next];
        //     node->random= (temp->random==NULL)? NULL:m[temp->random];
        //     temp= temp->next;
        // }

        // return m[head];

        //optimal->T= O(N)+O(N)+O(N), S= O(1)
        Node* temp = head;
        //step 1-> creating the new deep copy nodes
        while(temp != NULL){
            Node* newNode= new Node(temp->val);
            newNode->next= temp->next;
            temp->next= newNode;
            temp=temp->next->next;
        }

        //step 2-> pointing the random pointer of the deep copy nodes
        Node* itr= head;
        while(itr != NULL){
            if(itr->random != NULL){
                itr->next->random= itr->random->next;
            }
            itr= itr->next->next;
        }

        //step 3-> pointing the next pointer of the deep copy nodes
        itr= head;
        Node* dummy = new Node(0);
        temp=dummy;
        Node*fast;
        while(itr != NULL){
            fast= itr->next->next;
            temp->next= itr->next;
            itr->next= fast;
            itr= fast;
            temp=temp->next;
        }
        return dummy->next;
    }
};