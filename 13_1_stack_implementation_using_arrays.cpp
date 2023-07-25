// Stack class.
class Stack {
    
public:
    int *arr;
    int t;
    int size;

    Stack(int capacity) {
        // Write your code here.
        arr= new int[capacity];
        size= capacity;
        t=-1;
    }

    void push(int num) {
        // Write your code here.
        if(t < size-1)
        arr[++t]= num;
    }

    int pop() {
        // Write your code here.
        if(t == -1) return -1;
        int el= arr[t];
        --t;
        return el;
    }
    
    int top() {
        // Write your code here.
        if(t == -1) return -1;
        return arr[t];
    }
    
    int isEmpty() {
        // Write your code here.
        return (t == -1);
    }
    
    int isFull() {
        // Write your code here.
        return (t+1) == size;
    }
    
};
