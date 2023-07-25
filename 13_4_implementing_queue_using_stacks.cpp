// class MyQueue {
// public:
//     stack<int> s1,s2;
//     MyQueue() {
//         //brute force-> using two stacks-> T= O(N), S= O(2N)
//         //pseudo code
//         //first transfer element by element from s1 to s2
//         //push x in s2 
//         //transfer element by element from s2 to s1
//     }
    
//     void push(int x) {
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s2.push(x);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
    
//     int pop() {
//         int p= s1.top();
//         s1.pop();
//         return p;
//     }
    
//     int peek() {
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };
class MyQueue {
public:
    stack<int> ip,op;
    MyQueue() {
        //optimal-> using two stacks, but with lesser complexity-> 
        //T= O(1)-> push= O(1), pop and top= O(1)-amortised, S= O(2N)
        //pseudo code
        //for push operation-> push everything into ip stack
        //for pop, check if op is empty-> if yes-> then transfer everything from ip to op element by element
        //now pop and top operations will work on op stack
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
        if(op.empty()){
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
        }
        int t= op.top();
        op.pop();
        return t;
    }
    
    int peek() {
        if(op.empty()){
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
        }
        int t= op.top();
        return t;
    }
    
    bool empty() {
        return (ip.empty() && op.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */