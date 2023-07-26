class LRUCache {
    //T= O(1), S=O(N)-> for map
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key =k;
            val=v;
        }
    };

    int cap;
    unordered_map<int,Node*>m;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    LRUCache(int capacity) {
        cap= capacity;  
        head->next= tail;
        tail->prev= head;  
    }
    
    void addNode(Node* n){
        Node* temp= head->next;
        n->next= temp;
        n->prev= head;

        head->next= n;
        temp->prev= n;
    }

    void deleteNode(Node* nod){
        Node*p= nod->prev;
        Node*n= nod->next;

        p->next= n;
        n->prev= p;
    }

    int get(int key) {
        //to get any key, is making that particular key the most recently used(obv if the key exists)
        if(m.find(key) != m.end()){
            Node* resNode= m[key];
            int resVal= resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key]= head-> next;
            return resVal;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //to put any pair, we check two things:
        //1) if capacity is reached-> then we delete the least recently used pair
        //2) if already present-> then we delete it, and put it again we a new address
        if(m.find(key) != m.end()){
            Node* existing= m[key];
            m.erase(key);
            deleteNode(existing);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
       
        addNode(new Node(key, value));
        m[key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */