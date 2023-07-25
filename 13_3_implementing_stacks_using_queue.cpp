class MyStack {
    queue<int> q1, q2;

    queue<int>q;
public:
    MyStack() {
        //brute force-> using two queues-> T= O(N), S=O(2N)
        //pseudocode
        //push in q2
        //transfer element by element from q1
        //swap q1 and q2
        //no we have our elements in q1

        //optimal-> T= O(N), S= O(N)
        //using a single queue
        //pseudocode
        //push in q-> now iterate till <size-1 -> and push the front element again and pop it from the start
    }
    
    void push(int x) {

      //brute force
      // q2.push(x);
      // while(!q1.empty()){
      //   q2.push(q1.front());
      //   q1.pop();
      // }
      // swap(q1,q2);

      //optimal
      q.push(x);
      int n= q.size();
      for(int i=0;i<n-1;i++){
        q.push(q.front());
        q.pop();
      }
    }
    
    int pop() {
      // int t= q1.front();
      // q1.pop();
      // return t;

      //optimal
      int t= q.front();
      q.pop();
      return t;
    }
    
    int top() {
      // return q1.front();
      
      //optimal
      return q.front();

    }
    
    bool empty() {
      // return q1.empty();

      //optimal
      return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */